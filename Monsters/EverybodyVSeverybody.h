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
	virtual void getRound();
	virtual const string getType();
private:
	vector<Monster*> fighters;
	vector<Monster*> winners;
	vector<FightingPair> pairs;
	vector<FighterWins> fighersWithWins;
	void makeFighterWinnsCounter();
	void fight(bool restoreLife, ostream* outHistory);
	virtual void addWinner(int index);
	virtual void saveInHistory(ostream* outHistory, size_t numberOfPair);
	void addWins();
	int mostWins();
	void winnersWithMostWins();
};
