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
	World ourWorld("file.csv");
	Player player(ourWorld, ourWorld.getP1X(), ourWorld.getP1Y(), ourWorld.getCharPlayer1());
	Player player2(ourWorld, ourWorld.getP2X(), ourWorld.getP2Y(), ourWorld.getCharPlayer2());
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

