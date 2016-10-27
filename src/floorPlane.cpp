#include "floorPlane.h"

#include <iostream>

FloorPlane::FloorPlane():
    indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    arrayBuf.create();
    indexBuf.create();
    normalBuf.create();

    // Initializes cube geometry and transfers it to VBOs
    initPlane();

    color = QVector4D( 255.0f/255.0f, 21.0f/255.0f, 1.0f/255.0f, 1.0f);
}

FloorPlane::~FloorPlane()
{
    arrayBuf.destroy();
    indexBuf.destroy();
    normalBuf.destroy();
}

void FloorPlane::initPlane()
{
    // hard code floor    

    // o Plane 1
    // v -10 -2.220446049250313e-15 -10
    // v 10 -2.220446049250313e-15 -10
    // v -10 2.220446049250313e-15 10
    // v 10 2.220446049250313e-15 10
    // vn 0 0.10000000149011612 -2.2204460823375376e-17
    // vn 0 0.10000000149011612 -2.2204460823375376e-17
    // vn 0 0.10000000149011612 -2.2204460823375376e-17
    // vn 0 0.10000000149011612 -2.2204460823375376e-17
    // f 1/1/1 3/3/3 2/2/2
    // f 3/3/3 4/4/4 2/2/2

    float verts[16] = { -5.0f, 0.0f, -5.0f,
                        5.0f,  0.0f, -5.0f,
                        -5.0f, 0.0f, 5.0f,
                        5.0f,  0.0f, 5.0f };
    
    unsigned int faces[6] = { 0, 2, 1, 2, 3, 1 };

    float normals[16] = {   0.0f, 0.1f, 0.0f,
                            0.0f, 0.1f, 0.0f,
                            0.0f, 0.1f, 0.0f,
                            0.0f, 0.1f, 0.0f };

    arrayBuf.bind();
    arrayBuf.allocate(verts, 16 * sizeof(float));

    indexBuf.bind();
    indexBuf.allocate(faces, 6 * sizeof(unsigned int));

    normalBuf.bind();
    normalBuf.allocate(normals, 16 * sizeof(float));
}

void FloorPlane::draw(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();

    program->setUniformValue("objectColor", color);
    program->setUniformValue("model_matrix", QMatrix4x4());

    // Offset for position
    quintptr offset = 0;

    // Tell OpenGL programmable pipeline how to locate vertex position data
    int vertexLocation = program->attributeLocation("a_position");
    int normalLocation = program->attributeLocation("a_normal");

    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, 3*sizeof(float));

    normalBuf.bind();
    program->enableAttributeArray(normalLocation);
    program->setAttributeBuffer(normalLocation, GL_FLOAT, 0, 3, 3*sizeof(float));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
