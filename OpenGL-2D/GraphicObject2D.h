#pragma once
#include "string"

class GraphicObject2D
{
	protected:
		std::string name;
		float x=0, y=0, z=0, rotZ=0, scaleX, scaleY;

public:
	virtual void draw() = 0;

	void setName(std::string pName) {
		name = pName;
	}
	void setTranslate(float pX, float pY, float pZ) {
		x = pX;
		y = pY;
		z = pZ;
	}
	void setRotation(float pZ) {
		rotZ = pZ;
	}
	void setScale(float pScaleX, float pScaleY) {
		scaleX = pScaleX;
		scaleY = pScaleY;
	}

	std::string getName() {
		return name;
	}
	float getX(){
		return x;
	}
	float getY(){
		return y;
	}
	float getZ() {
		return z;
	}
	float getRotation() {
		return rotZ;
	}
	float getScaleX() {
		return scaleX;
	}
	float getScaleY() {
		return scaleY;
	}
};
