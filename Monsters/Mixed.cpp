#pragma once
#include "pch.h"
#include "Mixed.h"

const string Mixed::getType()
{
	return "Mixed";
}

vector<Monster*> Mixed::startFight(vector<Monster*> monsters, bool restoreLife, ostream* outHistory)
{
	winners = EverybodyVSeverybody::startFight(monsters, restoreLife, outHistory);
	/*for (unsigned int i = 0; i < winners.size(); i++)
	{
		cout << 2;
		winners[i]->print();
	}*/
	return DirectElemination::startFight(winners, restoreLife, outHistory);
}
