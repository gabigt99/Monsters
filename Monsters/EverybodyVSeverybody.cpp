#pragma once
#include"pch.h"
#include "EverybodyVSeverybody.h"


vector<Monster*> EverybodyVSeverybody::startFight(vector<Monster*> monsters, bool restoreLife, ostream* outHistory)
{
	fighters = monsters;
	makeFighterWinnsCounter();
	getRound();
	fight(restoreLife, outHistory);
	addWins();
	winners.clear();
	winnersWithMostWins();
	for (unsigned int i = 0; i < winners.size(); i++)//да се види на конзолата кой продължава, но иначе не е нужно(за удобство)
	{
		winners[i]->print();
	}
	return winners;
}

void EverybodyVSeverybody::makeFighterWinnsCounter()
{
	for (unsigned int i = 0; i < fighters.size(); i++)
	{
		FighterWins fighter(fighters[i]);
		fighersWithWins.push_back(fighter);
	}
}

void EverybodyVSeverybody::getRound()
{
	cout << "==========ROUND===============" << endl;//за удобство, иначе не трябва да го има
	for (unsigned int i = 0; i < fighters.size() - 1; i++)
	{
		for (unsigned int j = i + 1; j < fighters.size(); j++)
		{
			FightingPair pair;
			pair.firstFighter = fighters[i];
			pair.secondFighter = fighters[j];
			pairs.push_back(pair);
		}
	}
}

const string EverybodyVSeverybody::getType()
{
	return "EverybodyVSeverybody";
}

void EverybodyVSeverybody::addWinner(int index)
{
	if (pairs[index].executed == true && pairs[index].getWinner() != nullptr)
	{
		Monster* winner = pairs[index].getWinner();
		winners.push_back(winner);
	}
}

void EverybodyVSeverybody::addWins()
{
	for (unsigned int i = 0; i < winners.size(); i++)
	{
		for (unsigned int j = 0; j < fighersWithWins.size(); j++)
		{
			if (winners[i] == fighersWithWins[j].fighter)
			{
				fighersWithWins[j].addWin();
			}
		}
	}
}

int EverybodyVSeverybody::mostWins()
{
	int mostWins = fighersWithWins[0].returnWins();
	for (unsigned int i = 1; i < fighersWithWins.size(); i++)
	{
		if (fighersWithWins[i].returnWins() > mostWins)
		{
			mostWins = fighersWithWins[i].returnWins();
		}
	}
	return mostWins;
}

void EverybodyVSeverybody::winnersWithMostWins()
{
	int bestScore = mostWins();
	for (unsigned int i = 0; i < fighersWithWins.size(); i++)
	{
		if (fighersWithWins[i].returnWins() == bestScore)
		{
			winners.push_back(fighersWithWins[i].fighter);
		}
	}
}

void EverybodyVSeverybody::fight(bool restoreLife, ostream * outHistory)
{
	for (unsigned int i = 0; i < pairs.size(); i++)
	{
		if (outHistory != nullptr)
		{
			*outHistory << "Pair " << i << " is: " << pairs[i].firstFighter->getName() << " & " << pairs[i].secondFighter->getName() << endl;
		}
		pairs[i].execute(restoreLife);
		addWinner(i);
		if (outHistory != nullptr)
		{
			if (pairs[i].getWinner() == nullptr)
			{
				*outHistory << "Winner is: " << "No one" << endl;
			}
			else
			{
				*outHistory << "Winner is: " << winners.back()->getName() << endl;
			}
		}
	}
}