#pragma once

#include "GraphicObject2D.h"


#include <string>

class Quad: public GraphicObject2D
{
	float m_r, m_g, m_b;
protected:
	int textura = -1;

public:
	Quad::Quad();
	Quad(std::string mnombre);
	~Quad();

	virtual void draw();
	void setColor(float r, float g, float b);
};

