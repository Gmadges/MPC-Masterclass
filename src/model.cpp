#include "model.h"

#include "mesh.h"
#include "physicsModel.h"
#include <iostream>
#include <iterator>
#include <algorithm>

#include "openVDBTools.h"

Model::Model(std::string _path, 
                std::shared_ptr<PhysicsWorld> _phys)
:
    pMesh(new Mesh(_path)),
    pPhysicsModel(new PhysicsModel(_phys)),
    bShowMesh(true),
    bShowPhysShapes(true)
{

    //testing

    OpenVDBTools::getSpheresForMesh(pMesh->getVerts(), pMesh->getFaces());

}

Model::~Model()
{
}

void Model::draw(QOpenGLShaderProgram *pShader)
{
    if(pMesh)
    {   
        if(bShowMesh)
        {
            pMesh->drawMesh(pShader);
        }
    }

    if(pPhysicsModel)
    {
        if(bShowPhysShapes)
        {
            pPhysicsModel->draw(pShader);
        }
    }
}

void Model::update()
{
    // update transform
}

void Model::setShowMesh(bool show)
{
    bShowMesh = show;
}

void Model::setShowPhys(bool show)
{
    bShowPhysShapes = show;
}