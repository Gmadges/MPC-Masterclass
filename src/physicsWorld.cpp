#include "physicsWorld.h"

#include <iostream>

PhysicsWorld::PhysicsWorld()
:
bUseCollisionMasks(false)
{
    // Jon snippet -----------------------------------------------------------------------------------------------------------------------

    ///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
	 collisionConfiguration.reset( new btDefaultCollisionConfiguration());

	///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
	 dispatcher.reset(new btCollisionDispatcher( collisionConfiguration.get()));

	///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
	 overlappingPairCache.reset(new btDbvtBroadphase());

	///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
	 solver.reset(new btSequentialImpulseConstraintSolver());

	 dynamicsWorld.reset(new btDiscreteDynamicsWorld( dispatcher.get(),
													     overlappingPairCache.get(),
														 solver.get(),
														 collisionConfiguration.get()));
    // ---------------------------------------------------------------------------------------------------------------------------------

	 dynamicsWorld->setGravity(btVector3(0, -10, 0));

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
     dynamicsWorld->stepSimulation(_time,_step);
}

void PhysicsWorld::addRigidBody(btRigidBody* pBody, int idx)
{
	if(bUseCollisionMasks)
	{
		auto values = getMaskValues(idx);

		 dynamicsWorld->addRigidBody(pBody, values.first, values.second);
	}
	else
	{
		 dynamicsWorld->addRigidBody(pBody);
	}
}

void PhysicsWorld::addConstraint(btTypedConstraint* pConst)
{
	 dynamicsWorld->addConstraint(pConst);
}

void PhysicsWorld::removeRigidBody(btRigidBody* pBody)
{
	 dynamicsWorld->removeRigidBody(pBody);
}

void PhysicsWorld::addGroundPlane()
{
	//hardcode plane for now no need to destructor, always leave the ground plane
	btCollisionShape *groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), 1);
	btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, -1, 0)));
	btRigidBody::btRigidBodyConstructionInfo
	groundRigidBodyCI(0, groundMotionState, groundShape, btVector3(0, 0, 0));
	 groundBody.reset(new btRigidBody(groundRigidBodyCI));

	// accessing raw point, soooo bad. but okay for 
	
	if(bUseCollisionMasks)
	{	
		 dynamicsWorld->addRigidBody( groundBody.get(), 2, 0);
	}
	else
	{
		 dynamicsWorld->addRigidBody( groundBody.get());
	}
}

void PhysicsWorld::SetMaskAmount(int amount)
{	
	 maskNum = amount;	
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

	for(int i = 0; i <  maskNum; i++)
	{
		if(i == idx) continue;

		mask += pow(2, i + 2);
	}

	return std::make_pair(ID, mask);
}
