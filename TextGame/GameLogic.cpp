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

}