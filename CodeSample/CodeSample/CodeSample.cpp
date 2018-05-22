// CodeSample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Game.h"

int main()
{
	Game* game = new Game();

	if (game)
	{
		game->Init();
		bool bRunning = true;
		while (bRunning)
		{
			bRunning = game->MainGameLoop();
		}
		game->DeInit();
		delete game;
	}
	else
	{
		printf("Error! Failed to initialize Game, main()");
	}

    return 0;
}

