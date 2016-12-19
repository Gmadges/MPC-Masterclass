#include "mesh.h"

#include <iostream>

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

Mesh::Mesh(std::string _path):
    indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    // Generate VBOs
    arrayBuf.create();
    indexBuf.create();
    normalBuf.create();
    boneIDBuf.create();
    weightBuf.create();

    // Initializes cube geometry and transfers it to VBOs
    initMesh(_path);

    color = QVector4D(98.0f/255.0f,201.0f/255.0f,109.0f/255.0f,1);

    // hardcode
    QMatrix4x4 tmp;
    tmp.setToIdentity();
    bones.push_back(tmp);
}

Mesh::~Mesh()
{
    arrayBuf.destroy();
    indexBuf.destroy();
    normalBuf.destroy();
    boneIDBuf.destroy();
    weightBuf.destroy();
}

void Mesh::initMesh(std::string _path)
{
    loadMeshFromFile(_path);

    arrayBuf.bind();
    arrayBuf.allocate( vertices.data(),  vertices.size() * sizeof(QVector3D));

    indexBuf.bind();
    indexBuf.allocate( faces.data(),  faces.size() * sizeof(unsigned int));

    normalBuf.bind();
    normalBuf.allocate( normals.data(),  normals.size() * sizeof(QVector3D));

    // fill with empty data
    for(unsigned int i = 0; i < vertices.size(); ++i)
    {
        boneIDs.push_back(SkinIDs());

        // wet all weight to 0.25
        SkinWeights tmp;
        tmp.weight[0] = 0.25;
        tmp.weight[1] = 0.25;
        tmp.weight[2] = 0.25;
        tmp.weight[3] = 0.25;
        weights.push_back(tmp);
    }

    boneIDBuf.bind();
    boneIDBuf.allocate( boneIDs.data(),  boneIDs.size() * sizeof(SkinIDs));
    
    weightBuf.bind();
    weightBuf.allocate( weights.data(),  weights.size() * sizeof(SkinWeights));
}

void Mesh::loadMeshFromFile(std::string _path)
{
    const aiScene* scene = aiImportFile( _path.c_str(),
                                         aiProcess_CalcTangentSpace       |
                                         aiProcess_GenNormals             |
                                         aiProcess_Triangulate            |
                                         aiProcess_JoinIdenticalVertices  |
                                         aiProcess_SortByPType);

      if( !scene)
      {
        std::cout << aiGetErrorString() << std::endl;
        exit(1);
      }

      //loop over meshes
      for (unsigned int i = 0; i < scene->mNumMeshes; ++i)
      {
          //loop into current mesh for vertices
          for (unsigned int j = 0; j < scene->mMeshes[i]->mNumVertices; ++j)
          {
              QVector3D p = QVector3D(scene->mMeshes[i]->mVertices[j].x,
                                      scene->mMeshes[i]->mVertices[j].y,
                                      scene->mMeshes[i]->mVertices[j].z);
               vertices.push_back(p);
          }

          //loop into current mesh for indices
          for (unsigned int j = 0; j < scene->mMeshes[i]->mNumFaces; ++j)
          {
              aiFace f = scene->mMeshes[i]->mFaces[j];
              for (unsigned int k = 0; k < f.mNumIndices; ++k)
              { 
                   faces.push_back(f.mIndices[k]);
              }
          }

          //loop into current mesh for normals, one normal per vertex
          for (unsigned int j = 0; j < scene->mMeshes[i]->mNumVertices; ++j)
          {
              QVector3D m = QVector3D(scene->mMeshes[i]->mNormals[j].x,
                                      scene->mMeshes[i]->mNormals[j].y,
                                      scene->mMeshes[i]->mNormals[j].z);
               normals.push_back(m);
          }
      }
      aiReleaseImport(scene);
}

void Mesh::drawMesh(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();

    program->setUniformValue("objectColor", color);

    program->setUniformValueArray("bones", bones.data(), bones.size());

    // Offset for position
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("a_position");
    int normalLocation = program->attributeLocation("a_normal");
    int boneIDLocation = program->attributeLocation("a_boneIDs");
    int weightLocation = program->attributeLocation("a_weights");

    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(QVector3D));

    normalBuf.bind();
    program->enableAttributeArray(normalLocation);
    program->setAttributeBuffer(normalLocation, GL_FLOAT, 0, 3, sizeof(QVector3D));

    boneIDBuf.bind();
    program->enableAttributeArray(boneIDLocation);
    program->setAttributeBuffer(boneIDLocation, GL_UNSIGNED_INT, 0, 4, sizeof(SkinIDs));

    weightBuf.bind();
    program->enableAttributeArray(weightLocation);
    program->setAttributeBuffer(weightLocation, GL_FLOAT, 0, 4, sizeof(SkinWeights));

    // draw
    glDrawElements(GL_TRIANGLES,  faces.size(), GL_UNSIGNED_INT, 0);
}

std::vector<QVector3D>& Mesh::getVerts()
{
    return  vertices;
}

std::vector<unsigned int>& Mesh::getFaces()
{
    return  faces;
}

void Mesh::setWeights(std::vector<SkinWeights> _weights)
{    
    weights = _weights;
    weightBuf.bind();
    weightBuf.allocate( weights.data(),  weights.size() * sizeof(SkinWeights));
}

void Mesh::setSkinIDs(std::vector<SkinIDs> _ids)
{
    boneIDs = _ids;
    boneIDBuf.bind();
    boneIDBuf.allocate( boneIDs.data(),  boneIDs.size() * sizeof(SkinIDs));
}

void Mesh::setBones(std::vector<QMatrix4x4> _bones)
{
    bones = _bones;
}
