#pragma once
#include "Quad.h"
class MovingQuad : public Quad
{
	double m_vx;
	double m_vy;
public:
	MovingQuad(std::string name,double vx, double vy);
	~MovingQuad();
	virtual void draw();
	double getVX()
	{
		return m_vx;
	}
	double getVY()
	{
		return m_vy;
	}
};