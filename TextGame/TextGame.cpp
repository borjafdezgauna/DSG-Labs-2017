// TextGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

#include "World.h"
#include "GameLogic.h"
#include "Player.h"
#include <iostream>
#include <fstream>
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
	World ourWorld(10, 10, '.');
	Player player(ourWorld, 1, 1, ourWorld.getCharPlayer1());
	Player player2(ourWorld, 2, 2, ourWorld.getCharPlayer2());
	GameLogic game(ourWorld, player,player2);

	hideCursor();

	bool gameEnded = false;

	while (!gameEnded)
	{
		ourWorld.draw();

		gameEnded= game.processInput();
	}

    return 0;
}

