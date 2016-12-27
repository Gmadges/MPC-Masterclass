#include "modelController.h"

ModelController::ModelController()
{
}

ModelController::~ModelController()
{
}

void ModelController::loadModelFromFile(std::string _path, std::shared_ptr<PhysicsWorld> _phys)
{  
     models.push_back(std::make_shared<Model>(_path, _phys,  models.size()));
}

void ModelController::update()
{
    for(auto model :  models)
    {
        model->update();
    }
}

void ModelController::drawAllMesh(QOpenGLShaderProgram *pShader)
{
    for(auto model :  models)
    {
        model->drawMesh(pShader);
    }
}

void ModelController::drawAllPhysicsBody(QOpenGLShaderProgram *pShader)
{
    for(auto model :  models)
    {
        model->drawPhysicsBody(pShader);
    }
}

std::shared_ptr<Model> ModelController::getModel(int index)
{
    return  models[index];
}

void ModelController::showAllMeshes(bool show)
{
    for(auto model :  models)
    {
        model->setShowMesh(show);
    }
}

void ModelController::showAllPhysShapes(bool show)
{
    for(auto model :  models)
    {
        model->setShowPhys(show);
    }
}

void ModelController::emptyModels()
{
     models.clear();
}

void ModelController::resetModels()
{
    for(auto model :  models)
    {
        model->reset();
    }
}

int ModelController::getNumModels()
{
    return models.size();
}

void ModelController::removeModel(int id)
{
    models.erase(models.begin()+id);
}

