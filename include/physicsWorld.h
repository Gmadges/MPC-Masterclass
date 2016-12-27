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
    void step(float _time);

    void setSteps(int _step);

    void addRigidBody(btRigidBody* pBody, int idx);
    void removeRigidBody(btRigidBody* pBody);

    void addConstraint(btTypedConstraint* pConst);
    void removeConstraint(btTypedConstraint* pConst);
    
    // This method is a strange one
    // we need to know masks prior to adding rigid bodies(no more than 15)
    // reload models after we have set these values.
    void setMaskAmount(int amount);
    void setUseCollisionMasks(bool use);
    bool isUsingCollisionMask();

private:

    void addGroundPlane();

    // returns category and mask for rigid body, given its index
    std::pair<unsigned short int, unsigned short int> getMaskValues(int idx);

private:

    std::unique_ptr<btDefaultCollisionConfiguration> collisionConfiguration;
    std::unique_ptr<btCollisionDispatcher> dispatcher;
    std::unique_ptr<btBroadphaseInterface> overlappingPairCache ;
    std::unique_ptr<btSequentialImpulseConstraintSolver> solver;
    std::unique_ptr<btDiscreteDynamicsWorld> dynamicsWorld;

    //the ground
    std::unique_ptr<btRigidBody> groundBody;

    bool bUseCollisionMasks;
    int  maskNum;
    int steps;
};

#endif // PHYSICSWORLD