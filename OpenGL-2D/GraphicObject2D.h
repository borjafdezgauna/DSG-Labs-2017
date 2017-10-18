#pragma once
#include <string>

class GraphicObject2D
{
protected:

	double x= 0, y= 0, z= 0, escalado_x=0, escalado_y=0, rotacion= 0;
	std::string nombre;

public:
	virtual void draw() =0;
	double getX();
	double getY();
	double getZ();
	double getEscaladoX();
	double getEscaladoY();
	double getRotacion();
	void rotate(double angle);
	void escalar(double escx, double escy);
	void setPosicion(double mx,double my,double mz);
	std::string  GraphicObject2D::getname();

};