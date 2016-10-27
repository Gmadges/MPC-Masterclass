#ifndef FLOORPLANE_H
#define FLOORPLANE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

#include <vector>
#include <string>

class FloorPlane : protected QOpenGLFunctions
{
public:
    FloorPlane();
    virtual ~FloorPlane();

    void draw(QOpenGLShaderProgram *program);

private:
    void initPlane();

    QVector4D color;

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLBuffer normalBuf;
};

#endif // FLOORPLANE_H
