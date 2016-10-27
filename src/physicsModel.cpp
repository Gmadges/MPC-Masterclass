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

    // /// Create Dynamic Objects
    // btTransform startTransform;
    // startTransform.setIdentity();

    // btScalar mass(1.0f);

    // startTransform.setOrigin(btVector3(0.0f, 10.0f, 0.0f));
    // btVector3 localInertia(0.0f, 0.0f, 0.0f);
    // colShape->calculateLocalInertia(mass,localInertia);

    // //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
    // btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
    // btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,colShape,localInertia);
    // rbInfo.m_restitution = 0.2f;
    // rbInfo.m_friction = 0.5f;
    // rbInfo.m_additionalAngularDampingFactor=0.0;
    // rbInfo.m_additionalDamping=true;

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
    //pRigidBody.reset(new btRigidBody(rbInfo), deleter);

    // no velocity
    //pRigidBody->setLinearVelocity(btVector3(0.0f, 1.0f, 0.0f));
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

