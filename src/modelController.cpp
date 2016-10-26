#include "modelController.h"

ModelController::ModelController()
{
}

ModelController::~ModelController()
{
}

void ModelController::loadModelFromFile(std::string _path)
{  
    m_models.push_back(std::make_shared<Model>(_path));
}

void ModelController::drawAll(QOpenGLShaderProgram *pShader)
{
    if(m_models.size() != 0)
    {
        for(auto model : m_models)
        {
            model->draw(pShader);
        }
    }
}

std::shared_ptr<Model> ModelController::getModel(int index)
{
    return m_models[index];
}

