#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H 

#include <btBulletDynamicsCommon.h>
#include <QVector3D>
#include <memory>
#include <vector>

#include "types.h"

class PhysicsWorld;
class Sphere;
class Line;
class QOpenGLShaderProgram;

class PhysicsBody
{
public:
    PhysicsBody(std::shared_ptr<PhysicsWorld> _phys, int _id);
    virtual ~PhysicsBody();

    // This draws all the physics things, mainly spheres and contrainsts when we have them
    void drawSpheres(QOpenGLShaderProgram *pShader);
    void drawConstraints(QOpenGLShaderProgram *pShader);

    // update method.
    void update();

    // here we pass a list of spheres to turn into the collision shapes
    void initBodyWithSpheres(std::vector<QVector3D>& verts, std::vector<unsigned int>& indices);

    void createConstraints();

// setters
    void setConstraintType(BodyConstraintType _type);
    void setConstraintSettings(ConstraintSettings settings);
    void setMaxSphereCount(int num);
    void setMinSphereSize(float size);
    void setMaxSphereSize(float size);
    void setSphereOverlap(bool enable);
    void setPlasticDeformation(bool _deform);
    void setMaxPlasticForce(double _value);
    void setMinPlasticForce(double _value);
// getters
    BodyConstraintType getConstraintType();
    ConstraintSettings getConstraintSettings();
    int getMaxSphereCount();
    float getMinSphereSize();
    float getMaxSphereSize();
    bool getSphereOverlap();
    std::vector<std::pair<std::shared_ptr<btRigidBody>, float>> getRigidBodies();
    bool getPlasticDeformation();
    double getMaxPlasticForce();
    double getMinPlasticForce();

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

    // handy functions
    btVector3 getPositionForBody(std::shared_ptr<btRigidBody> pBody);
    void calcFrameMatrices(std::shared_ptr<btRigidBody> pBodyA, 
                            std::shared_ptr<btRigidBody> pBodyB, 
                            btTransform& frameInA, 
                            btTransform& frameInB);

    void updatePlasticDeformation();

private:

    //pointer to physics world for ease
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

    //store pointers to rigid body, and radius. because it sucks trying to retrive it
    std::vector<std::pair<std::shared_ptr<btRigidBody>, float>> rigid_bodies;

    std::vector<std::shared_ptr<btTypedConstraint>> constraints;

    // sphere thing
    std::shared_ptr<Sphere> pSphere;

    //line thing
    std::shared_ptr<Line> pLine;

    // ID
    int  id;

    BodyConstraintType constraintType;

    int maxSphereCount;
    float minSphereSize;
    float maxSphereSize;
    bool bSphereOverlap;

    ConstraintSettings constraintSettings;

    bool bPlasticDeform;
    double maxForceThreshold;
    double minForceThreshold;
};

#endif // PHYSICSBODY