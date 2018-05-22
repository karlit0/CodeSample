#pragma once

class Player;

class World
{
public:
	World();

	void Clear();

	void DeInit();

	void Update(const Player& player);

	void Draw();	

	bool IsWithinBounds(short worldPosX, short worldPosY);

private:
	short WorldSizeX;
	short WorldSizeY;

	int WorldBufferSize;
	char* WorldBuffer;

	void ConvertFromWorldPosToRawBufferPos(short worldPosX, short worldPosY, short& OUT_RawBufferPos);
	void DrawPlayer(const Player& player);
};