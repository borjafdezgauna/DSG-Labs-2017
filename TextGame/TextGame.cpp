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
	std::ifstream file("file.csv");
	std::string value;
	int x, y;
	char c[2];
	int i = 0;
	while (file.good())
	{
		getline(file, value, ','); 
		if (i == 0) 
		{
			x = std::stoi(value);
		}
		else if (i==1)
		{
			y = std::stoi(value);
		}
		else if(i==2)
		{
			strcpy_s(c, value.c_str());
		}
		i++;
	}
	World ourWorld(x, y, c[0]);
	Player player(ourWorld, 2, 6, 'o');
	GameLogic game(ourWorld, player);

	hideCursor();

	bool gameEnded = false;

	while (!gameEnded)
	{
		ourWorld.draw();

		gameEnded= game.processInput();
	}

    return 0;
}

