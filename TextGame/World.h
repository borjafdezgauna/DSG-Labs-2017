#pragma once
#include "Timer.h"

class World
{
	char* m_pContent;
	char m_defaultValue;
	int m_sizeX, m_sizeY;
	
	int getPosInArray(int x, int y) const;

	Timer m_timer;

public:
	World(int sizeX, int sizeY, char defaultValue = ' ');
	~World();

	int getSizeX() const;
	int getSizeY() const;

	void clamp(int& x, int& y) const;

	char get(int x, int y) const;
	void set(int x, int y, char value);
	char move(int originX, int originY, int destX, int destY);
	void draw();
};