#pragma once

class World;

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

	void UpdateInput();

	void ExitGame();

	void Init();

	void DeInit();

private:
	bool bRunning;

	World* world;
};