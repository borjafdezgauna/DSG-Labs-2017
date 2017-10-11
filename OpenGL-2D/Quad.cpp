#include "stdafx.h"
#include "Quad.h"





Quad::Quad(std::string name)
{
	m_name = name;
}


Quad::~Quad()
{
}

void GraphicObject2D::setColor(float r, float g, float b)
{
	m_r = r;
	m_g = g;
	m_b = b;
}

void GraphicObject2D::setPosition(double x, double y, double z)
{
	m_position_X = x;
	m_position_Y = y;
	m_position_Z = z;
}

void GraphicObject2D::moveAmount(double x, double y, double z)
{
	m_position_X = m_position_X + x;
	m_position_Y = m_position_Y + y;
	m_position_Z = m_position_Z + z;
}

void GraphicObject2D::rotateAmount(double angles, double x, double y, double z)
{
	m_angles = m_angles + angles;
	m_rotation_X = x;
	m_rotation_Y = y;
	m_rotation_Z = z;
}

void GraphicObject2D::setRotation(double angles, double x, double y, double z)
{
	m_angles = angles;
	m_rotation_X = x;
	m_rotation_Y = y;
	m_rotation_Z = z;
}

void GraphicObject2D::setScale(double x, double y, double z)
{
	m_scale_X = x;
	m_scale_Y = y;
	m_scale_Z = z;
}

void Quad::draw()
{
	//TODO:

	//1. Set the color
	glColor3f(m_r, m_g, m_b);

	//2. Draw the cube
	glPushMatrix();

	glTranslatef(m_position_X, m_position_Y, m_position_Z);
	glRotatef(m_angles,m_rotation_X, m_rotation_Y, m_rotation_Z);

	glBegin(GL_QUADS);
	glVertex3f(-0.1, -0.1, -2);
	glVertex3f(0.1, -0.1, -2);
	glVertex3f(0.1, 0.1, -2);
	glVertex3f(-0.1, 0.1, -2);
	glEnd();

	glPopMatrix();

	

	
}