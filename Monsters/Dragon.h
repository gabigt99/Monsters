#pragma once
#include "pch.h"
#include "Monsters.h"
#include "Weapon.h"
#include "Shield.h"
#include <string>
#include<iostream> 
#include<stdio.h>
#include<stddef.h>
#include<string.h>


class Dragon : public Monster
{
public:
	Dragon(int health = 0, int attackPower = 0, int armor = 0, const char *name = NULL, Weapon* weapon = NULL, Shield* shield = NULL) :Monster(health, attackPower, armor, name, weapon, shield) {};
	virtual const int getAttackPower();
	virtual const int getArmor();
	virtual const string getType();
	virtual bool canUseWeapon();
	virtual bool canUseShield();
	virtual ~Dragon();
};


