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

    //hardcode plane for now

    m_groundShape.reset(new btStaticPlaneShape(btVector3(0,1,0), 0.0f));

	btTransform groundTransform;
	groundTransform.setIdentity();
	{
		btScalar mass(0.0f);
		btVector3 localInertia(0,0,0);
		//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass,myMotionState,m_groundShape.get(),localInertia);
		rbInfo.m_rollingFriction=1.0f;
		btRigidBody* body = new btRigidBody(rbInfo);
		//add the body to the dynamics world
		m_dynamicsWorld->addRigidBody(body);
	}
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
	std::cout << "step " << _time << "ms \n";
    m_dynamicsWorld->stepSimulation(_time,_step);
}

void PhysicsWorld::addRigidBody(btRigidBody* pBody)
{
	std::cout << "Adding Rigid Body \n";
	m_dynamicsWorld->addRigidBody(pBody);
}

void PhysicsWorld::removeRigidBody(btRigidBody* pBody)
{
	std::cout << "removing rigid body \n";
	m_dynamicsWorld->removeRigidBody(pBody);
}
