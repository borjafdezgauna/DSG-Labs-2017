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
	m_defaultValue = defaultValue;
	m_pContent = new char[sizeX * sizeY];
	for (int i = 0; i < sizeX*sizeY; ++i) m_pContent[i] = defaultValue;

	m_timer.start();
}

World::~World()
{
	delete[] m_pContent;
}

int World::getPosInArray(int x, int y) const
{
	return x + y*m_sizeX;
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
	return m_pContent[getPosInArray(x, y)];
}

void World::set(int x, int y, char value)
{
	m_pContent[getPosInArray(x, y)] = value;
}

void World::clamp(int& x, int& y) const
{
	x = std::max((int)0, std::min(m_sizeX-1, x));
	y = std::max((int)0, std::min(m_sizeY-1, y));
}

char World::move(int originX, int originY, int destX, int destY)
{
	int originPosInArray = getPosInArray(originX, originY);
	int destPosInArray = getPosInArray(destX, destY);
	char steppedOver = m_pContent[originPosInArray];
	if (originPosInArray != destPosInArray)
	{
		m_pContent[destPosInArray] = m_pContent[originPosInArray];
		m_pContent[originPosInArray] = m_defaultValue;
	}
	return steppedOver;
}

void World::draw()
{
	//clear the console window
	system("cls");
	//draw the wall separating the real from the wildlings
	for (int i = 0; i < m_sizeX + 2; ++i)
		std::cout << "#";
	std::cout << "\n";
	for (int row = 0; row < m_sizeY; ++row)
	{
		std::cout << "#";
		for (int column = 0; column < m_sizeX; ++column)
		{
			std::cout << get(column, row);
		}
		std::cout << "#\n";
	}
	//draw the south wall
	for (int i = 0; i < m_sizeX + 2; ++i)
		std::cout << "#";
	std::cout << "\n";

	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << "Time= " << m_timer.getElapsedTime() << "\n";
	std::cout << "Points= " << 0;

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}