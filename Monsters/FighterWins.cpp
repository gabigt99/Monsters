#pragma once
#include "pch.h"
#include "FighterWins.h"

FighterWins::FighterWins(Monster * monster)
{
	fighter = monster;
	wins = 0;
}

void FighterWins::addWin()
{
	wins++;
}

int FighterWins::returnWins()
{
	return wins;
}
