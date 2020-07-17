#pragma once
#include"pch.h"
#include "Tournament.h"
#include <string>

Tournament::Tournament(ostream* outHistory, bool isLifeRestorable)
{
	schema = nullptr;
	this->outHistory = outHistory;
	this->isLifeRestorable = isLifeRestorable;
}

const string Tournament::getType()
{
	return "Tournament";
}

Tournament * Tournament::factory()//евентуално за повече видове турнири
{
	return new Tournament();
}

void Tournament::addFighter(Monster& fighter)
{
	monsters.push_back(&fighter);
}

void Tournament::addWeapon(Weapon& weapon)
{
	weapons.push_back(&weapon);
}

void Tournament::addShield(Shield& shield)
{
	shields.push_back(&shield);
}

void Tournament::setIsLifeRestorable(bool isLifeRestorable)
{
	this->isLifeRestorable = isLifeRestorable;
}

void Tournament::setOutHistory(ostream * outHistory)
{
	this->outHistory = outHistory;
}

const bool Tournament::getIsLifeRestorable()
{
	return isLifeRestorable;
}

const ostream * Tournament::getOutHistory()
{
	return outHistory;
}

void Tournament::getSchema(Schema* schema)
{
	this->schema = schema;
}

istream& Tournament::operator>>(istream& in)
{
	restoreOutHistory(in);
	in >> isLifeRestorable;
	restoreMonsters(in);
	restoreWeapons(in);
	restoreShields(in);
	restoreSchema(in);
	return in;
}

istream & Tournament::restoreOutHistory(istream & in)
{
	bool isHaveHistory;
	in >> isHaveHistory;
	if (isHaveHistory)
	{
		string filename;
		in >> filename;
		ofstream* out = new ofstream(filename);
		setOutHistory(out);
	}
	else
	{
		setOutHistory(nullptr);
	}
	return in;
}

istream & Tournament::restoreMonsters(istream & in)
{
	string type;
	size_t sizeOfMonsters;
	in >> sizeOfMonsters;
	sizeOfMonsters = monsters.size() + sizeOfMonsters;
	for (size_t i = monsters.size(); i < sizeOfMonsters; i++)
	{
		in >> type;
		monsters.push_back(Monster::factory(type));
		monsters[i]->read(in);
	}
	return in;
}

istream& Tournament::restoreWeapons(istream& in)
{
	string type;
	size_t sizeOfWeapons;
	in >> sizeOfWeapons;
	for (int i = 0; i < sizeOfWeapons; i++)
	{
		in >> type;
		weapons.push_back(Weapon::factory(type));
		weapons[i]->read(in);
	}
	return in;
}

istream& Tournament::restoreShields(istream & in)
{
	string type;
	size_t sizeOfShields;
	in >> sizeOfShields;
	for (int i = 0; i < sizeOfShields; i++)
	{
		in >> type;
		shields.push_back(Shield::factory(type));
		shields[i]->read(in);
	}
	return in;
}

istream& Tournament::restoreSchema(istream& in)//би трябвало да е class Schema, но не работи
{
	string type;
	in >> type;
	if (type == "DirectElemination")
	{
		DirectElemination *schema = new DirectElemination;
		this->schema = schema;
	}
	else if (type == "EverybodyVSeverybody")
	{
		EverybodyVSeverybody *schema = new EverybodyVSeverybody;
		this->schema = schema;
	}
	else if (type == "Mixed")
	{
		Mixed* schema = new Mixed;
		this->schema = static_cast <EverybodyVSeverybody*> (schema);
	}
	else
	{
		schema = nullptr;
	}
	return in;
}

ostream& Tournament::operator<<(ostream& out)
{
	saveOutHistory(out);
	out << isLifeRestorable << endl;
	saveMonsters(out);
	saveWeapons(out);
	saveShields(out);
	out << schema->getType() << endl;
	return out;
}

ostream & Tournament::saveOutHistory(ostream & out)
{
	if (getOutHistory() != nullptr)
	{
		out << true << " " << "Tournament" << sizeTournaments() << endl;
	}
	else
	{
		out << false << endl;
	}
	return out;
}

ostream & Tournament::saveMonsters(ostream & out)
{
	out << monsters.size() << endl;
	for (unsigned int i = 0; i < monsters.size(); i++)
	{
		monsters[i]->save(out);
	}
	return out;
}

ostream & Tournament::saveWeapons(ostream & out)
{
	out << weapons.size() << endl;
	for (unsigned int i = 0; i < weapons.size(); i++)
	{
		weapons[i]->save(out);
	}
	return out;
}

ostream & Tournament::saveShields(ostream & out)
{
	out << shields.size() << endl;
	for (unsigned int i = 0; i < shields.size(); i++)
	{
		shields[i]->save(out);
	}
	return out;
}

int Tournament::sizeTournaments()
{
	static int sizeTournaments = 0;
	sizeTournaments++;
	return sizeTournaments;
}

void Tournament::fight()
{
	if (schema != nullptr)
	{
		giveWeapons();
		giveShields();
		for (unsigned int i = 0; i < monsters.size(); i++)
		{
			monsters[i]->print();
		}
		winners = schema->startFight(monsters, isLifeRestorable, outHistory);
		returnWeapons();
		returnShields();
	}
	else
	{
		cout << "It doesn't know which schema to use!!!" << endl;
	}
}

void Tournament::giveWeapons()
{
	random_shuffle(monsters.begin(), monsters.end());
	random_shuffle(weapons.begin(), weapons.end());
	size_t size = monsters.size() < weapons.size() ? monsters.size() : weapons.size();
	for (int i = 0; i < size; i++)
	{
		monsters[i]->takeWeapon(weapons[i]);
	}
}

void Tournament::giveShields()
{
	random_shuffle(monsters.begin(), monsters.end());
	random_shuffle(shields.begin(), shields.end());
	size_t size = monsters.size() < shields.size() ? monsters.size() : shields.size();
	for (int i = 0; i < size; i++)
	{
		monsters[i]->takeShield(shields[i]);
	}
}

void Tournament::returnWeapons()
{
	for (unsigned int i = 0; i < monsters.size(); i++)
	{
		monsters[i]->returnWeapon();
	}
}

void Tournament::returnShields()
{
	for (unsigned int i = 0; i < monsters.size(); i++)
	{
		monsters[i]->returnShield();
	}
}

void Tournament::print()
{
	for (unsigned int i = 0; i < winners.size(); i++)
	{
		winners[i]->print();
	}
}
