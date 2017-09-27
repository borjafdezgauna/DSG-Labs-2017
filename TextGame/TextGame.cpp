// TextGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#include "World.h"
#include "GameLogic.h"
#include "Player.h"

int main()
{
	World ourWorld(20, 20, '.');
	Player player(ourWorld, 2, 6, 'o');
	GameLogic game(ourWorld, player);

	bool gameEnded = false;

	while (!gameEnded)
	{
		ourWorld.draw();

		gameEnded= game.processInput();
	}

    return 0;
}

