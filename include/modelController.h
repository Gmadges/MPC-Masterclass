#ifndef MODELCONTROLLER_H
#define MODELCONTROLLER_H

#include <string>
#include <vector>
#include <memory>

#include "model.h"

class QOpenGLShaderProgram;
class PhysicsWorld;

class ModelController 
{
public:
    ModelController();
    virtual ~ModelController();

    // draw all meshes
    void drawAll(QOpenGLShaderProgram *pShader);

    // load mesh
    void loadModelFromFile(std::string _path, std::shared_ptr<PhysicsWorld> _phys);

    // returns pointer to mesh of index
    std::shared_ptr<Model> getModel(int index);

    void showAllMeshes(bool show);
    void showAllPhysShapes(bool show);
    void emptyModels();
    void resetModels();
    
private:
    // my models
    std::vector<std::shared_ptr<Model>> models;

};

#endif // MODELCONTROLLER_H