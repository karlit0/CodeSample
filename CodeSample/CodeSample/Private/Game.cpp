#include "stdafx.h"

#include "Game.h"
#include "Windows.h"
#include "Winuser.h"
#include <chrono>

Game::Game()
{
	bRunning = true;
	worldSizeX = 64;
	worldSizeY = 32;
	renderBufferSize = (worldSizeX + 3) * (worldSizeY + 2) + 1; // worldsizeX + 3 (2 for left and right border, 1 for endline), worldsizeY + 2 (2 for top and bot border), + 1 for \0
	renderBuffer = new char[renderBufferSize];
	renderCounter = 0;
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
	for (int i = 0; i < renderBufferSize; i++)
	{
		renderBuffer[i] = '\0';
	}
	renderCounter = 0;
}

void Game::DrawWorld()
{	
	// top border
	for (int x = 0; x < worldSizeX + 2; x++)
	{
		AddToRenderBuffer('*');
	}
	AddToRenderBuffer('\n');

	// side borders
	for (int y = 0; y < worldSizeY; y++)
	{
		AddToRenderBuffer('*');
		for (int x = 0; x < worldSizeX; x++)
		{
			AddToRenderBuffer(' ');
		}
		AddToRenderBuffer('*');
		AddToRenderBuffer('\n');
	}

	// bot border
	for (int x = 0; x < worldSizeX + 2; x++)
	{
		AddToRenderBuffer('*');
	}
	AddToRenderBuffer('\n');

	AddToRenderBuffer('\0');

	printf("%s", renderBuffer);
}

void Game::AddToRenderBuffer(char c)
{
	if (renderCounter < renderBufferSize)
	{
		renderBuffer[renderCounter] = c;
	}
	else
	{
		printf("Error!! renderCounter: %d", renderCounter);
	}
	renderCounter++;
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

}

void Game::DeInit()
{

}
