#pragma once
#include "pch.h"
#include "Zombie.h"
void Zombie::setHealth(int health)
{
	if (health < -20)
	{
		health = -20;
	}
	this->health = health;
}

const string Zombie::getType()
{
	return "Zombie";
}

bool Zombie::isAlive()
{
	return this->getHealth() > -20;
}
