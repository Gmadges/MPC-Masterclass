#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H 

#include <btBulletDynamicsCommon.h>
#include <memory>

#include "openVDBTools.h"

class PhysicsWorld;
class Sphere;
class QOpenGLShaderProgram;

enum BodyConstraintType {
    FIXED,
    SLIDER,
    SIX_DOF
};

class PhysicsBody
{
public:
    PhysicsBody(std::shared_ptr<PhysicsWorld> _phys, int _id);
    virtual ~PhysicsBody();

    // This draws all the physics things, mainly spheres and contrainsts when we have them
    void draw(QOpenGLShaderProgram *pShader);

    // here we pass a list of spheres to turn into the collision shapes
    void initBodyWithSpheres(std::vector<SphereData>& _spheres, BodyConstraintType _type = BodyConstraintType::FIXED);

    void createConstraints(BodyConstraintType _type);

private:

    // method for adding a rigid body for each sphere
    void addSphere(SphereData _sphere);

    // carries out the task of creating constraints for all the rigid bodies
    void applyConstraints(BodyConstraintType _type);

    void addFixedConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2);
    void addSliderConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2);
    void add6DoFConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2);

private:

    //pointer to physics world for ease
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

    //store pointers to rigid body, and radius. because it sucks trying to retrive it
    std::vector<std::pair<std::shared_ptr<btRigidBody>, float>> rigid_bodies;

    std::vector<std::shared_ptr<btTypedConstraint>> constraints;

    // sphere thing
    std::shared_ptr<Sphere> pSphere;

    // ID
    int  id;

};

#endif // PHYSICSBODY