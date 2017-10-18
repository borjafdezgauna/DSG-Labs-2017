#pragma once
#include "Quad.h"

class MovingQuad : public Quad
{
	double m_dir_X = 0.0;
	double m_dir_Y = 0.0;

public:
	MovingQuad(std::string name, char* texturePath);
	~MovingQuad();
	void setdirX(double amountX);
	void setdirY(double amountY);
	virtual void draw();
};

