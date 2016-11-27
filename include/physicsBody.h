#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H 

#include <btBulletDynamicsCommon.h>
#include <memory>
#include <vector>

#include "types.h"

class PhysicsWorld;
class Sphere;
class QOpenGLShaderProgram;

class PhysicsBody
{
public:
    PhysicsBody(std::shared_ptr<PhysicsWorld> _phys, int _id);
    virtual ~PhysicsBody();

    // This draws all the physics things, mainly spheres and contrainsts when we have them
    void draw(QOpenGLShaderProgram *pShader);

    // here we pass a list of spheres to turn into the collision shapes
    void initBodyWithSpheres(std::vector<SphereData>& _spheres);

    void createConstraints();

    void setConstraintType(BodyConstraintType _type);

    BodyConstraintType getConstraintType();

private:

    // method for adding a rigid body for each sphere
    void addSphere(SphereData _sphere);

    // carries out the task of creating constraints for all the rigid bodies
    void applyConstraints();

    void addConstraint(std::shared_ptr<btRigidBody> pBody1, std::shared_ptr<btRigidBody> pBody2);

    std::shared_ptr<btTypedConstraint> getConstraint(  std::shared_ptr<btRigidBody> pBody1, 
                                                                std::shared_ptr<btRigidBody> pBody2, 
                                                                btTransform frameInA, 
                                                                btTransform frameInB);
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

    BodyConstraintType constraintType;

};

#endif // PHYSICSBODY