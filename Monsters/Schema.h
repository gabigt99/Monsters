#pragma once
#include "pch.h"
#include "Monsters.h"
//#include "DirectElemination.h" ne gi slagai, che spira da raboti
//#include "EverybodyVSeverybody.h"
#include <vector>
#include <string>

class Schema
{
public:
	virtual void getRound() = 0;
	//virtual vector<Monster*> restore(istream & in) = 0;
	virtual const string getType() = 0;
	virtual vector<Monster*> startFight(vector<Monster*> monsters, bool restoreLife, ostream* outHistory) = 0;
private:
	virtual void addWinner(int i) = 0;
};
