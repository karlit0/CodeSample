// CodeSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Game.h"

int main()
{
	Game* game = GetGame();

	if (game)
	{
		game->Init();
		bool bRunning = true;
		while (bRunning)
		{
			bRunning = game->MainGameLoop();
		}
		game->DeInit();
	}
	else
	{
		printf("Error! Failed to initialize Game, main()");
	}

    return 0;
}

