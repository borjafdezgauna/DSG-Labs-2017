#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include "World.h"

Player::Player(World& world, int posX, int posY, char c)
	:m_world(world)
{
	m_posX = std::max((int)0, std::min(world.getSizeX(), posX));
	m_posY = std::max((int)0, std::min(world.getSizeY(), posY));

	m_world.set(m_posX, m_posY, c);
}


Player::~Player()
{
}

char Player::move(int destX, int destY)
{
	m_world.clamp(destX, destY);

	char steppedOver= m_world.move(m_posX, m_posY, destX, destY);
	m_posX = destX;
	m_posY = destY;

	return steppedOver;
}

char Player::moveUp()
{
	int destX = m_posX, destY = m_posY-1;
	return move(destX, destY);
}
char Player::moveDown()
{
	int destX = m_posX, destY = m_posY + 1;
	return move(destX, destY);
}
char Player::moveRight()
{
	int destX = m_posX+1, destY = m_posY;
	return move(destX, destY);
}
char Player::moveLeft()
{
	int destX = m_posX-1, destY = m_posY;
	return move(destX, destY);
}