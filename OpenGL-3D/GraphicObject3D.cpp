#include "GraphicObject3D.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"

void GraphicObject3D::setPosition(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

void GraphicObject3D::addPositionOffset(double x, double y, double z)
{
	m_x = m_x + x;
	m_y = m_y + y;
	m_z = m_z + z;
}

void GraphicObject3D::setRotation(double yaw, double pitch, double roll)
{
	m_yaw = yaw;
	m_pitch = pitch;
	m_roll = roll;
}

void GraphicObject3D::setScale(double scaleX, double scaleY, double scaleZ)
{ 
	m_scaleX = scaleX;
	m_scaleY = scaleY;
	m_scaleZ = scaleZ;
}

void GraphicObject3D::applyMatrix()
{
	//TODO
	//apply the transformation matrix of the object
	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glRotatef(m_roll, 0.0, 0.0, 1.0);
	glRotatef(m_yaw, 0.0, 1.0, 0.0);
	glRotatef(m_pitch, 1.0, 0.0, 0.0);
	glTranslatef(m_x, m_y, m_z);
	glScalef(m_scaleX, m_scaleY, m_scaleZ);

}