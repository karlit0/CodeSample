#include "stdafx.h"

#include "Game.h"
#include "Windows.h"
#include "Winuser.h"
#include <chrono>

#include "World.h"
#include "Player.h"

Game GameGlobal;

Game::Game()
{
	bRunning = true;
	world = new World();
	player = new Player();
}

bool Game::MainGameLoop()
{
	if (bRunning)
	{
		WaitForFrameTime();
		
		Update();

		Render();
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

void Game::Update()
{
	UpdateInput();

	if (world && player)
	{
		world->Update(*player);
	}
}

void Game::UpdateInput()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		ExitGame();
	}
	
	if (GetAsyncKeyState(VK_UP))
	{
		if (player)
		{
			player->MoveUp();
		}
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (player)
		{
			player->MoveDown();
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (player)
		{
			player->MoveLeft();
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (player)
		{
			player->MoveRight();
		}
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
		world->Clear();
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

World* Game::GetWorld()
{
	return world;
}

Game* GetGame()
{
	return &GameGlobal;
}
