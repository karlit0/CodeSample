#include "stdafx.h"

#include "World.h"
#include "Player.h"

World::World()
{
	WorldSizeX = 64;
	WorldSizeY = 32;
	WorldBufferSize = (WorldSizeX + 3) * (WorldSizeY + 2) + 1; // worldsizeX + 3 (2 for left and right border, 1 for endline), worldsizeY + 2 (2 for top and bot border), + 1 for \0
	WorldBuffer = new char[WorldBufferSize];
}

void World::Clear()
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

void World::Update(const Player& player)
{	
	Clear();

	PlacePlayer(player);
}

void World::Draw()
{
	printf("%s", WorldBuffer);
}
void World::ConvertFromWorldPosToRawBufferPos(short worldPosX, short worldPosY, short& OUT_RawBufferPos)
{
	OUT_RawBufferPos = (worldPosY + 1) * (WorldSizeX + 3) + (worldPosX + 1);
}

void World::PlacePlayer(const Player& player)
{
	short playerPosX = 0;
	short playerPosY = 0;
	player.GetPosition(playerPosX, playerPosY);
	short rawBufPos = 0;
	ConvertFromWorldPosToRawBufferPos(playerPosX, playerPosY, rawBufPos);
	WorldBuffer[rawBufPos] = '@';
}

bool World::IsWithinBounds(short worldPosX, short worldPosY)
{
	if (worldPosX >= 0 && worldPosX < WorldSizeX
		&& worldPosY >= 0 && worldPosY < WorldSizeY)
	{
		return true;
	}
	else
	{
		return false;
	}
}
