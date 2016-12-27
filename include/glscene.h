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
class FloorPlane;

class GLScene : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    
    //ctor
    GLScene(QWidget *parent = 0);

    //dtor
    ~GLScene();

    void toggleSim();
    void resetSim();
    void clearSim();

    void showMesh(bool show);
    void showPhys(bool show);

    void setSimSteps(int _steps);

    void loadObject(std::string filePath);

    std::shared_ptr<ModelController> getModelController();

protected:

    // controls
    void mousePressEvent(QMouseEvent *_event) override;
    void mouseMoveEvent(QMouseEvent *_event) override;
    void mouseReleaseEvent(QMouseEvent *_event) override;
    void keyPressEvent(QKeyEvent *_event) override;
    void wheelEvent(QWheelEvent *_event) override;
    void timerEvent(QTimerEvent *_event) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void initShaders();
    void loadMatricesToShaders(QOpenGLShaderProgram *pProgram);

private:
    
    // the real deals
    std::shared_ptr<ModelController> pModelController;
    std::shared_ptr<PhysicsWorld> pPhysicsWorld;
    std::shared_ptr<FloorPlane> pFloorPlane;

    //lights
    int lightPosLoc;

    //shaders
    QOpenGLShaderProgram simpleShaderProgram;
    QOpenGLShaderProgram skinShaderProgram;

    //matrices
    QMatrix4x4 projMat; // projection matrix
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

    //sim variables
    bool bSimulate;
};

#endif // GLSCENE_H
