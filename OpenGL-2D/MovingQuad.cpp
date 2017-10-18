#include "MovingQuad.h"
#include "stdafx.h"




MovingQuad::MovingQuad(std::string name, char* texturePath):Quad(name, texturePath)
{
	
}


MovingQuad::~MovingQuad()
{
}

void MovingQuad::draw()
{	

	m_position_X += m_position_X*m_dir_X;
	m_position_Y += m_position_Y*m_dir_Y;

	Quad::draw();
}

void MovingQuad::setdirX(double amountX)
{
	m_dir_X = amountX;
}

void MovingQuad::setdirY(double amountY)
{
	m_dir_Y = amountY;
}

