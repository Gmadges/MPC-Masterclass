#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <memory>

#include "physicsBody.h"

class Mesh;
class PhysicsWorld;
class QOpenGLShaderProgram; 

class Model 
{
public:
    Model(std::string _path, std::shared_ptr<PhysicsWorld> _phys, int _id);
    virtual ~Model();

    // draw
    void draw(QOpenGLShaderProgram *pShader);
    void update();

    void setShowMesh(bool show);
    void setShowPhys(bool show);

    void reset();

    void createConstraints(BodyConstraintType _type);
    
private:
    // my meshs
    std::shared_ptr<Mesh> pMesh;
    std::shared_ptr<PhysicsBody> pPhysicsBody;
    std::shared_ptr<PhysicsWorld> pPhysWorld;

    bool bShowMesh;
    bool bShowPhysShapes;

    int id;
};

#endif // MODEL_H