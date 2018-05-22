#pragma once

class World;
class Player;

class Game
{

public:
	Game();

	// returns bRunning
	bool MainGameLoop();

	World* GetWorld();

	void Init();

	void DeInit();

private:
	
	void WaitForFrameTime();

	void Render();

	void ClearScreen();

	void DrawWorld();

	void Update();	

	void UpdateInput();

	void ExitGame();


	bool bRunning;

	World* world;

	Player* player;
};

Game* GetGame();
