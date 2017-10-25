#include "Camera.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::applyMatrix()
{
	//TODO: apply the inverse transformation
	//1. Set the perspective matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
	
	//2. Reset the modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//3. Apply the camera's own transformation: translation/rotation
	glRotatef(-m_roll, 0.0, 0.0, 1.0);
	glRotatef(-m_yaw, 0.0, 1.0, 0.0);
	glRotatef(-m_pitch, 1.0, 0.0, 0.0);
	glTranslatef(-m_x,-m_y,-m_z);
}