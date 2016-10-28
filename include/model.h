#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <memory>

class Mesh;
class PhysicsModel;
class PhysicsWorld;
class QOpenGLShaderProgram; 

class Model 
{
public:
    Model(std::string _path, std::shared_ptr<PhysicsWorld> _phys);
    virtual ~Model();

    // draw
    void draw(QOpenGLShaderProgram *pShader);
    void update();

    void setShowMesh(bool show);
    void setShowPhys(bool show);
    
private:
    // my meshs
    std::shared_ptr<Mesh> pMesh;
    std::shared_ptr<PhysicsModel> pPhysicsModel;

    bool bShowMesh;
    bool bShowPhysShapes;
};

#endif // MODEL_H