#pragma once
#include"pch.h"
#include "Schema.h"
#include "Monsters.h"
#include "FightingPair.h"
#include "FighterWins.h"
#include <vector>

class EverybodyVSeverybody : public Schema
{
public:
	virtual vector<Monster*> startFight(vector<Monster*> monsters, bool restoreLife, ostream* outHistory);
	void makeFighterWinnsCounter();
	virtual void getRound();
	virtual const string getType();
	virtual void addWinner(int i);
	void addWins();
	int mostWins();
	void winnersWithMostWins();
private:
	vector<Monster*> fighters;
	vector<Monster*> winners;
	vector<FightingPair> pairs;
	vector<FighterWins> fighersWithWins;
	void fight(bool restoreLife, ostream* outHistory);
};
