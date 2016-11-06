#include "physicsWorld.h"

#include <iostream>

PhysicsWorld::PhysicsWorld()
:
bUseCollisionMasks(false)
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

	addGroundPlane();
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

void PhysicsWorld::addRigidBody(btRigidBody* pBody, int idx)
{
	if(bUseCollisionMasks)
	{
		auto values = getMaskValues(idx);

		m_dynamicsWorld->addRigidBody(pBody, values.first, values.second);
	}
	else
	{
		m_dynamicsWorld->addRigidBody(pBody);
	}
}

void PhysicsWorld::removeRigidBody(btRigidBody* pBody)
{
	m_dynamicsWorld->removeRigidBody(pBody);
}

void PhysicsWorld::addGroundPlane()
{
	//hardcode plane for now no need to destructor, always leave the ground plane
	btCollisionShape *groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
	btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btRigidBody::btRigidBodyConstructionInfo
	groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
	m_groundBody.reset(new btRigidBody(groundRigidBodyCI));

	// accessing raw point, soooo bad. but okay for 
	
	if(bUseCollisionMasks)
	{	
		m_dynamicsWorld->addRigidBody(m_groundBody.get(), 2, 0);
	}
	else
	{
		m_dynamicsWorld->addRigidBody(m_groundBody.get());
	}
}

void PhysicsWorld::SetMaskAmount(int amount)
{	
	m_maskNum = amount;	
}

void PhysicsWorld::setUseCollisionMasks(bool use)
{
	bUseCollisionMasks = use;
}

std::pair<unsigned short int, unsigned short int> PhysicsWorld::getMaskValues(int idx)
{
	unsigned short int ID = 0; 

	// mask is set to 2 as default because everything will collide with the ground and that is 2.
	unsigned short int mask = 2;

	//Okay, I'm not crazy, we add 2 because we dont want 0 and the ground shape is 1;
	int val = idx + 2;

	ID = pow(2, val);

	for(int i = 0; i < m_maskNum; i++)
	{
		if(i == idx) continue;

		mask += pow(2, i + 2);
	}

	return std::make_pair(ID, mask);
}
