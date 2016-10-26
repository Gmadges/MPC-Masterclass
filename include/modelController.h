#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <string>
#include <vector>
#include <memory>

#include "model.h"

class QOpenGLShaderProgram;

class ModelController 
{
public:
    ModelController();
    virtual ~ModelController();

    // draw all meshes
    void drawAll(QOpenGLShaderProgram *pShader);

    // load mesh
    void loadModelFromFile(std::string _path);

    // returns pointer to mesh of index
    std::shared_ptr<Model> getModel(int index);
    
private:
    // my models
    std::vector<std::shared_ptr<Model>> m_models;

};

#endif // MODELCONTROLLER_H
