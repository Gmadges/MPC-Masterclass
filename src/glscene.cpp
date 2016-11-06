#include "glscene.h"

#include <iostream>
#include <QMouseEvent>
#include <QQuaternion>

#include "modelController.h"
#include "physicsWorld.h"
#include "floorPlane.h"

constexpr float INCREMENT=0.01f;
constexpr float ZOOM=0.1f;

// global for testing
static std::string MODEL_PATH = "./models/GiantTeapot.obj";

GLScene::GLScene(QWidget *parent) :
    QOpenGLWidget(parent),
    pModelController(new ModelController()),
    pPhysicsWorld(new PhysicsWorld()),
    cam_pos(0.0f, 20.0f, -50.0f),
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
    // hardcode this to one, because i know only one model will be being loaded.
    pPhysicsWorld->SetMaskAmount(1);
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

    //load this stuff here because we need to have openGL initialised
    pModelController->loadModelFromFile(MODEL_PATH, pPhysicsWorld);

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
    loadMatricesToShader();

    // draw
    pModelController->drawAll(&program);

    pFloorPlane->draw(&program); 
}

void GLScene::loadMatricesToShader()
{
    // create view mat
    //mat.rotate(QQuaternion::fromEulerAngles(spinXFace, spinYFace, 0.0f));
    viewMat.setToIdentity();
    viewMat.lookAt(cam_pos, QVector3D(0,0,0), QVector3D(0,1,0));


    normMat = viewMat.normalMatrix();

    // normal matrix
    program.setUniformValue("normal_matrix", normMat);

    // MVP matrix
    program.setUniformValue("proj_matrix", projMat);
    program.setUniformValue("view_matrix", viewMat);

    //light position
    m_lightPosLoc = program.uniformLocation("lightPos");
    program.setUniformValue(m_lightPosLoc, QVector3D(0, 50, 100));
}

void GLScene::initShaders()
{
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/simple.vert"))
        close();

    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple.frag"))
        close();

    if (!program.link())
        close();

    if (!program.bind())
        close();
}

void GLScene::toggleSim()
{   
    bSimulate = !bSimulate;

    // just some debug 
    if(bSimulate)
    {
        std::cout<< "simulation on \n";
    }
    else 
    {
        std::cout<< "simulation off \n";
    }
}

void GLScene::resetSim()
{
    
    pModelController->emptyModels();
    pModelController->loadModelFromFile(MODEL_PATH, pPhysicsWorld);
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
