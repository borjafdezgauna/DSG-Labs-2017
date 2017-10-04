#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <thread>

World::World(int sizeX, int sizeY, char defaultValue, char coinDefaultValue, char player1DefaultValue, char player2DefaultValue)
{
	//set the random seed
	int seed = (time(NULL)) % 100;
	srand(seed);

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
	playerDefaultValue1 = player1DefaultValue;
	playerDefaultValue2 = player2DefaultValue;

	addCoins(numCoins);
	m_timer.start();
	points1 = 0;
	points2 = 0;
	
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

	for (int i = 0; i < n; i++)
	{
		int posEntera = rand() % (m_sizeX*m_sizeY);
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

bool World::move(int originX, int originY, int& destX, int& destY)
{
	
	bool isMoney = false;
	char originValue= get(originX, originY);	
	char destValue = get(destX, destY);
	
	if ((originX != destX || originY != destY) && (destValue != playerDefaultValue1 && destValue != playerDefaultValue2)&&()) {
			if (destValue == m_coinDefaultValue) {
				if (originValue == playerDefaultValue1) {
					points1 ++;
				}
				else if (originValue == playerDefaultValue2) {
					points2++;
				}
			}
			set(destX, destY, originValue);
			set(originX, originY, m_defaultValue);
			
		
	}
	else {
		destX = originX;
		destY = originY;
	}

	return isMoney;;
}

void World::draw()
{
	system("cls");
	if (points1 + points2 == numCoins) {
		double time = m_timer.getElapsedTime();
		int aux;
		if (points1 < points2) {
			aux = 2;
		}
		else if(points1> points2){
			aux = 1;
		}
		else {
			aux = 0;
		}
		if (aux == 0) {
			std::cout << "\nEmpate!!!!!! \nTiempo final: " << time;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
		else {
			std::cout << "\nEnhorabuena ha ganado el Player " << aux << "!!!!!!! \nTiempo final: " << time;
			std::cout << "\nTotal monedas Player1: " << points1;
			std::cout << "\nTotal monedas Player2: " << points2;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
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
		std::cout << "Points Player1 = " << points1;
		std::cout << "\nPoints Player2 = " << points2;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));


	}


}

char World::getCharPlayer1() const
	{
		return playerDefaultValue1;
	}
char World::getCharPlayer2() const
{
	return playerDefaultValue2;
}
char World::getCharDefault() const
{
	return m_defaultValue;
}