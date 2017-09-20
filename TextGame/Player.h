#pragma once

class World;

class Player
{
	World& m_world;
	int m_posX, m_posY;

	char move(int destX, int destY);
public:
	Player() = default;
	Player(World& world, int posX, int posY, char c);
	~Player();

	char moveUp();
	char moveDown();
	char moveRight();
	char moveLeft();
};

