#pragma once
#include "pch.h"
#include "Schema.h"
#include "DirectElemination.h"
#include "EverybodyVSeverybody.h"
#include "Monsters.h"
#include <vector>

using namespace std;

class Mixed: public DirectElemination, public EverybodyVSeverybody
{
public:
	virtual const string getType();
	virtual vector<Monster*> startFight(vector<Monster*> monsters, bool restoreLife, ostream* outHistory);
private:
	vector<Monster*> winners;
};