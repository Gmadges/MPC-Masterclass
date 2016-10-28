#ifndef SPHERE_H
#define SPHERE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class Sphere : protected QOpenGLFunctions
{
public:
    Sphere();
    virtual ~Sphere();

    void draw(QOpenGLShaderProgram *program);

private:
    void initSphere();

    QVector4D color;

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLBuffer normalBuf;

    unsigned int indexCount;
};

#endif // FLOORPLANE_H
