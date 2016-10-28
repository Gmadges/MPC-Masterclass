#include "sphere.h"

#include <iostream>
#include <math.h>

Sphere::Sphere():
    indexBuf(QOpenGLBuffer::IndexBuffer),
    indexCount(0)
{
    initializeOpenGLFunctions();

    arrayBuf.create();
    indexBuf.create();
    normalBuf.create();

    initSphere();

    color = QVector4D( 20.0f/255.0f, 220.0f/255.0f, 20.0f/255.0f, 1.0f);
}

Sphere::~Sphere()
{
    arrayBuf.destroy();
    indexBuf.destroy();
    normalBuf.destroy();
}

void Sphere::initSphere()
{
    // Calc The Vertices

    float radius = 0.5f;
    unsigned int stacks = 10;
    unsigned int slices = 10;

    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<unsigned int> indices;

    for (unsigned int i = 0; i <= stacks; ++i)
    {

        float V   = i / (float) stacks;
        float phi = V * M_PI;

        // Loop Through Slices
        for (unsigned int j = 0; j <= slices; ++j)
        {
            float U = j / (float) slices;
            float theta = U * (M_PI * 2);

            // Calc The Vertex Positions
            float x = cosf (theta) * sinf (phi);
            float y = cosf (phi);
            float z = sinf (theta) * sinf (phi);

            // Push Back Vertex Data
            vertices.push_back(x * radius);
            vertices.push_back(y * radius);
            vertices.push_back(z * radius);

            //push normal data
            normals.push_back(x);
            normals.push_back(y);
            normals.push_back(z);
        }
    }

    // Calc The Index Positions
    for (unsigned int i = 0; i < slices * stacks + slices; ++i)
    {
        indices.push_back (i);
        indices.push_back (i + slices + 1);
        indices.push_back (i + slices);

        indices.push_back (i + slices + 1);
        indices.push_back (i);
        indices.push_back (i + 1);
    }

    //load to GPU
    arrayBuf.bind();
    arrayBuf.allocate(vertices.data(), vertices.size() * sizeof(float));

    indexBuf.bind();
    indexBuf.allocate(indices.data(), indices.size() * sizeof(unsigned int));

    normalBuf.bind();
    normalBuf.allocate(normals.data(), normals.size() * sizeof(float));

    indexCount = indices.size();
}

void Sphere::draw(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();
    indexBuf.bind();

    program->setUniformValue("objectColor", color);

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

    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}
