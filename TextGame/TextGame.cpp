// TextGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#include "World.h"
#include "GameLogic.h"
#include "Player.h"
#include <windows.h>

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}


int main()
{
	World ourWorld(5, 5, '.');
	Player player(ourWorld, 1, 1, 'o');
	GameLogic game(ourWorld, player);

	hideCursor();
	int seed = (time(NULL))%100;
	srand(seed);
	bool gameEnded = false;

	while (!gameEnded)
	{
		ourWorld.draw();

		gameEnded= game.processInput();
	}

    return 0;
}

