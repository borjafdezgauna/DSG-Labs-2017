#pragma once
#include "Quad.h"
class MovingQuad : public Quad
{
	
public:
	double vy, vx;
	MovingQuad(float mx, float my, float mz, double mvx, double mvy );
	~MovingQuad();
	virtual void MovingQuad::draw();
};

