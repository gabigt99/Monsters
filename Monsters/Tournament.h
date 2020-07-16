#pragma once
#include "pch.h"
#include <iostream> 
#include <algorithm> 
#include <string>
#include <vector>
#include "Monsters.h"
#include "Weapon.h"
#include "Shield.h"
#include "Schema.h"
#include "Mixed.h"
class Tournament
{
public:
	Tournament(ostream* outHistory = NULL, bool restoreLife = 1);
	virtual const string getType();
	static Tournament* factory();
	void addFighter(Monster& newMonster);
	void addWeapon(Weapon& newWeapon);
	void addShield(Shield& newShield);
	void setIsLifeRestorable(bool restoreLife);
	void setOutHistory(ostream* outHistory);
	const bool getIsLifeRestorable();
	const ostream* getOutHistory();
	void getSchema(Schema* s);
	istream& operator>>(istream& in);
	istream& restoreOutHistory(istream& in);
	istream& restoreMonsters(istream& in);
	istream& restoreWeapons(istream& in);
	istream& restoreShields(istream& in);
	istream& restoreSchema(istream& in);
	ostream& operator<<(ostream& out);
	ostream& saveOutHistory(ostream& out);
	ostream& saveMonsters(ostream& out);
	ostream& saveWeapons(ostream& out);
	ostream& saveShields(ostream& out);
	static int sizeTournaments();
	void fight();
	void giveWeapons();
	void giveShields();
	void returnWeapons();
	void returnShields();
	void print();
private:
	Schema* schema;
	bool isLifeRestorable;
	ostream* outHistory;
	vector<FightingPair> history;
	vector<Monster*> monsters;
	vector<Monster*> winners;
	vector<Weapon*> weapons;
	vector<Shield*> shields;
};