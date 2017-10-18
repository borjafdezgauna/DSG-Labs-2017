#pragma once
#include "GraphicObject2D.h"

class Quad: public GraphicObject2D
{
	
public:

	Quad(std::string name, char* texturePath);
	~Quad();

	virtual void draw();
	
};

