#include "physicsModel.h"
#include "physicsWorld.h"
#include "sphere.h"

#include <QOpenGLShaderProgram>

#include <iostream>

PhysicsModel::PhysicsModel(std::shared_ptr<PhysicsWorld> _phys)
:
    pPhysicsWorld(_phys),
    pSphere(new Sphere())
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
    pPhysicsWorld->addRigidBody(pBody.get());

    // to our list of bodies for this model
    rigid_bodies.push_back(pBody);
}

void PhysicsModel::draw(QOpenGLShaderProgram *pShader)
{   
    //iterate through all bodies
    for(auto body : rigid_bodies)
    {
        float modelMat[16];
        btTransform trans;
        body->getMotionState()->getWorldTransform(trans); 
        trans.getOpenGLMatrix(modelMat);

        QMatrix4x4 model = QMatrix4x4(modelMat).transposed();
        model.scale(2.0f, 2.0f);
        pShader->setUniformValue("model_matrix", model);

        pSphere->draw(pShader);
    }
}

