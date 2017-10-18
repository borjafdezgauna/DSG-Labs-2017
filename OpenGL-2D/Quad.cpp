#include "stdafx.h"
#include "Quad.h"
#include "Renderer.h"
#include "MovingQuad.h"
#include "../3rd-party/SOIL/src/SOIL.h"





Quad::Quad(std::string name, char* textureName)
{
	m_name = name;

	m_myTextureId = SOIL_load_OGL_texture(textureName, 0, 0, 0);



	

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

void GraphicObject2D::shoot()
{
	MovingQuad *mov_rect2 = new MovingQuad("Q_Rect2", "../OpenGL-2D/img/bullet.png");
	mov_rect2->setdirX(0.005);
	mov_rect2->setScale(1, 0.5, 1);
	mov_rect2->setColor(0, 255, 0);
	mov_rect2->setPosition(m_position_X, m_position_Y, m_position_Z);
	Renderer::getRendererInstance()->addObject(mov_rect2);
	
}

void Quad::draw()
{

	//glColor3f(m_r, m_g, m_b);

	glPushMatrix();

	glTranslatef(m_position_X, m_position_Y, m_position_Z);
	glRotatef(m_angles,m_rotation_X, m_rotation_Y, m_rotation_Z);
	glScalef(m_scale_X, m_scale_Y, m_scale_Z);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_myTextureId);

	glTexEnvf(GL_TEXTURE_2D, GL_TEXTURE_ENV_MODE, GL_DECAL);
	
	glBegin(GL_QUADS);


	glTexCoord2f(1.0, 0.0);
	glVertex2f(-0.1, -0.1);
	glTexCoord2f(1.0, 1.0);
	glVertex2f(0.1, -0.1);
	glTexCoord2f(0.0, 1.0);
	glVertex2f(0.1, 0.1);
	glTexCoord2f(0.0, 0.0);
	glVertex2f(-0.1, 0.1);

	glEnd();
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();




	

	
}