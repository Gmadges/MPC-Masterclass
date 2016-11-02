#ifndef CAMERA_H
#define CAMERA_H

#include <QVector4D>
#include <QVector3D>
#include <QVector2D>
#include <QMatrix4x4>

class Camera
{

public :

  Camera();

  Camera(QVector3D& _eye, QVector3D& _look, QVector3D& _up);

  void pitch(float _angle);
  void yaw(float _angle);
  void set(QVector3D &_eye, QVector3D &_look, QVector3D &_up);
  void move(float _dx,float _dy,float _dz);
  void moveEye(float _dx,  float _dy, float _dz);
  void setViewAngle(float _angle);

  QMatrix4x4 & getViewMatrix() {return m_viewMatrix;}
  QVector4D getEye() {return m_eye;}
  void setEye(QVector4D _e) {m_eye=_e; update();}
  void setLook(QVector4D _e) {m_look=_e; update();}
  QVector4D getLook() {return m_look;}

protected :

  void rotAxes(QVector4D& io_a, QVector4D& io_b, const float _angle);

protected :

  QVector4D m_u;
  QVector4D m_v;
  QVector4D m_n;
  QVector4D m_eye;
  QVector4D m_look;
  QVector4D m_up;
  float m_width;
  float m_height;
  QMatrix4x4 m_viewMatrix;

  void setViewMatrix();
};

#endif /
