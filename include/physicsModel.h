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
    PhysicsModel(std::shared_ptr<PhysicsWorld> _phys, int _id);
    virtual ~PhysicsModel();

    // This draws all the physics things, mainly spheres and contrainsts when we have them
    void draw(QOpenGLShaderProgram *pShader);

    // here we pass a list of spheres to turn into the collision shapes
    void initModelWithSpheres(std::vector<SphereData>& _spheres);

private:

    void addSphere(SphereData _sphere);

    void applyConstraints();

    void addConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2);

    btVector3 getPositionForBody(std::shared_ptr<btRigidBody> pBody);

private:

    //pointer to physics world for ease
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

    //store pointers to rigid body, and radius. because it sucks trying to retrive it
    std::vector<std::pair<std::shared_ptr<btRigidBody>, float>> rigid_bodies;

    std::vector<btPoint2PointConstraint*> constraints;

    // sphere thing
    std::shared_ptr<Sphere> pSphere;

    // ID
    int m_id;

};

#endif // PHYSICSMODEL