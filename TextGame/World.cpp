#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>

World::World(int sizeX, int sizeY, char defaultValue)
{
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	int numCeldas = sizeX*sizeY;
	m_pContent = new char[numCeldas];
	m_defaultValue = defaultValue;
}

World::~World()
{
	delete[] m_pContent;
}

int World::getPosInArray(int x, int y) const
{
	int result = x + (y*m_sizeX);
	return result;

	}


int World::getSizeX() const
{
	return m_sizeX;
}

int World::getSizeY() const
{
	return m_sizeY;
}

char World::get(int x, int y) const
{
	int pos = getPosInArray(x, y);
	return m_pContent[pos];
}

void World::set(int x, int y, char value)
{
	int pos = getPosInArray(x, y);
	m_pContent[pos] = value;
}

void World::clamp(int& x, int& y) const
{
	if (x > m_sizeX) {
		x = m_sizeX;
	}
	else if (x < 0) {
		x = 0;
	}if (y > m_sizeY) {
		y = m_sizeY;
	}
	else if (y < 0) {
		y = 0;
	}
}

char World::move(int originX, int originY, int destX, int destY)
{
	char value= get(originX, originY);
	set(destX, destY, value);
	return value;
}

void World::draw()
{
	system("cls");
	for (int j = 0; j < m_sizeY; j++) {
		for (int i = 0; i < m_sizeX; i++) {
			std::cout << get(i, j);
		}
}

}