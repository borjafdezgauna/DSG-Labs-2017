#pragma once
#include "GraphicObject3D.h"
class Cube : public GraphicObject3D
{
public:
	Cube();
	~Cube();

	virtual void draw();

};
