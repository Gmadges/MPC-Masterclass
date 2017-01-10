#include "line.h"

Line::Line():
    indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();

    arrayBuf.create();
    indexBuf.create();
    normalBuf.create();

    // Initializes cube geometry and transfers it to VBOs
    initLine();

    color = QVector4D( 250.0f/255.0f, 10.0f/255.0f, 10.0f/255.0f, 1.0f);
}

Line::~Line()
{
    arrayBuf.destroy();
    indexBuf.destroy();
    normalBuf.destroy();
}

void Line::initLine()
{
    // hard code floor    

    float verts[16] = { -1.0f, -1.0f, 0.0f,
                        1.0f,  -1.0f, 0.0f,
                        -1.0f, 1.0f, 0.0f,
                        1.0f,  1.0f, 0.0f };
    
    unsigned int faces[6] = { 0, 2, 1, 2, 3, 1 };

    float normals[16] = {   0.0f, 0.0f, 0.1f,
                            0.0f, 0.0f, 0.1f,
                            0.0f, 0.0f, 0.1f,
                            0.0f, 0.0f, 0.1f };

    arrayBuf.bind();
    arrayBuf.allocate(verts, 16 * sizeof(float));

    indexBuf.bind();
    indexBuf.allocate(faces, 6 * sizeof(unsigned int));

    normalBuf.bind();
    normalBuf.allocate(normals, 16 * sizeof(float));
}

void Line::draw(QVector3D start, QVector3D end, QOpenGLShaderProgram *program)
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

    float verts[16] = { start.x(), start.y() - 0.15f, start.z(),
                    end.x(),  end.y() - 0.15f, end.z(),
                    start.x(), start.y() + 0.15f, start.z(),
                    end.x(),  end.y() + 0.15f, end.z() };

    arrayBuf.allocate(verts, 16 * sizeof(float));

    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, 3*sizeof(float));

    normalBuf.bind();
    program->enableAttributeArray(normalLocation);
    program->setAttributeBuffer(normalLocation, GL_FLOAT, 0, 3, 3*sizeof(float));

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}