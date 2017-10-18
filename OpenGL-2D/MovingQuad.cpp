#include "MovingQuad.h"
#include "../3rd-party/SOIL/src/SOIL.h"



MovingQuad::MovingQuad(float mx, float my, float mz, double mvx, double mvy)
{
	x = mx;
	y = my;
	z = mz;
	vx = mvx;
	vy = mvy;
	textura = SOIL_load_OGL_texture("img/alien-01.png", 0, 0, 0);
}
MovingQuad::~MovingQuad()
{
}
void MovingQuad::draw() {
	x = x + (vx*0.01);
	y = y + (vy*0.01);
	Quad::draw();
}