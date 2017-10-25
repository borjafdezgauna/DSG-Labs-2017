#pragma once

#include "string"
#include "GraphicObject2D.h"

class Quad: public GraphicObject2D
{
protected:
	float m_r, m_g, m_b;
	int texture_id = -1;
public:
	Quad();
	Quad(std::string pNombre);
	Quad(std::string pNombre, const char *filename);

	~Quad();

	virtual void draw();
	void setColor(float r, float g, float b);

};

