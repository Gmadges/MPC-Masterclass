#include "physicsModel.h"
#include "physicsWorld.h"

PhysicsModel::PhysicsModel(std::shared_ptr<PhysicsWorld> _phys)
:
    pPhysicsWorld(_phys)
{
    init();
}

PhysicsModel::~PhysicsModel()
{
}

void PhysicsModel::init()
{
    //hardcode alot for now for testing
    btCollisionShape* colShape = new btSphereShape(1.0f);
    btDefaultMotionState* fallMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 10, 0)));
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

    pRigidBody.reset(new btRigidBody(fallRigidBodyCI), deleter);

    // no velocity
    pRigidBody->setActivationState(DISABLE_DEACTIVATION);

    // rigid body created so now we add to physics world
    pPhysicsWorld->addRigidBody(pRigidBody.get());
}

btTransform PhysicsModel::getTransformMatrix()
{
    btTransform trans;

    if (pRigidBody && pRigidBody->getMotionState())
	{
		pRigidBody->getMotionState()->getWorldTransform(trans);
	}

    return trans;
}

