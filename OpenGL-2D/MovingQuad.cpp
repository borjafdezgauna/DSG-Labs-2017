#include "stdafx.h"
#include "MovingQuad.h"
#include "../3rd-party/SOIL/src/SOIL.h"




MovingQuad::MovingQuad(const char *filename, float pX, float pY, float pZ, double pDirX, double pDirY)
{
	x = pX;
	y = pY;
	z = pZ;
	texture_id = SOIL_load_OGL_texture(filename, 0, 0, 0);
	setPosition(pDirX,pDirY);
	
}


MovingQuad::~MovingQuad()
{
}

void MovingQuad::setPosition(double pDirX, double pDirY)
{
	dirX = pDirX;
	dirY = pDirY;
}

void MovingQuad::draw()
{

	x += dirX*0.001;
	y += dirY*0.001;

	Quad::draw(); //hace lo que hace draw
}