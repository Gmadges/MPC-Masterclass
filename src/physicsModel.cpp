#include "physicsModel.h"
#include "physicsWorld.h"
#include "sphere.h"

#include <QOpenGLShaderProgram>

#include <iostream>

PhysicsModel::PhysicsModel(std::shared_ptr<PhysicsWorld> _phys, int _id)
:
    pPhysicsWorld(_phys),
    pSphere(new Sphere()),
    m_id(_id)
{
}

PhysicsModel::~PhysicsModel()
{
}

void PhysicsModel::initModelWithSpheres(std::vector<SphereData>& _spheres)
{
    for(auto sphere : _spheres)
    {
        addSphere(sphere);
    }

    applyConstraints();
}

void PhysicsModel::addSphere(SphereData _sphere)
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
    pPhysicsWorld->addRigidBody(pBody.get(), m_id);

    // add to our list of bodies for this model
    rigid_bodies.emplace_back(pBody, _sphere.radius);
}

void PhysicsModel::draw(QOpenGLShaderProgram *pShader)
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

void PhysicsModel::applyConstraints()
{   

    // really basic method that just applies constaints to all spheres from all others
    for(unsigned int i = 0; i < rigid_bodies.size(); i++)
    {   

        for(unsigned int j = 0; j < rigid_bodies.size(); j++)
        {   
            if(j < i) continue;

            auto rigid1 = rigid_bodies[i].first;
            auto rigid2 = rigid_bodies[j].first;

            // get positions
            btTransform trans1;
            rigid1->getMotionState()->getWorldTransform(trans1);
            const btVector3 rigid1Pos = trans1.getOrigin();

            btTransform trans2;
            rigid2->getMotionState()->getWorldTransform(trans2);
            const btVector3 rigid2Pos = trans2.getOrigin();

            btPoint2PointConstraint *constraint = new btPoint2PointConstraint(*(rigid1.get()),
                                                                                *(rigid2.get()),
                                                                                rigid1Pos,
                                                                                rigid2Pos);

            pPhysicsWorld->addConstraint(constraint);

            constraints.push_back(constraint);
        }
    }
}

