#include "stdafx.h"
#include "Luces.h"

int Luces::numLuces= 0;

Luces::Luces(float amb_r, float amb_g, float amb_b, float dif_r, float dif_g, float dif_b)
{
	GLfloat light_ambient[] = { amb_r,amb_g,amb_b,1.0 };
	GLfloat light_diffuse[] = { dif_r,dif_g,dif_b,1.0 };
	glLightfv(GL_LIGHT0+numLuces, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0+numLuces, GL_DIFFUSE, light_diffuse);

	index = numLuces;
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0+numLuces);
	numLuces++;
}


Luces::~Luces()
{
}

void Luces::cambiarActivacion()
{
	if (isActive) {
		isActive = false;
		glDisable(GL_LIGHT0 + index);
	}
	else {
		isActive = true;
		glEnable(GL_LIGHT0 + index);
	}
	;
}
