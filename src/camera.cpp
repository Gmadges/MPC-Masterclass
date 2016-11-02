#include "camera.h"

Camera::Camera()
{
  m_width=720;
  m_height=576;
  m_eye.set(1,1,1);
}

void Camera::set(QVector3D &_eye, QVector3D &_look,  QVector3D &_up  )
{
	// make U, V, N vectors
	m_eye=_eye;
	m_look=_look;
	m_up=_up;
	m_n=m_eye-m_look;
	m_u=m_up.cross(m_n);
	m_v=m_n.cross(m_u);
	m_u.normalize();
	m_v.normalize();
	m_n.normalize();
	setViewMatrix();
}

Camera::Camera(QVector3D &_eye, QVector3D &_look, QVector3D &_up )
{
	setDefaultCamera();
	set(_eye,_look,_up);
}

void Camera::setViewMatrix()  
{
    // grab a pointer to the matrix so we can index is quickly
    auto M = &m_viewMatrix.m_m[0][0];
    M[0] =  m_u.x();         M[1] =  m_v.x();        M[2] =  m_n.x();        M[3] = 0.0;
    M[4] =  m_u.y();         M[5] =  m_v.y();        M[6] =  m_n.y();        M[7] = 0.0;
    M[8]  = m_u.z();         M[9] =  m_v.z();        M[10]=  m_n.z();        M[11] =0.0;
    M[12] = -m_eye.dot(m_u); M[13]= -m_eye.dot(m_v); M[14]= -m_eye.dot(m_n); M[15] =1.0;
}

void Camera::move( float _dx, float _dy,  float _dz )
{
// simply add the translation to the current eye point
	m_eye.x() += _dx;
	m_eye.y() += _dy;
	m_eye.z() += _dz;
	setViewMatrix();
}

void Camera::rotAxes( QVector4D& io_a, QVector4D& io_b,  const float _angle  )  
{
// rotate orthogonal vectors a (like x axis) and b(like y axis) through angle degrees
	// convert to radians
	float ang = radians(_angle);
	// pre-calc cos and sine
  float c = cosf(ang);
  float s = sinf(ang);
	// tmp for io_a vector
	QVector4D t( c * io_a.x() + s * io_b.x(),  c * io_a.y() + s * io_b.y(),  c * io_a.z() + s * io_b.z());
	// now set to new rot value
	io_b.set(-s * io_a.x() + c * io_b.x(), -s * io_a.y() + c * io_b.y(), -s * io_a.z() + c * io_b.z());
	// put tmp into _a'
	io_a.set(t.x(), t.y(), t.z());
}

void Camera::pitch(float _angle )  
{
  rotAxes(m_n, m_v, _angle);
  setViewMatrix();
}

void Camera::yaw(float _angle )  
{
  rotAxes(m_u, m_n, _angle);
  setViewMatrix();
}

void Camera::moveEye( float _dx, float _dy,   float _dz  )  
{
	m_eye.x()+=_dx;
	m_eye.y()+=_dy;
	m_eye.z()+=_dz;
	m_n=m_eye-m_look;
	m_u.set(m_up.cross(m_n));
	m_v.set(m_n.cross(m_u));
	// normalize the vectors
	m_u.normalize();
	m_v.normalize();
	m_n.normalize();
	// pass to OpenGL
	setViewMatrix();
}

