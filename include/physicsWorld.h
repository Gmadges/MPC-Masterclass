#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H 

#include <btBulletDynamicsCommon.h>

#include <memory>

class PhysicsWorld 
{
public:
    PhysicsWorld();
    virtual ~PhysicsWorld();

    void reset(); //TODO
    void step(float _time, float _step);

private:

    std::unique_ptr<btDefaultCollisionConfiguration> m_collisionConfiguration;
    std::unique_ptr<btCollisionDispatcher> m_dispatcher;
    std::unique_ptr<btBroadphaseInterface> m_overlappingPairCache ;
    std::unique_ptr<btSequentialImpulseConstraintSolver> m_solver;
    std::unique_ptr<btDiscreteDynamicsWorld> m_dynamicsWorld;

    //the ground
    std::unique_ptr<btCollisionShape> m_groundShape;

};

#endif // PHYSICSWORLD