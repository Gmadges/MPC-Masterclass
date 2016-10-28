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

    // This draws all the physics things, mainly spheres and contrainsts when we have them
    void debugDraw();

private:

    void init();

    //pointer to physics world for ease
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

    //RIGID body
    std::shared_ptr<btRigidBody> pRigidBody;

};

#endif // PHYSICSMODEL