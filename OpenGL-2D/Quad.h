#pragma once

#include "GraphicObject2D.h"
#include <string>

class Quad: public GraphicObject2D
{
	float m_r, m_g, m_b;
	int m_Textureld= -1;
	

public:
	Quad (std::string name);
	~Quad(){}

	virtual void draw();
	void setColor(float r, float g, float b);
	void setTexture(std::string myTextureld);

};

