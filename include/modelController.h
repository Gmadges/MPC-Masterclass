#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <string>
#include <vector>
#include <memory>

#include "mesh.h"

class QOpenGLShaderProgram;

class ModelController 
{
public:
    ModelController();
    virtual ~ModelController();

    // draw all meshes
    void DrawAll(QOpenGLShaderProgram *pShader);

    // load mesh
    bool loadMesh(std::string _path);

    // returns pointer to mesh of index
    std::shared_ptr<Mesh> GetMesh(int index);
    
private:
    // my meshs
    std::vector<std::shared_ptr<Mesh>> m_meshes;

};

#endif // MODELCONTROLLER_H
