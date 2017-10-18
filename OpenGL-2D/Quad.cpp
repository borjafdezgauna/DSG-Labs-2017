#include "stdafx.h"
#include "Quad.h"
#include "../3rd-party/SOIL/src/SOIL.h"


Quad::Quad(std::string name)
{
	m_name = name;
}




void Quad::setColor(float r, float g, float b)
{
	m_r = r;
	m_g = g;
	m_b = b;
}
void Quad::setTexture(std::string myTextureld)
{
	m_Textureld = SOIL_load_OGL_texture(myTextureld.c_str(),0,0,0);
}

void Quad::draw()
{
	
	//1. Set the color
	if (m_Textureld >= 0)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, m_Textureld);
	}
	else
	{
		glColor3f(m_r, m_g, m_b);
	}

	//2. Draw the cube
	glPushMatrix();
	glTranslatef(m_x,m_y,m_z);
	glRotatef(m_rotation, 0, 0, 1);
	glScalef(0.1,0.1,1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-1, 1, -10);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, -10);
	glTexCoord2f(1, 0);
	glVertex3f(1,-1, -10);
	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, -10);
	glEnd();
	glPopMatrix();
}