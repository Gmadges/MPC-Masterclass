#ifndef GLSCENE_H
#define GLSCENE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QVector3D>
#include <QOpenGLShaderProgram>

#include <memory>

class ModelController;
class PhysicsWorld;

class GLScene : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    
    //ctor
    GLScene(QWidget *parent = 0);

    //dtor
    ~GLScene();

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
    std::shared_ptr<ModelController> pModelController;
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;

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

#endif // GLSCENE_H
