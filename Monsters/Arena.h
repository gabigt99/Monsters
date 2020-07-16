#pragma once
#include <iostream>
#include <fstream>
#include "Tournament.h"
class Arena
{
public:
	void addTournament(Tournament& tournament);
	void startTournaments();
	ostream& serializationOfTournaments(ostream& out);
	istream& deserializationOfTournaments(istream& in);
private:
	vector<Tournament*> tournaments;
};
