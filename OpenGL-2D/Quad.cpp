#include "stdafx.h"
#include "Quad.h"
#include "../3rd-party/SOIL/src/SOIL.h"


Quad::Quad()
{
	
}

Quad::Quad(std::string mnombre)
{
	nombre = mnombre;
	textura = SOIL_load_OGL_texture("img/fighter-01.png", 0, 0, 0);
}


Quad::~Quad()
{
}

void Quad::setColor(float r, float g, float b)
{
	m_r = r;
	m_g = g;
	m_b = b;
}
void Quad::draw()
{
	//TODO:
	glPushMatrix();
	glScalef(0.1, 0.1, 1);
	glTranslatef(x, y, z);
	glRotatef(rotacion, 0, 0, 1);


	//1. Set the color
	
	if (textura == -1) {
		glColor3f(m_r, m_g, m_b);
	}
	else {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textura);
	}
	//2. Draw the cube
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 1);
	glVertex3f(1, 1, -10);
	glTexCoord2f(1, 0);
	glVertex3f(1, -1, -10);
	glTexCoord2f(0, 0);
	glVertex3f(-1, -1, -10);
	glTexCoord2f(0, 1);
	glVertex3f(-1,1,-10);
	glEnd();
	glPopMatrix();



}