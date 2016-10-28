#include "model.h"

#include "mesh.h"
#include "physicsModel.h"

#include <QOpenGLShaderProgram>

#include <iostream>
#include <iterator>
#include <algorithm>

//test
#include "sphere.h"

Model::Model(std::string _path, 
                std::shared_ptr<PhysicsWorld> _phys)
:
    pMesh(new Mesh(_path)),
    pPhysicsModel(new PhysicsModel(_phys)),
    pSphere(new Sphere())
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

        //testing sphere drawing
        pSphere->draw(pShader);

        //pMesh->drawMesh(pShader);
    }
}

void Model::update()
{
    // update transform
}