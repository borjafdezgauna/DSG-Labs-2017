#pragma once
class Luces
{
	static int numLuces;
	boolean isActive;
	int index;
public:
	Luces(float amb_r, float amb_g, float amb_b, float dif_r, float dif_g, float dif_b);
	~Luces();
	void cambiarActivacion();
};

