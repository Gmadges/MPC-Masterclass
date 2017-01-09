#include "model.h"

#include "mesh.h"
#include "physicsBody.h"
#include "types.h"
#include <iterator>
#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <utility>

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

    //reskin
    //weightMeshFromPhysicsBody();
}

void Model::drawMesh(QOpenGLShaderProgram *pShader, bool bGPUSkinning)
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

            pMesh->drawMesh(pShader, bGPUSkinning);
        }
    }
}

void Model::drawPhysicsBody(QOpenGLShaderProgram *pShader)
{
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
    // update bone transforms
    auto spheres = pPhysicsBody->getRigidBodies();
    if(!spheres.empty())
    {
        std::vector<QMatrix4x4> boneTransforms;
        
        for(auto sphere : spheres)
        {
            // just get the translate data no rotation and scale;
            // get a standard transform
            QMatrix4x4 transform;
            transform.setToIdentity();

            // tricky part
            // upcast the motion state to a default one which stores the original start transform and new
            // find the translation from its starting point
            // use this translation with the transform mattrix we will store
            btDefaultMotionState* pState = dynamic_cast<btDefaultMotionState*>(sphere.first->getMotionState());
            btVector3 trans = pState->m_graphicsWorldTrans.getOrigin() - pState->m_startWorldTrans.getOrigin();
            transform.translate(QVector3D(trans.x() ,trans.y(), trans.z()));
            
            boneTransforms.push_back(transform);
        }
    
        pMesh->setBones(boneTransforms);
    }
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

QVector3D Model::getPositionForBody(std::shared_ptr<btRigidBody> pBody)
{
    btTransform trans1;
    pBody->getMotionState()->getWorldTransform(trans1);
    btVector3 pos = trans1.getOrigin();
    return QVector3D(pos.x() ,pos.y(), pos.z());
}

void Model::weightMeshFromPhysicsBody()
{
    //Get mesh verts
    auto verts = pMesh->getVerts();

    //Get spheres
    auto spheres = pPhysicsBody->getRigidBodies();

    //vector of weights and ids
    std::vector<SkinWeights> weightsArray;
    std::vector<SkinIDs> idsArray;

    //HARD CODED weight radius for now
    float weightRadius = 5.0f;

    // Iterate through verts and find nearest spheres based on weighting value
    // alot of brute force searching
    for(auto vert : verts)
    {
        auto nearest = getNearestSpheres(vert, spheres);

        // Figure out weighting by comparing the volume intersection of the spheres with our weighting sphere
        // iterate through from nearest to furthest
        // store volumes
        std::vector<float> intersects;

        float nearestDist = 0.0f;
        for(unsigned int i =0; i < nearest.size(); ++i)
        {
            // first check for intersection
            auto sphere = spheres[nearest[i]];
            auto spherePos = getPositionForBody(sphere.first);
            float dist = QVector3D::dotProduct(vert, spherePos);

            if(i == 0) { nearestDist = abs(dist); }

            if(abs(dist) < (sphere.second + weightRadius + nearestDist))
            {
                //add amount of intersect
                intersects.push_back((sphere.second + weightRadius + nearestDist) - abs(dist));
            }
        }

        SkinWeights weights;
        SkinIDs ids;

        // calc weights
        // should always have one value
        for(unsigned int j = 0; j < MAX_WEIGHTS; ++j)
        {
            if(j < intersects.size())
            {
                float sum = 0.0f;
                for(float num : intersects)
                {
                    sum += num;
                }

                weights.weight[j] = intersects[j] / sum;
                ids.id[j] = (float)nearest[j];
            }
            else
            {
                weights.weight[j] = 0.0f;
                ids.id[j] = (float)nearest[j];
            }
        }

        // add to the vectors
        weightsArray.push_back(weights);
        idsArray.push_back(ids);
    }

    // //print debug
    // for(auto itr : weightsArray)
    // {
    //     if(itr.weight[0] > 1.0f || itr.weight[0] < 1.0f)
    //     {
    //         std::cout << "Weight ------------------------------ \n";
    //         std::cout << "weight: " << itr.weight[0] << "\n"; 
    //     }
    // }

    // std::cout << "\n";
    // for(auto itr : idsArray)
    // {
    //     std::cout << " " << itr.id[0] << " ";
    // }
    // std::cout << "\n";

    pMesh->setWeights(weightsArray);
    pMesh->setSkinIDs(idsArray);

    update();
}

std::vector<unsigned int> Model::getNearestSpheres(QVector3D vert, std::vector<std::pair<std::shared_ptr<btRigidBody>, float>>& spheres)
{
    // gonna use a priority queue because it looks useful and I'll just grab the top 4 at the end
    // cant be bothered to write my own sorting thing
    // comparison lambda
    auto cmp = [](std::pair<unsigned int, float> left, std::pair<unsigned int, float> right) { 
        return left.second > right.second;
    };

    std::priority_queue<std::pair<unsigned int, float>, std::vector<std::pair<unsigned int, float>>, decltype(cmp)> sphereQueue(cmp);

    // through the spheres we go
    for(unsigned int i = 0; i < spheres.size(); ++i)
    {
        // find the 4(hardcoded) nearest spheres
        // I do this instead of intersections because for verts that are distant from spheres it would be easier 
        // to keep and delete than look again. 

        // whats defines nearest?
        // I'm just gonna do smallest values of vert location and sphere surface
        // other options could be to look at intersections and colume sizes etc. maybe explore later
        //btVector3 spherePos = getPositionForBody(sphere.first);
        QVector3D spherePos = getPositionForBody(spheres[i].first);
        float sphereRadius = spheres[i].second;

        // dist from centre of sphere to vert
        float centreDist = QVector3D::dotProduct(vert, spherePos);
        // dist from surface to vert
        float dist = abs(sphereRadius - centreDist);

        sphereQueue.push(std::pair<unsigned int, float>(i, dist));
    }

    // get 4 smallest values
    std::vector<unsigned int> nearestSpheres;
    for(unsigned int j = 0; j < MAX_WEIGHTS; ++j) 
    {
        nearestSpheres.push_back(sphereQueue.top().first);
        sphereQueue.pop();
    }

    return nearestSpheres;
}

