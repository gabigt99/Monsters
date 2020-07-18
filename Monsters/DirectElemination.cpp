#pragma once
#include"pch.h"
#include "DirectElemination.h"

vector<Monster*> DirectElemination::startFight(vector<Monster*> monsters, bool restoreLife , ostream* outHistory)
{
	int numberOfRound = 0;
	fighters = monsters;
	if (fighters.size() == 1)
	{
		winners = fighters;
	}
	while (fighters.size() != 1)
	{
		numberOfRound++;
		getRound();
		if (fighters.size() % 2 != 0)
		{
			winners.push_back(fighters[fighters.size() - 1]);
		}
		fight(restoreLife, outHistory, numberOfRound);
		fighters = winners;
		for (unsigned int i = 0; i < winners.size(); i++) // това е, за да се вид€, че работи адекватно, иначе не ни тр€бва
		{
			winners[i]->print();
		}
	}
	return winners;
}

void DirectElemination::getRound()
{
	pairs.clear();
	winners.clear();
	cout << "==========ROUND===============" << endl;//за прегледност на конзолата
	for (unsigned int i = 0; i < fighters.size() - 1; i = i + 2)
	{
		FightingPair pair;
		pair.firstFighter = fighters[i];
		pair.secondFighter = fighters[i + 1];
		pairs.push_back(pair);
	}
}


/*void DirectElemination::save(ostream & out)
{
	out << winners.size() << endl;
	for (unsigned int i = 0; i < winners.size(); i++)
	{
		winners[i]->save(out);
		out << winners[i]->isHaveWeapon() << " ";
		if (winners[i]->isHaveWeapon())
		{
			out << winners[i]->getWeapon()->getPower() << " "
				<< winners[i]->getWeapon()->getDupability() << " ";
		}
		out << winners[i]->isHaveShield() << " ";
		if (winners[i]->isHaveShield())
		{
			out << winners[i]->getShield()->getProtection() << " "
				<< winners[i]->getShield()->getDupability() << " ";
		}
	}
}*/

/*vector<Monster*> DirectElemination::restore(istream & in)
{
	int size;
	string type;
	bool isThereWeapon;
	bool isThereShield;
	in >> size;
	for (int i = 0; i < size; i++)
	{
		in >> type;
		fighters.push_back(Monster::factory(type));
		fighters[i]->read(in);
		in >> isThereWeapon;
		if (isThereWeapon)
		{
			fighters[i]->restoreWeapon(in);
		}
		in >> isThereShield;
		if (isThereShield)
		{
			fighters[i]->restoreShield(in);
		}
	}
	return fighters;
}*/

const string DirectElemination::getType()
{
	return "DirectElemination";
}

void DirectElemination::fight(bool restoreLife, ostream * outHistory, int numberOfRound)
{
	if (outHistory != nullptr)
	{
		*outHistory << "==========ROUND" << numberOfRound << "=============" << endl;
	}
	for (unsigned int i = 0; i < pairs.size(); i++)
	{
		pairs[i].execute(restoreLife);
		addWinner(i);
		saveInHistory(outHistory, i);
	}
}

void DirectElemination::addWinner(int index)
{
	if (pairs[index].executed == true)
	{
		Monster* winner = pairs[index].getWinner();
		if (winner == nullptr)
		{
			if (rand() % 2 == 0)
			{
				winners.push_back(pairs[index].firstFighter);
			}
			else
			{
				winners.push_back(pairs[index].secondFighter);
			}
		}
		else
		{
			winners.push_back(winner);
		}
	}
}

void DirectElemination::saveInHistory(ostream * outHistory, size_t numberOfPair)
{
	if (outHistory != nullptr)
	{
		*outHistory << "Pair " << numberOfPair << " is: "
			<< pairs[numberOfPair].firstFighter->getName() << " & " 
			<< pairs[numberOfPair].secondFighter->getName() << endl;
		*outHistory << "Winner is: " << winners.back()->getName() << endl;
	}
}
