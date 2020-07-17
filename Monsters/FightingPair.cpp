#pragma once
#include "pch.h"
#include "FightingPair.h"

void FightingPair::execute(bool restoreLife) 
{
	if (restoreLife) 
	{
		int lifeRememberFirst = firstFighter->getHealth();
		int lifeRememberSecond = secondFighter->getHealth();
		winner = (*firstFighter).fight(*secondFighter);
		firstFighter->setHealth(lifeRememberFirst);
		secondFighter->setHealth(lifeRememberSecond);
	}
	else
	{
		winner = (*firstFighter).fight(*secondFighter);
	}
	executed = true;
}

FightingPair::FightingPair(Monster* first, Monster* second)
{
	firstFighter = first;
	secondFighter = second;
}

Monster* FightingPair::getWinner()
{
	if (executed)
	{
		return winner;
	}
	return nullptr;
}