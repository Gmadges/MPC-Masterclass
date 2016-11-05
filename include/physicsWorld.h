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

    void addRigidBody(btRigidBody* pBody);
    void removeRigidBody(btRigidBody* pBody);

    // This method is a strange one
    // we need to know masks prior to adding rigid bodies(no more than 15)
    // reload models after we have set these values.
    void CalcCollisionMasks(int num);
    void setUseCollisionMasks(bool use);

private:

    void addGroundPlane();

private:

    std::unique_ptr<btDefaultCollisionConfiguration> m_collisionConfiguration;
    std::unique_ptr<btCollisionDispatcher> m_dispatcher;
    std::unique_ptr<btBroadphaseInterface> m_overlappingPairCache ;
    std::unique_ptr<btSequentialImpulseConstraintSolver> m_solver;
    std::unique_ptr<btDiscreteDynamicsWorld> m_dynamicsWorld;

    //the ground
    std::unique_ptr<btRigidBody> m_groundBody;

    bool bUseCollisionMasks;
};

#endif // PHYSICSWORLD