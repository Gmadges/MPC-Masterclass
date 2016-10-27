#ifndef PHYSICSMODEL_H
#define PHYSICSMODEL_H 

#include <btBulletDynamicsCommon.h>

#include <memory>

class PhysicsWorld;

class PhysicsModel
{
public:
    PhysicsModel(std::shared_ptr<PhysicsWorld> _phys);
    virtual ~PhysicsModel();

    btTransform getTransformMatrix();

private:

    void init();

    //pointer to physics world for ease
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

    //RIGID body
    std::shared_ptr<btRigidBody> pRigidBody;

};

#endif // PHYSICSMODEL