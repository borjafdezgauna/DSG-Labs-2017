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
	this->m_posX = destX;
	this->m_posY = destY;

}

char Player::moveUp()
{
	if(m_posY > 0){
	this->move(m_posX,m_posY-1);
	}
}
char Player::moveDown()
{
	if (m_posY < m_world.getSizeY()) {
		this->move(m_posX, m_posY + 1);
	}

}
char Player::moveRight()
{
	if (m_posX < m_world.getSizeX()) {
		this->move(m_posX+1, m_posY);
	}

}
char Player::moveLeft()
{
	if (m_posX > 0) {
		this->move(m_posX-1, m_posY);
	}

}