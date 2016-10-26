#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <memory>

class Mesh;
class QOpenGLShaderProgram; 

class Model 
{
public:
    Model(std::string _path);
    virtual ~Model();

    // draw
    void draw(QOpenGLShaderProgram *pShader);
    
private:
    // my meshs
    std::shared_ptr<Mesh> pMesh;

};

#endif // MODEL_H