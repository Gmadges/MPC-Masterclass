#include "model.h"

#include "mesh.h"

Model::Model(std::string _path) :
    pMesh(new Mesh(_path))
{

}

Model::~Model()
{
}

void Model::draw(QOpenGLShaderProgram *pShader)
{
    if(pMesh)
    {
        pMesh->drawMesh(pShader);
    }
}