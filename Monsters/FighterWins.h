#pragma once
#include "pch.h"
#include "Monsters.h"

struct FighterWins
{
	FighterWins(Monster* monster);
	void addWin();
	int returnWins();
	Monster* fighter;
private:
	int wins;
};