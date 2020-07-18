#pragma once
#include"pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Schema.h"
#include "Monsters.h"
#include "FightingPair.h"


using namespace std;

class DirectElemination : public Schema
{
public:
	virtual vector<Monster*> startFight(vector<Monster*> monsters, bool restoreLife, ostream* outHistory);
	virtual void getRound();
	//virtual void save(ostream& out);
	//virtual vector<Monster*> restore(istream& in);
	virtual const string getType();
private:
	vector<Monster*> fighters;
	vector<Monster*> winners;
	vector<FightingPair> pairs;
	void fight(bool restoreLife, ostream* outHistory, int numberOfRound);
	virtual void addWinner(int index);
	virtual void saveInHistory(ostream* outHistory, size_t numberOfPair);
};