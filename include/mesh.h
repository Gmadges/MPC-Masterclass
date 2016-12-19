#ifndef MESH_H
#define MESH_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include <vector>
#include <string>

class Mesh : protected QOpenGLFunctions
{
public:
    Mesh(std::string _path);
    virtual ~Mesh();

    void drawMesh(QOpenGLShaderProgram *program);

    std::vector<QVector3D>& getVerts();
    std::vector<unsigned int>& getFaces();

private:

    // This loads mesh from file and then loads to the GPU buffers
    void initMesh(std::string _path);

    // This uses assimp to get the data from the file and fill our arrays, ready to be loaded.
    void loadMeshFromFile(std::string _path);

    QVector4D color;

    // store these incase we need them later.... we do
    std::vector<QVector3D> vertices;
    std::vector<unsigned int> faces;
    std::vector<QVector3D> normals;

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLBuffer normalBuf;

    QOpenGLBuffer boneIDBuf;
    QOpenGLBuffer weightBuf;
    
};

#endif // MESH_H
