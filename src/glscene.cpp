#include "glscene.h"

#include <iostream>
#include <QMouseEvent>
#include <QQuaternion>

#include "modelController.h"
#include "physicsWorld.h"
#include "floorPlane.h"

constexpr float INCREMENT=0.01f;
constexpr float ZOOM=0.1f;

GLScene::GLScene(QWidget *parent) :
    QOpenGLWidget(parent),
    pModelController(new ModelController()),
    pPhysicsWorld(new PhysicsWorld()),
    cam_pos(0.0f, 25.0f, -75.0f),
    bRotate(false),
    bTranslate(false),
    origX(0),
    origY(0),
    origXPos(0),
    origYPos(0),
    spinXFace(0),
    spinYFace(0),
    bSimulate(false)
{
    // opengl surface config
    QSurfaceFormat format = QSurfaceFormat::defaultFormat();
    format.setSamples(16);
    format.setSwapInterval(0);
    QSurfaceFormat::setDefaultFormat(format);
    this->setFormat(format);

    startTimer(10);

    pPhysicsWorld->setUseCollisionMasks(true);
}

GLScene::~GLScene()
{
}

void GLScene::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(0.4f, 0.4f, 0.4f, 1.0f);

    initShaders();

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_MULTISAMPLE);

    pFloorPlane.reset(new FloorPlane());
}

void GLScene::resizeGL(int w, int h)
{
    qreal aspect = qreal(w) / qreal(h ? h : 1);
    const qreal zNear = 1.0, zFar = 1000.0, fov = 45.0;
    projMat.setToIdentity();
    projMat.perspective(fov, aspect, zNear, zFar);
}

void GLScene::paintGL()
{   
    // clear tings
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // load matrices;
    loadMatricesToShaders();

    // draw
    pFloorPlane->draw(&simpleShaderProgram);
    pModelController->drawAllMesh(&simpleShaderProgram);
    pModelController->drawAllPhysicsBody(&simpleShaderProgram);
}

void GLScene::loadMatricesToShaders()
{
    // create view mat
    //mat.rotate(QQuaternion::fromEulerAngles(spinXFace, spinYFace, 0.0f));
    viewMat.setToIdentity();
    viewMat.lookAt(cam_pos, QVector3D(0,5,0), QVector3D(0,1,0));


    normMat = viewMat.normalMatrix();

    // normal matrix
    simpleShaderProgram.setUniformValue("normal_matrix", normMat);
    //skinShaderProgram.setUniformValue("normal_matrix", normMat);

    // MVP matrix
    simpleShaderProgram.setUniformValue("proj_matrix", projMat);
    simpleShaderProgram.setUniformValue("view_matrix", viewMat);

    //skinShaderProgram.setUniformValue("proj_matrix", projMat);
    //skinShaderProgram.setUniformValue("view_matrix", viewMat);

    //light position
    lightPosLoc = simpleShaderProgram.uniformLocation("lightPos");
    simpleShaderProgram.setUniformValue(lightPosLoc, QVector3D(0, 50, 100));


    //lightPosLoc = skinShaderProgram.uniformLocation("lightPos");
    //skinShaderProgram.setUniformValue(lightPosLoc, QVector3D(0, 50, 100));
}

void GLScene::initShaders()
{
    if (!simpleShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/simple.vert"))
        close();

    if (!simpleShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple.frag"))
        close();

    if (!skinShaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/skinning.vert"))
        close();

    if (!skinShaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple.frag"))
        close();

    if (!simpleShaderProgram.link())
        close();

    if (!skinShaderProgram.link())
        close();

    if (!simpleShaderProgram.bind())
        close();
}

void GLScene::toggleSim()
{   
    bSimulate = !bSimulate;
}

void GLScene::resetSim()
{
    // personal preference - but i want the sim to stop when i reset
    bSimulate = false;
    pModelController->resetModels();
}

void GLScene::clearSim()
{
    pModelController->emptyModels();
}

void GLScene::showMesh(bool show)
{   
    pModelController->showAllMeshes(show);
}

void GLScene::showPhys(bool show)
{   
    pModelController->showAllPhysShapes(show);
}

void GLScene::mousePressEvent(QMouseEvent *_event)
{
    if(_event->button() == Qt::LeftButton)
    {
        origX = _event->x();
        origY = _event->y();
        bRotate =true;
    }
    // right mouse translate mode
    else if(_event->button() == Qt::RightButton)
    {
        origXPos = _event->x();
        origYPos = _event->y();
        bTranslate=true;
    }
}

void GLScene::mouseMoveEvent(QMouseEvent *_event)
{
    if(bRotate && _event->buttons() == Qt::LeftButton)
    {
        int diffx=_event->x()-origX;
        int diffy=_event->y()-origY;
        spinXFace += static_cast<int>( 0.5f * diffy);
        spinYFace += static_cast<int>( 0.5f * diffx);
        origX = _event->x();
        origY = _event->y();
        update();
    }
    // right mouse translate code
    else if(bTranslate && _event->buttons() == Qt::RightButton)
    {
        int diffX = static_cast<int>(_event->x() - origXPos);
        int diffY = static_cast<int>(_event->y() - origYPos);
        origXPos=_event->x();
        origYPos=_event->y();
        cam_pos += QVector3D(INCREMENT * diffX, -(INCREMENT * diffY), 0.0f);
        update();
    }
}

void GLScene::mouseReleaseEvent(QMouseEvent *_event)
{
    // we then set Rotate to false
    if (_event->button() == Qt::LeftButton)
    {
        bRotate=false;
    }
    // right mouse translate mode
    if (_event->button() == Qt::RightButton)
    {
        bTranslate=false;
    }
}

void GLScene::keyPressEvent(QKeyEvent *_event)
{
    // that method is called every time the main window recives a key event.
    // we then switch on the key value and set the camera in the GLWindow
    switch (_event->key())
    {
        // turn on wirframe rendering
        case Qt::Key_W : glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); break;
        // turn off wire frame
        case Qt::Key_S : glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); break;
        default : break;
    }
    update();
}

void GLScene::wheelEvent(QWheelEvent *_event)
{
	// check the diff of the wheel position (0 means no change)
	if(_event->delta() > 0)
	{
		cam_pos += QVector3D(0.0f, 0.0f, ZOOM);
	}
	else if(_event->delta() <0 )
	{
		cam_pos += QVector3D(0.0f, 0.0f, -ZOOM);
	}
	update();
}

void GLScene::timerEvent(QTimerEvent *_event)
{
  if(bSimulate)
  {
      pPhysicsWorld->step(1.0/60.0,1);
  }
  update();
}

void GLScene::loadObject(std::string filePath)
{   
    // if using masks we need to reset how many we have and then reset all the models
    if(pPhysicsWorld->isUsingCollisionMask())
    {
        // add one to it for the next one
        pPhysicsWorld->setMaskAmount(pModelController->getNumModels() + 1);

        pModelController->resetModels();
    }
    
    pModelController->loadModelFromFile(filePath, pPhysicsWorld);
}

std::shared_ptr<ModelController> GLScene::getModelController()
{
    return pModelController;
}
