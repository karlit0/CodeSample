#include "stdafx.h"

#include "Game.h"
#include "Windows.h"
#include "Winuser.h"
#include <chrono>

#include "World.h"

Game::Game()
{
	bRunning = true;
	world = new World();
}

bool Game::MainGameLoop()
{
	if (bRunning)
	{
		WaitForFrameTime();

		Render();

		UpdateInput();
	}

	return bRunning;
}

void Game::WaitForFrameTime()
{
	std::chrono::time_point<std::chrono::steady_clock> timeStart = std::chrono::steady_clock::now();
	
	int frameRate = 30;
	double timestepMilli = (1.0 / static_cast<double>(frameRate)) * 1000.0;

	std::chrono::duration<double, std::milli> fp_ms;

	do
	{
		std::chrono::time_point<std::chrono::steady_clock> timeNow = std::chrono::steady_clock::now();

		fp_ms = timeNow - timeStart;

	} while (fp_ms.count() < timestepMilli);
}

void Game::Render()
{
	ClearScreen();
	DrawWorld();
}

void Game::ClearScreen()
{	
	system("CLS");
}

void Game::DrawWorld()
{	
	if (world)
	{
		world->Draw();
	}
}

void Game::UpdateInput()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		ExitGame();
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		printf("LEFT");
	}
}

void Game::ExitGame()
{
	bRunning = false;
}

void Game::Init()
{
	if (world)
	{
		world->Init();
	}
	else
	{
		printf("Error!! Game::Init, world NULL");
	}
}

void Game::DeInit()
{
	if (world)
	{
		world->DeInit();
	}
}
