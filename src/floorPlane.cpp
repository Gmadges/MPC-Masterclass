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

    color = QVector4D( 204.0f/255.0f, 204.0f/255.0f, 204.0f/255.0f, 1.0f);
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

    float verts[16] = { -100.0f, 0.0f, -100.0f,
                        100.0f,  0.0f, -100.0f,
                        -100.0f, 0.0f, 100.0f,
                        100.0f,  0.0f, 100.0f };
    
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

    QMatrix4x4 model;
    model.setToIdentity();
    program->setUniformValue("model_matrix", model);

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
