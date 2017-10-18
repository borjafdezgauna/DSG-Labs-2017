#pragma once
#include "GraphicObject2D.h"



	double GraphicObject2D::getX(){
		return x;
	}
	double GraphicObject2D::getY() {
		return y;
	}
	double GraphicObject2D::getEscaladoX() {
		return escalado_x;

	}
	double GraphicObject2D::getEscaladoY() {
		return escalado_y;
	}
	double  GraphicObject2D::getRotacion() {
		return rotacion;
	}
	void GraphicObject2D::setPosicion(double mx, double my, double mz) {
		x = mx;
		y = my;
		z = mz;
	}
	std::string  GraphicObject2D::getname(){
		return nombre;
	}
	double GraphicObject2D::getZ() {
		return z;
	}
	void GraphicObject2D::rotate(double angle) {
		rotacion = angle;
	}
	void GraphicObject2D::escalar(double escx, double escy) {
		escalado_x =escx;
		escalado_y = escy;
	}
	

