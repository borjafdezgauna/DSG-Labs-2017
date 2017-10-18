#pragma once
#include <string>

class GraphicObject2D
{
protected: 
	
	float m_r, m_g, m_b;

	double m_position_X = 0.0;
	double m_position_Y = 0.0;
	double m_position_Z = 0.0;

	double m_angles = 0.0;
	double m_scale_X = 0.0;
	double m_scale_Y = 0.0;
	double m_scale_Z = 0.0;

	double m_rotation_X = 0.0;
	double m_rotation_Y = 0.0;
	double m_rotation_Z = 0.0;




public:
	unsigned int m_myTextureId;
	std::string m_name = "";
	virtual void draw() = 0;
	void setColor(float r, float g, float b);
	void setPosition(double x, double y, double z);
	void moveAmount(double x, double y, double z);
	void rotateAmount(double angles, double x, double y, double z);
	void setRotation(double angles, double x, double y, double z);
	void setScale(double x, double y, double z);
	void shoot();
};