#pragma once
#include <string>

class GraphicObject2D
{
protected:
	std::string m_name;
	double m_x = 0, m_y = 0, m_z = 0;
	double m_rotation = 0;
	double scale_x = 1;
	double scale_y = 1;
	
public:
	virtual void draw() = 0;

	void setName(std::string name) { m_name = name; }
	std::string getName() { return m_name; }
	void setPosition(double x, double y, double z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	double getX()
	{
		return m_x;
	}
	double getY()
	{
		return m_y;
	}
	double getZ()
	{
		return m_z;
	}
	void setRotate(double rotation)
	{
		m_rotation = rotation;
	}
	double getRotate()
	{
		return m_rotation;
	}
};