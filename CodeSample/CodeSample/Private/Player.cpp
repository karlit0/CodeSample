#include "stdafx.h"

#include "Player.h"
#include "Game.h"
#include "World.h"

Player::Player()
{
	PositionX = 0;
	PositionY = 0;
}

void Player::MoveUp()
{
	if (IsWithinWorldBounds(PositionX, PositionY - 1))
	{
		PositionY--;
	}
}

void Player::MoveDown()
{
	if (IsWithinWorldBounds(PositionX, PositionY + 1))
	{
		PositionY++;
	}
}

void Player::MoveLeft()
{
	if (IsWithinWorldBounds(PositionX - 1, PositionY))
	{
		PositionX--;
	}
}

void Player::MoveRight()
{
	if (IsWithinWorldBounds(PositionX + 1, PositionY))
	{
		PositionX++;
	}
}

bool Player::IsWithinWorldBounds(int PosX, int PosY)
{
	bool bRet = false;

	if (GetGame())
	{
		if (GetGame()->GetWorld())
		{
			bRet = (GetGame()->GetWorld()->IsWithinBounds(PosX, PosY));
		}
		else
		{
			printf("Error!! world NULL, IsWithinWorldBounds");
		}
	}
	else
	{
		printf("Error!! game NULL, IsWithinWorldBounds");
	}
	
	return bRet;
}

void Player::GetPosition(short& OUT_PosX, short& OUT_PosY) const
{
	OUT_PosX = PositionX;
	OUT_PosY = PositionY;
}
