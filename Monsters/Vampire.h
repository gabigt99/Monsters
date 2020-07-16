#pragma once
#include "pch.h"
#include "Monsters.h"
#include <string>
#include<iostream> 
#include<stdio.h>
#include<stddef.h>




class Vampire : public Monster
{
public:
	Vampire(int health = 0, int attackPower = 0, int armor = 0, const char *name = NULL, Weapon * weapon = NULL, Shield* shield = NULL) :Monster(health, attackPower, armor, name, weapon, shield) {};
	virtual const string getType(); 
	virtual int hit(Monster& m);
	virtual ~Vampire()
	{

	}
};
