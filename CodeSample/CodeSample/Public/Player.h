#pragma once

class Player
{
public:
	Player();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	bool IsWithinWorldBounds(int PosX, int PosY);
	void GetPosition(short& OUT_PosX, short& OUT_PosY) const;

private:
	short PositionX;
	short PositionY;
};