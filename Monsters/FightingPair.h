#pragma once
#include<iostream>
#include"Monsters.h"

using namespace std;

struct FightingPair
{
	Monster* firstFighter;
	Monster* secondFighter;
	bool executed;
	Monster* winner;
	FightingPair() {}
	FightingPair(Monster* first, Monster* second);
	Monster* getWinner();
	void execute(bool restoreLife);
};
