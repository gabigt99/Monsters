#pragma once
#include "Monsters.h"
#include <string>



class Knight : public Monster
{
public:
	Knight(int health = 0, int attackPower = 0, int armor = 0, const char *name = NULL, Weapon* weapon = NULL, Shield* shield = NULL) :Monster(health, attackPower, armor, name, weapon, shield) {};
	virtual const string getType(); 
	virtual bool canUseWeapon();
	virtual bool canUseShield();
	virtual ~Knight()
	{

	}
};
