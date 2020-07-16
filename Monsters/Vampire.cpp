#pragma once
#include "pch.h"
#include "Vampire.h"

const string Vampire::getType()
{
	return "Vampire";
}

int Vampire::hit(Monster& opponent)
{
	int damage;
	damage = Monster::hit(opponent);
	if (opponent.getHealth() > 0 && opponent.getHealth() > 0.1*damage)
	{
		setHealth(getHealth() + (int)0.1*damage);
	}
	return damage;
}