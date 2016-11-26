#include "physicsBody.h"
#include "physicsWorld.h"
#include "sphere.h"

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
    id(_id)
{
}

PhysicsBody::~PhysicsBody()
{
}

void PhysicsBody::initModelWithSpheres(std::vector<SphereData>& _spheres)
{
    for(auto sphere : _spheres)
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
                addFixedConstraint(body, compareBody);
                consts[i].push_back(j);
            //}
        }
    }
}

void PhysicsBody::addFixedConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2)
{
    btTransform frameInA, frameInB;
    calcFrameMatrices(pBody1, pBody2, frameInA, frameInB); 

    //lambda to clean up in pPhysicsWorld
    auto deleter = [&](btTypedConstraint* b){
        if(b)
        {
            pPhysicsWorld->removeConstraint(b);
        }
    };

    std::shared_ptr<btTypedConstraint> constraint(new btFixedConstraint(*(pBody1.get()),
                                                            *(pBody2.get()),
                                                            frameInA,
                                                            frameInB), 
                                                            deleter);

    //terrible raw pointer, but we make up for it with the ole lambda                                                         
    pPhysicsWorld->addConstraint(constraint.get());

    constraints.push_back(constraint);
}

void PhysicsBody::addSliderConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2)
{
    btTransform frameInA, frameInB;
    calcFrameMatrices(pBody1, pBody2, frameInA, frameInB); 
    
    //lambda to clean up in pPhysicsWorld
    auto deleter = [&](btTypedConstraint* b){
        if(b)
        {
            pPhysicsWorld->removeConstraint(b);
        }
    };

    std::shared_ptr<btTypedConstraint> constraint(new btSliderConstraint(*(pBody1.get()),
                                                            *(pBody2.get()),
                                                            frameInA,
                                                            frameInB,
                                                            true), 
                                                            deleter);

    //terrible raw pointer, but we make up for it with the ole lambda                                                         
    pPhysicsWorld->addConstraint(constraint.get());

    constraints.push_back(constraint);
}

void PhysicsBody::add6DoFConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2)
{
    btTransform frameInA, frameInB;
    calcFrameMatrices(pBody1, pBody2, frameInA, frameInB); 

    //lambda to clean up in pPhysicsWorld
    auto deleter = [&](btTypedConstraint* b){
        if(b)
        {
            pPhysicsWorld->removeConstraint(b);
        }
    };

    std::shared_ptr<btTypedConstraint> constraint(new btGeneric6DofConstraint(*(pBody1.get()),
                                                            *(pBody2.get()),
                                                            frameInA,
                                                            frameInB,
                                                            true), 
                                                            deleter);

    //terrible raw pointer, but we make up for it with the ole lambda                                                         
    pPhysicsWorld->addConstraint(constraint.get());

    constraints.push_back(constraint);
}