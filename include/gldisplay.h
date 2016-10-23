#ifndef GLDISPLAY_H
#define GLDISPLAY_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector2D>
#include <QVector3D>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>

#include <memory>

class Mesh;

class GLDisplay : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GLDisplay(QWidget *parent = 0);
    ~GLDisplay();

protected:

    // controls
    void mousePressEvent(QMouseEvent *_event) override;
    void mouseMoveEvent(QMouseEvent *_event) override;
    void mouseReleaseEvent(QMouseEvent *_event) override;
    void keyPressEvent(QKeyEvent *_event) override;
    void wheelEvent(QWheelEvent *_event) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();
    void loadMatricesToShader();

private:
    //geometry
    std::shared_ptr<Mesh> pMesh;

    //lights
    int m_lightPosLoc;

    //shaders
    QOpenGLShaderProgram program;

    //matrices
    QMatrix4x4 projMat; // projection matrix
    QMatrix4x4 modelMat; //modelmatrix
    QMatrix4x4 viewMat; // view matrix
    QMatrix3x3 normMat; // normal matrix

    QVector3D cam_pos;

    //view variables
    bool bRotate;
    bool bTranslate;
    int origX;
    int origY;
    int origXPos;
    int origYPos;
    int spinXFace;
    int spinYFace; 
};

#endif // GLDISPLAY_H
