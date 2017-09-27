#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>

World::World(int sizeX, int sizeY, char defaultValue, char coinDefaultValue)
{
	
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	numCeldas = sizeX*sizeY;
	numCoins = numCeldas / 10;
	m_pContent = new char[numCeldas];
	for (int i = 0; i < numCeldas; i++) {
		m_pContent[i] = defaultValue;
	}
	m_defaultValue = defaultValue;
	m_coinDefaultValue = coinDefaultValue;
	addCoins(numCoins);
	m_timer.start();
	points = 0;
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

void World::addCoins(int n)
{
	double pos=0;

	for (int i = 0; i < n; i++) {
		pos =(double)rand() / RAND_MAX;
		int posEntera = (int) (pos * (m_sizeX*m_sizeY));
		if (m_pContent[posEntera] == m_defaultValue)
		{
		m_pContent[posEntera] = m_coinDefaultValue;

		}
		else
		{
			i--;
		}
		}
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
	if (x >m_sizeX-1) {
		x = m_sizeX-1;
	}
	else if (x < 0) {
		x = 0;
	}
	if (y > m_sizeY-1) {
		y = m_sizeY-1;
	}
	else if (y < 0) {
		y = 0;
	}
}

char World::move(int originX, int originY, int destX, int destY)
{
	

	char originValue= get(originX, originY);	
	char destValue = get(destX, destY);
	
	if (originX != destX || originY != destY) {
		if (destValue == m_coinDefaultValue) {
			points=points+1;
		}
		
		set(destX, destY, originValue);
		set(originX, originY, m_defaultValue);
	}
	return originValue;
}

void World::draw()
{
	system("cls");
	if (points == numCoins) {
		double time = m_timer.getElapsedTime();
		
		std::cout << "\nEnhorabuena has ganado!!!!!!! \nTiempo final: " << time;
		std::cout << "\nTotal monedas: " << points;
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	}
	else {

		for (int a = 0; a < m_sizeX + 2; a++) {
			std::cout << "*";
		}
		std::cout << "\n";
		for (int j = 0; j < m_sizeY; j++) {
			std::cout << "*";
			for (int i = 0; i < m_sizeX; i++) {
				std::cout << get(i, j);
			}
			std::cout << "*\n";
		}
		for (int b = 0; b < m_sizeX + 2; b++) {
			std::cout << "*";

		}

		std::cout << std::fixed;
		std::cout.precision(2);
		std::cout << "\nTime = " << m_timer.getElapsedTime() << " \n";
		std::cout << "Points = " << points;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));


	}


}