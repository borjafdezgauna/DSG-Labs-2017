#pragma once
#include "Timer.h"

class World
{
	//un caracter por cada casilla. Se inicializa en el constructor
	char* m_pContent;
	//el valor con el que inicializaremos cada casilla
	char m_defaultValue;
	//valor de la moneda
	char m_coinDefaultValue;
	//tamaño del mapa en x e y
	int m_sizeX, m_sizeY;
	
	int numCeldas;
	

	int getPosInArray(int x, int y) const;

	Timer m_timer;

public:
	World(int sizeX, int sizeY, char defaultValue = ' ', char coinDefaultValue = '?', char player1DefaultValue='o', char player2DefaultValue = 'x');
	//liberar la memoria reservada en el constructor
	~World();
	int points1;
	char playerDefaultValue1;
	char playerDefaultValue2;
	int points2;
	int numCoins;
	int getSizeX() const;
	int getSizeY() const;

	//se asegura de que x e y están en rango
	void clamp(int& x, int& y) const;

	void addCoins(int n);
	char get(int x, int y) const;
	void set(int x, int y, char value);
	bool move(int originX, int originY, int& destX, int& destY);
	//dibujar el mapa
	void draw();
	char getCharPlayer1() const;
	char getCharPlayer2() const;
	char getCharDefault() const;
	
};