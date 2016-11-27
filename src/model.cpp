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
    pPhysWorld(_phys),
    bShowMesh(true),
    bShowPhysShapes(true),
    id(_id)
{

    //initiate physics straight away
    std::vector<SphereData> spheres = OpenVDBTools::getSpheresForMesh(pMesh->getVerts(), pMesh->getFaces());
    pPhysicsBody->initBodyWithSpheres(spheres);
}

Model::~Model()
{
}

void Model::reset()
{
    // destroy and create a new physics body.
    // TODO make the holding of constraint type
    BodyConstraintType type = pPhysicsBody->getConstraintType();
    pPhysicsBody.reset(new PhysicsBody(pPhysWorld, id));
    pPhysicsBody->setConstraintType(type);

    // reload spheres
    std::vector<SphereData> spheres = OpenVDBTools::getSpheresForMesh(pMesh->getVerts(), pMesh->getFaces());
    pPhysicsBody->initBodyWithSpheres(spheres);
}

void Model::draw(QOpenGLShaderProgram *pShader)
{
    if(pMesh)
    {   
        if(bShowMesh)
        {
            // model position
            // Put this here because we'll probably need to change these values at some point here
            QMatrix4x4 model;
            model.setToIdentity();
            pShader->setUniformValue("model_matrix", model);

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

void Model::createConstraints()
{
    pPhysicsBody->createConstraints();
}

void Model::setConstraintType(BodyConstraintType _type)
{
    pPhysicsBody->setConstraintType(_type);
}