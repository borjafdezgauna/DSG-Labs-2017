#include "MovingQuad.h"



MovingQuad::MovingQuad(std::string name, double vx, double vy) :Quad(name)
{
	m_vx = vx;
	m_vy = vy;
}


MovingQuad::~MovingQuad()
{
}


void MovingQuad::draw()
{
	m_x += m_vx * 0.01;
	m_y += m_vy * 0.01;
	Quad::draw();
}