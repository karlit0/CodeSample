#pragma once

class Game
{

public:
	Game();

	// returns bRunning
	bool MainGameLoop();

	void WaitForFrameTime();

	void Render();

	void ClearScreen();

	void DrawWorld();

	void AddToRenderBuffer(char c);

	void UpdateInput();

	void ExitGame();

	void Init();

	void DeInit();

private:
	bool bRunning;

	short worldSizeX;
	short worldSizeY;

	int renderBufferSize;
	char* renderBuffer;
	int renderCounter;

};