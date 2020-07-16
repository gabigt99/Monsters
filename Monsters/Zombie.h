#pragma once
#include "pch.h"
#include "Monsters.h"
#include <string>
#include <iostream> 
#include <stdio.h>
#include <stddef.h>
#include <string.h>


class Zombie : public Monster
{
public:
	Zombie(int health = 0, int attackPower = 0, int armor = 0, const char *name = NULL, Weapon* weapon = NULL, Shield* shield = NULL) :Monster(health, attackPower, armor, name, weapon, shield) {};
	virtual void setHealth(int health);
	virtual const string getType();
	virtual bool isAlive();
	virtual ~Zombie()
	{

	}
};
