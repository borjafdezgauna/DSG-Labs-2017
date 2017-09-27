#include "stdafx.h"
#include <iostream>
#include <conio.h>

#include "GameLogic.h"
#include "World.h"
#include "Player.h"

GameLogic::GameLogic(World& world, Player& player)
	:m_world(world),m_player(player)
{

}


GameLogic::~GameLogic()
{
}

bool GameLogic::processInput()
{
	if (!kbhit()) return;

	char c = _getch();
	switch (c)
	{
	case 'w':
	case 'W':
		m_player.moveUp(); break;
	case 's':
	case 'S':
		m_player.moveDown(); break;
	case 'd':
	case 'D':
		m_player.moveRight(); break;
	case 'a':
	case 'A':
		m_player.moveLeft(); break;
	case 27:
		return true;
	}
	return false;
}