#ifndef PHYSICSMODEL_H
#define PHYSICSMODEL_H 

#include <btBulletDynamicsCommon.h>

#include <memory>

class PhysicsWorld;
class Sphere;
class QOpenGLShaderProgram;

class PhysicsModel
{
public:
    PhysicsModel(std::shared_ptr<PhysicsWorld> _phys);
    virtual ~PhysicsModel();

    btTransform getTransformMatrix();

    // This draws all the physics things, mainly spheres and contrainsts when we have them
    void draw(QOpenGLShaderProgram *pShader);

private:

    void init();

    //pointer to physics world for ease
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

    //RIGID body
    std::shared_ptr<btRigidBody> pRigidBody;

    // sphere thing
    std::shared_ptr<Sphere> pSphere;

};

#endif // PHYSICSMODEL