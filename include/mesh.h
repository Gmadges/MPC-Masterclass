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

    void loadMesh(std::string _path);

private:
    void initMesh(std::string _path);

    QVector4D color;

    std::vector<QVector3D> m_vertices;
    std::vector<QVector2D> m_texcoord;
    std::vector<unsigned int> m_faces;
    std::vector<QVector3D> m_normals;

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLBuffer normalBuf;
};

#endif // MESH_H
