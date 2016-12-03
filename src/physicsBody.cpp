#include "physicsBody.h"
#include "physicsWorld.h"
#include "sphere.h"
#include "openVDBTools.h"

#include <QOpenGLShaderProgram>

#include <iostream>

//Handy methods ///////////////////////////
btVector3 getPositionForBody(std::shared_ptr<btRigidBody> pBody)
{
    btTransform trans1;
    pBody->getMotionState()->getWorldTransform(trans1);
    return trans1.getOrigin();
}

void calcFrameMatrices(std::shared_ptr<btRigidBody> pBodyA, std::shared_ptr<btRigidBody> pBodyB, btTransform& frameInA, btTransform& frameInB)
{
    // get positions
    btVector3 rigid1Pos = getPositionForBody(pBodyA);

    frameInA.setIdentity();
    frameInB.setIdentity();
    
    frameInA.setOrigin( rigid1Pos );

    btTransform inv = pBodyB->getCenterOfMassTransform().inverse();

    btTransform globalFrameA = pBodyA->getCenterOfMassTransform() * frameInA;

    frameInB = inv  * globalFrameA;
}

//////////class
PhysicsBody::PhysicsBody(std::shared_ptr<PhysicsWorld> _phys, int _id)
:
    pPhysicsWorld(_phys),
    pSphere(new Sphere()),
    id(_id),
    constraintType(BodyConstraintType::FIXED),
    maxSphereCount(1000),
    minSphereSize(1.0f),
    maxSphereSize(100000.0f),
    bSphereOverlap(true)
{
}

PhysicsBody::~PhysicsBody()
{
}

void PhysicsBody::initBodyWithSpheres(std::vector<QVector3D>& verts, std::vector<unsigned int>& indices)
{
    // get spheres
    std::vector<SphereData> spheres = OpenVDBTools::getSpheresForMesh(verts, indices, maxSphereCount, bSphereOverlap, minSphereSize, maxSphereSize);

    for(auto sphere : spheres)
    {
        addSphere(sphere);
    }

    applyConstraints();
}

void PhysicsBody::addSphere(SphereData _sphere)
{
    //hardcode alot for now for testing
    btCollisionShape* colShape = new btSphereShape(_sphere.radius);
    btDefaultMotionState* fallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(_sphere.x, _sphere.y, _sphere.z)));
    btScalar mass = 1;
    btVector3 fallInertia(0, 0, 0);
    colShape->calculateLocalInertia(mass, fallInertia);
    btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, colShape, fallInertia);

    // make the rigid body
    //custom deleter to remove it from the physics world if we should delete it here
    auto deleter = [&](btRigidBody* b){
        if(b)
        {
            pPhysicsWorld->removeRigidBody(b);
        }
    };

    std::shared_ptr<btRigidBody> pBody(new btRigidBody(fallRigidBodyCI), deleter); 

    // no velocity
    pBody->setActivationState(DISABLE_DEACTIVATION);

    // rigid body created so now we add to physics world
    pPhysicsWorld->addRigidBody(pBody.get(),  id);

    // add to our list of bodies for this model
    rigid_bodies.emplace_back(pBody, _sphere.radius);
}

void PhysicsBody::draw(QOpenGLShaderProgram *pShader)
{   
    //iterate through all bodies
    for(auto body : rigid_bodies)
    {
        float modelMat[16];
        btTransform trans;
        body.first->getMotionState()->getWorldTransform(trans);
        trans.getOpenGLMatrix(modelMat);

        QMatrix4x4 model;
        model.setToIdentity();
        model *= QMatrix4x4(modelMat).transposed();
        model.scale(body.second*2.0f, body.second*2.0f, body.second*2.0f);
        
        pShader->setUniformValue("model_matrix", model);

        pSphere->draw(pShader);
    }
}

void PhysicsBody::createConstraints()
{   
    // if we have no rigid bodies do nothing
    if(rigid_bodies.empty()) return;

    // if we have constraints get rid of them
    if(!constraints.empty())
    {
        constraints.clear();
    }

    applyConstraints();
}

void PhysicsBody::applyConstraints()
{   
    //store containts we've made'
    std::vector<std::vector<unsigned int>> consts(rigid_bodies.size());

    float lookFactor = 1.25f;

    // really basic method that just applies constaints to all spheres from all others
    for(unsigned int i = 0; i < rigid_bodies.size(); i++)
    {   
        // get position and radius around 
        auto body = rigid_bodies[i].first;
        float bodyRadius = rigid_bodies[i].second * lookFactor;
        btVector3 bodyPos = getPositionForBody(body);

        for(unsigned int j = 0; j < rigid_bodies.size(); j++)
        {   
            //check their not already linked
            bool bNext = false;
            for(unsigned int bod : consts[j])
            {
                if(bod == i)
                {
                    bNext = true;
                    break;
                }
            }
            if(bNext) break;

            auto compareBody = rigid_bodies[j].first;
            btVector3 comparePos = getPositionForBody(compareBody);

            //check if their near each other
            //float dist = bodyPos.dot(comparePos);
            //if(abs(dist) <= bodyRadius)
            //{
                addConstraint(body, compareBody);
                consts[i].push_back(j);
            //}
        }
    }
}

void PhysicsBody::addConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2)
{
    btTransform frameInA, frameInB;
    calcFrameMatrices(pBody1, pBody2, frameInA, frameInB); 

    std::shared_ptr<btTypedConstraint> constraint = getConstraint(pBody1, pBody2, frameInA, frameInB);

    //terrible raw pointer, but we make up for it with the ole lambda                                                         
    pPhysicsWorld->addConstraint(constraint.get());

    constraints.push_back(constraint);
}

std::shared_ptr<btTypedConstraint> PhysicsBody::getConstraint(  std::shared_ptr<btRigidBody> pBody1, 
                                                                std::shared_ptr<btRigidBody> pBody2, 
                                                                btTransform frameInA, 
                                                                btTransform frameInB)
{
    //lambda to clean up in pPhysicsWorld
    auto deleter = [&](btTypedConstraint* b){
        if(b)
        {
            pPhysicsWorld->removeConstraint(b);
        }
    };

    switch(constraintType)
    {
        case BodyConstraintType::FIXED :
        {
            return std::shared_ptr<btFixedConstraint>(new btFixedConstraint(*(pBody1.get()),
                                                            *(pBody2.get()),
                                                            frameInA,
                                                            frameInB), 
                                                            deleter);
        }
        case BodyConstraintType::SLIDER :
        {
            return std::shared_ptr<btSliderConstraint>(new btSliderConstraint(*(pBody1.get()),
                                                                                *(pBody2.get()),
                                                                                frameInA,
                                                                                frameInB,
                                                                                true), 
                                                                                deleter);
        }
        case BodyConstraintType::SPRING :
        {

            std::shared_ptr<btGeneric6DofSpring2Constraint> constraint(new btGeneric6DofSpring2Constraint(*(pBody1.get()),
                                                                                            *(pBody2.get()),
                                                                                            frameInA,
                                                                                            frameInB), 
                                                                                            deleter);
            // just linear for now no angular
            constraint->setLinearLowerLimit(btVector3(-50, -50, -50));
            constraint->setLinearUpperLimit(btVector3(50, 50, 50));
			
			constraint->enableSpring(0, true);
            constraint->setStiffness(0, 100, true);
			constraint->setDamping(0, 100, true);

			constraint->enableSpring(1, true);
            constraint->setStiffness(1, 100, true);
			constraint->setDamping(1, 100, true);

			constraint->enableSpring(2, true);
            constraint->setStiffness(2, 100, true);
			constraint->setDamping(2, 100, true);

            constraint->setEquilibriumPoint();
            
            return constraint;
        }
        default :
        {
            //return fixed if nothing else
            return std::shared_ptr<btFixedConstraint>(new btFixedConstraint(*(pBody1.get()),
                                                                            *(pBody2.get()),
                                                                            frameInA,
                                                                            frameInB), 
                                                                            deleter);
        }
    }
}

void PhysicsBody::setConstraintType(BodyConstraintType _type)
{
    constraintType = _type;
}

BodyConstraintType PhysicsBody::getConstraintType()
{
    return constraintType;
}

void PhysicsBody::setMaxSphereCount(int count)
{
    maxSphereCount = count;
}

void PhysicsBody::setMinSphereSize(float size)
{
    minSphereSize = size;
}

void PhysicsBody::setMaxSphereSize(float size)
{
    maxSphereSize = size;
}

void PhysicsBody::setSphereOverlap(bool enable)
{
    bSphereOverlap = enable;
}

int PhysicsBody::getMaxSphereCount()
{
    return maxSphereCount;
}

float PhysicsBody::getMinSphereSize()
{
    return minSphereSize;
}

float PhysicsBody::getMaxSphereSize()
{
    return maxSphereSize;
}

bool PhysicsBody::getSphereOverlap()
{
    return bSphereOverlap;
}
