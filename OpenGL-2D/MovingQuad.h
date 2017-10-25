#pragma once

#include "string"
#include "Quad.h"

class MovingQuad : public Quad
{
	int dirX, dirY;
public:
	MovingQuad(const char *filename, float pX, float pY, float pZ, double pDirX, double pDirY);
	~MovingQuad();

	void setPosition(double pDirX, double pDirY);

	virtual void draw();
};

