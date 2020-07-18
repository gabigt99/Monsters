#pragma once
#include "pch.h"
#include "Dragon.h"

const int Dragon::getAttackPower()
{
	if (rand() % 8 == 0)
	{
		return this->Monster::getAttackPower() + 20;
	}
	return this->Monster::getAttackPower();
}

const int Dragon::getArmor()
{
	if (rand() % 8 == 0)
	{
		return 100000;
	}
	return this->Monster::getArmor();
}

const string Dragon::getType()
{
	return "Dragon";
}

bool Dragon::canUseWeapon()
{
	return 0;
}

bool Dragon::canUseShield()
{
	return 0;
}

Dragon::~Dragon()
{

}