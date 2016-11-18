#include "model.h"

#include "mesh.h"
#include "physicsBody.h"
#include <iostream>
#include <iterator>
#include <algorithm>

#include "openVDBTools.h"

Model::Model(std::string _path, 
                std::shared_ptr<PhysicsWorld> _phys,
                int _id)
:
    pMesh(new Mesh(_path)),
    pPhysicsBody(new PhysicsBody(_phys, _id)),
    bShowMesh(true),
    bShowPhysShapes(true)
{

    //testing may just leave this here.
    std::vector<SphereData> spheres = OpenVDBTools::getSpheresForMesh(pMesh->getVerts(), pMesh->getFaces());
    pPhysicsBody->initModelWithSpheres(spheres);

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

    if(pPhysicsBody)
    {
        if(bShowPhysShapes)
        {
            pPhysicsBody->draw(pShader);
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