#pragma once
#include "GraphicObject2D.h"

class Quad: public GraphicObject2D
{
	
public:
	Quad(std::string name);
	~Quad();

	virtual void draw();
	
};

