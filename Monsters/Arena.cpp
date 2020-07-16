#pragma once
#include "pch.h"
#include "Arena.h"

void Arena::addTournament(Tournament& tournament)
{
	tournaments.push_back(&tournament);
}

void Arena::startTournaments()
{
	for (size_t i = 0; i < tournaments.size(); i++)
	{
		cout << "=====================Tour======================" << endl;//на конзолата да се виждат ясно различните турнири
		tournaments[i]->fight();
	}
}

ostream & Arena::serializationOfTournaments(ostream & out)
{
	out << tournaments.size() << endl;
	for (unsigned int i = 0; i < tournaments.size(); i++)
	{
		out << tournaments[i];
		//tournaments[i]->operator<<(out);
	}
	return out;
}

istream & Arena::deserializationOfTournaments(istream & in)
{
	int size;
	in >> size;
	for (int i = 0; i < size; i++)
	{
		tournaments.push_back(Tournament::factory());
		tournaments[i]->operator>>(in);
	}
	return in;
}

