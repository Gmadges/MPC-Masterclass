#ifndef PHYSICSMODEL_H
#define PHYSICSMODEL_H 

#include <btBulletDynamicsCommon.h>
#include <memory>

#include "openVDBTools.h"

class PhysicsWorld;
class Sphere;
class QOpenGLShaderProgram;

class PhysicsModel
{
public:
    PhysicsModel(std::shared_ptr<PhysicsWorld> _phys);
    virtual ~PhysicsModel();

    // This draws all the physics things, mainly spheres and contrainsts when we have them
    void draw(QOpenGLShaderProgram *pShader);

    // here we pass a list of spheres to turn into the collision shapes
    void initModelWithSpheres(std::vector<SphereData>& _spheres);

private:

    void addSphere(SphereData _sphere);

    //pointer to physics world for ease
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

    //RIGID body
    std::vector<std::shared_ptr<btRigidBody>> rigid_bodies;

    // sphere thing
    std::shared_ptr<Sphere> pSphere;

};

#endif // PHYSICSMODEL