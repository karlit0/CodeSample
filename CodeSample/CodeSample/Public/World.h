#pragma once

class World
{
public:
	World();

	void Init();

	void DeInit();

	void Draw();

private:
	short WorldSizeX;
	short WorldSizeY;

	int WorldBufferSize;
	char* WorldBuffer;
};