#ifndef LINE_H
#define LINE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

class Line : protected QOpenGLFunctions
{
public:
    Line();
    virtual ~Line();

    void draw(QVector3D start, QVector3D end, QOpenGLShaderProgram *program);

private:
    void initLine();

private:
    QVector4D color;

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLBuffer normalBuf;
};

#endif // LINE_H
