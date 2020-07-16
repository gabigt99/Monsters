#pragma once
#include "pch.h"
#include "Monsters.h"
#include "Knight.h"

const string Knight::getType()
{
	return "Knight";
}

bool Knight::canUseWeapon()
{
	if (this->weapon == NULL)
	{
		return false;
	}
	return 1;
}
bool Knight::canUseShield()
{
	if (this->shield == NULL)
	{
		return false;
	}
	return 1;
}
