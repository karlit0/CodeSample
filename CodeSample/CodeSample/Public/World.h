#pragma once

class Player;

class World
{
public:
	World();

	void Clear();

	void DeInit();

	void Update(const Player& player);

	void Draw() const;	

	bool IsWithinBounds(short worldPosX, short worldPosY) const;

private:
	short WorldSizeX;
	short WorldSizeY;

	int WorldBufferSize;
	char* WorldBuffer;

	void ConvertFromWorldPosToRawBufferPos(short worldPosX, short worldPosY, short& OUT_RawBufferPos) const;
	void PlacePlayer(const Player& player);
};