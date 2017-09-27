#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include "World.h"

Player::Player(World& world, int posX, int posY, char c)
	:m_world(world)
{
	m_posX = posX;
	m_posY = posY;

	m_world.set(posX, posY, c);


}


Player::~Player()
{
}

char Player::move(int destX, int destY)
{
	m_world.clamp(destX, destY);
	this->m_posX = destX;
	this->m_posY = destY;
}

char Player::moveUp()
{
	move(m_posX, m_posY - 1);
}

char Player::moveDown()
{
	move(m_posX, m_posY + 1);
}
char Player::moveRight()
{
	move(m_posX+1, m_posY);
}
char Player::moveLeft()
{
	move(m_posX -1, m_posY);

}