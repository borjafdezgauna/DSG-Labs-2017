#include "stdafx.h"
#include "Quad.h"
#include "../3rd-party/SOIL/src/SOIL.h"
#include "MovingQuad.h"
#include "Renderer.h"


Quad::Quad()
{}

Quad::Quad(std::string pNombre)
{
	name = pNombre;

}

Quad::Quad(std::string pNombre, const char *filename)
{
	name = pNombre;
 texture_id = SOIL_load_OGL_texture(filename, 0, 0, 0);

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
	glPushMatrix();
	glTranslatef(getX(), getY(), getZ());
	glRotatef(getRotation(), 0, 0, 1);


	glScalef(0.2, 0.2, 1);

	//TODO:

	//2.Textura

	if (texture_id != -1)
	{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glAlphaFunc(GL_GREATER, 0.5);
	glEnable(GL_ALPHA_TEST);

	glBegin(GL_QUADS);

	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.5, -0.5, -10);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5, -0.5, -10);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5, 0.5, -10);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5, 0.5, -10);
	}
	else
	{
		//1. Set the color

		glBegin(GL_QUADS);

		glColor3f(0,0,255);

		glVertex3f(-0.5, -0.5, -10);
		glVertex3f(0.5, -0.5, -10);
		glVertex3f(0.5, 0.5, -10);
		glVertex3f(-0.5, 0.5, -10);
	}

	//2. Draw the cube
	glEnd();
	glPopMatrix();
}