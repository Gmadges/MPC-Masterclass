#include "model.h"

#include "mesh.h"
#include "physicsBody.h"
#include "types.h"
#include <iostream>
#include <iterator>
#include <algorithm>

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
    //pPhysicsBody->initBodyWithSpheres(pMesh->getVerts(), pMesh->getFaces());
}

Model::~Model()
{
}

void Model::reset()
{
    // destroy and create a new physics body.
    // TODO create a more elegant solution;
    BodyConstraintType type = pPhysicsBody->getConstraintType();
    ConstraintSettings constSettings = pPhysicsBody->getConstraintSettings();
    float maxSize = pPhysicsBody->getMaxSphereSize();
    float minSize = pPhysicsBody->getMinSphereSize();
    int maxCount = pPhysicsBody->getMaxSphereCount();
    bool bOverlap = pPhysicsBody->getSphereOverlap();

    pPhysicsBody.reset(new PhysicsBody(pPhysWorld, id));

    pPhysicsBody->setConstraintType(type);
    pPhysicsBody->setConstraintSettings(constSettings);
    pPhysicsBody->setMaxSphereSize(maxSize);
    pPhysicsBody->setMinSphereSize(minSize);
    pPhysicsBody->setMaxSphereCount(maxCount);
    pPhysicsBody->setSphereOverlap(bOverlap);

    // reload spheres
    pPhysicsBody->initBodyWithSpheres(pMesh->getVerts(), pMesh->getFaces());
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

void Model::setMaxSphereCount(int num)
{
    pPhysicsBody->setMaxSphereCount(num);
}

void Model::setMinSphereSize(float size)
{
    pPhysicsBody->setMinSphereSize(size);
}

void Model::setMaxSphereSize(float size)
{
    pPhysicsBody->setMaxSphereSize(size);
}

void Model::setSphereOverlap(bool enable)
{
    pPhysicsBody->setSphereOverlap(enable);
}

void Model::setConstraintSettings(ConstraintSettings settings)
{
    pPhysicsBody->setConstraintSettings(settings);
}

void Model::WeightMeshFromPhysicsBody()
{
    //TODO

    //Get mesh verts
    auto verts = pMesh->getVerts();

    //Get spheres
    auto spheres = pPhysicsBody->getRigidBodies();

    //vector of weights and ids
    std::vector<SkinWeights> weightsArray;
    std::vector<SkinIDs> idsArray;

    //HARD CODED weight radius for now
    float weightRadius = 2.0f;

    // Iterate through verts and find nearest spheres based on weighting value
    // alot of brute force searching
    for(auto vert : verts)
    {
        // array to store our current sphere info for later calculations;
        std::pair<std::shared_ptr<btRigidBody>, float> currentSpheres[MAX_WEIGHTS];

        // throught the spheres we go
        for(auto sphere : spheres)
        {
            // find the 4(hardcoded) nearest spheres
            // I do this instead of intersections because for verts that are distant from spheres it would be easier 
            // to keep and delete than look again. 

             
        }

        SkinWeights weights;
        SkinIDs ids;

        // Figure out weighting by comparing the volume intersection of the spheres with our weighting sphere



        // add to the vectors
        weightsArray.push_back(weights);
        idsArray.push_back(ids);
    }

    //TODO
    // Do something with our weights and IDs;
}