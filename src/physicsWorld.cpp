#include "physicsWorld.h"

#include <iostream>

PhysicsWorld::PhysicsWorld()
{
    // Jon snippet -----------------------------------------------------------------------------------------------------------------------

    ///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	m_collisionConfiguration.reset( new btDefaultCollisionConfiguration());

	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	m_dispatcher.reset(new btCollisionDispatcher(m_collisionConfiguration.get()));

	///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
	m_overlappingPairCache.reset(new btDbvtBroadphase());

	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	m_solver.reset(new btSequentialImpulseConstraintSolver());

	m_dynamicsWorld.reset(new btDiscreteDynamicsWorld(m_dispatcher.get(),
													    m_overlappingPairCache.get(),
														m_solver.get(),
														m_collisionConfiguration.get()));
    // ---------------------------------------------------------------------------------------------------------------------------------

	m_dynamicsWorld->setGravity(btVector3(0, -10, 0));

    //hardcode plane for now no need to destructor, always leave the ground plane
	btCollisionShape *groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
	btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btRigidBody::btRigidBodyConstructionInfo
	groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
	m_groundBody.reset(new btRigidBody(groundRigidBodyCI));

	// accessing raw point, soooo bad. but okay for now
	m_dynamicsWorld->addRigidBody(m_groundBody.get());
}

PhysicsWorld::~PhysicsWorld()
{
}

void PhysicsWorld::reset()
{
    // todo
	std::cout << "reset Sim \n";
}

void PhysicsWorld::step(float _time, float _step)
{
    m_dynamicsWorld->stepSimulation(_time,_step);
}

void PhysicsWorld::addRigidBody(btRigidBody* pBody)
{
	m_dynamicsWorld->addRigidBody(pBody);
}

void PhysicsWorld::removeRigidBody(btRigidBody* pBody)
{
	m_dynamicsWorld->removeRigidBody(pBody);
}
