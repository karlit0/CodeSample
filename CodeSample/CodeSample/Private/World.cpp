#include "stdafx.h"

#include "World.h"

World::World()
{
	WorldSizeX = 64;
	WorldSizeY = 32;
	WorldBufferSize = (WorldSizeX + 3) * (WorldSizeY + 2) + 1; // worldsizeX + 3 (2 for left and right border, 1 for endline), worldsizeY + 2 (2 for top and bot border), + 1 for \0
	WorldBuffer = new char[WorldBufferSize];
}

void World::Init()
{
	int worldBufferCounter = 0;

	// top border
	for (int x = 0; x < WorldSizeX + 2; x++)
	{
		WorldBuffer[worldBufferCounter] = '*';
		worldBufferCounter++;
	}
	WorldBuffer[worldBufferCounter] = '\n';
	worldBufferCounter++;

	// side borders
	for (int y = 0; y < WorldSizeY; y++)
	{
		WorldBuffer[worldBufferCounter] = '*';
		worldBufferCounter++;
		for (int x = 0; x < WorldSizeX; x++)
		{
			WorldBuffer[worldBufferCounter] = ' ';
			worldBufferCounter++;
		}
		WorldBuffer[worldBufferCounter] = '*';
		worldBufferCounter++;
		WorldBuffer[worldBufferCounter] = '\n';
		worldBufferCounter++;
	}

	// bot border
	for (int x = 0; x < WorldSizeX + 2; x++)
	{
		WorldBuffer[worldBufferCounter] = '*';
		worldBufferCounter++;
	}
	WorldBuffer[worldBufferCounter] = '\n';
	worldBufferCounter++;

	WorldBuffer[worldBufferCounter] = '\0';
	worldBufferCounter++;
}

void World::DeInit()
{
	delete WorldBuffer;
}

void World::Draw()
{
	printf("%s", WorldBuffer);
}
