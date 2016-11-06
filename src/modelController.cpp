#include "modelController.h"

ModelController::ModelController()
{
}

ModelController::~ModelController()
{
}

void ModelController::loadModelFromFile(std::string _path, std::shared_ptr<PhysicsWorld> _phys)
{  
    m_models.push_back(std::make_shared<Model>(_path, _phys, m_models.size()+1));
}

void ModelController::drawAll(QOpenGLShaderProgram *pShader)
{
    for(auto model : m_models)
    {
        model->draw(pShader);
    }
}

std::shared_ptr<Model> ModelController::getModel(int index)
{
    return m_models[index];
}

void ModelController::showAllMeshes(bool show)
{
    for(auto model : m_models)
    {
        model->setShowMesh(show);
    }
}

void ModelController::showAllPhysShapes(bool show)
{
    for(auto model : m_models)
    {
        model->setShowPhys(show);
    }
}

void ModelController::emptyModels()
{
    m_models.clear();
}

