#include "modelController.h"

ModelController::ModelController()
{
}

ModelController::~ModelController()
{
}

bool ModelController::loadMesh(std::string _path)
{  
    m_meshes.push_back(std::make_shared<Mesh>(_path));
}

void ModelController::DrawAll(QOpenGLShaderProgram *pShader)
{
    if(m_meshes.size() != 0)
    {
        for(auto mesh : m_meshes)
        {
            mesh->drawMesh(pShader);
        }
    }
}

std::shared_ptr<Mesh> ModelController::GetMesh(int index)
{
    return m_meshes[index];
}

