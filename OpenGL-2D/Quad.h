#pragma once

#include "GraphicObject2D.h"

class Quad: public GraphicObject2D
{
	float m_r, m_g, m_b;
public:
	Quad();
	~Quad();

	virtual void draw();
	void setColor(float r, float g, float b);
};

