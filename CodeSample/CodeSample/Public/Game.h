#pragma once

class World;
class Player;

class Game
{

public:
	Game();

	// returns bRunning
	bool MainGameLoop();

	World* GetWorld() const;

	void Init();

	void DeInit();

private:
	
	void WaitForFrameTime() const;

	void Render() const;

	void ClearScreen() const;

	void DrawWorld() const;

	void Update();	

	void UpdateInput();

	void ExitGame();


	bool bRunning;

	World* world;

	Player* player;
};

Game* GetGame();
