#include "model.h"

#include "mesh.h"
#include "physicsModel.h"

#include <QOpenGLShaderProgram>

#include <iostream>
#include <iterator>
#include <algorithm>

Model::Model(std::string _path, 
                std::shared_ptr<PhysicsWorld> _phys)
:
    pMesh(new Mesh(_path)),
    pPhysicsModel(new PhysicsModel(_phys))
{

}

Model::~Model()
{
}

void Model::draw(QOpenGLShaderProgram *pShader)
{
    if(pMesh)
    {   
        if(pPhysicsModel)
        {
            float modelMat[16];
            pPhysicsModel->getTransformMatrix().getOpenGLMatrix(modelMat);
            pShader->setUniformValue("model_matrix", QMatrix4x4(modelMat).transposed());
        }

        pMesh->drawMesh(pShader);
    }
}

void Model::update()
{
    // update transform
}