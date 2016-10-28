#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <memory>

class Mesh;
class PhysicsModel;
class PhysicsWorld;
class QOpenGLShaderProgram; 

//test
class Sphere;

class Model 
{
public:
    Model(std::string _path, std::shared_ptr<PhysicsWorld> _phys);
    virtual ~Model();

    // draw
    void draw(QOpenGLShaderProgram *pShader);
    void update();
    
private:
    // my meshs
    std::shared_ptr<Mesh> pMesh;
    std::shared_ptr<PhysicsModel> pPhysicsModel;

    //test
    std::shared_ptr<Sphere> pSphere;
};

#endif // MODEL_H