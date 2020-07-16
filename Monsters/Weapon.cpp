#pragma once
#include "pch.h"
#include "Weapon.h"
void Weapon::setPower(int newPower)
{
	if (newPower < 0)
	{
		newPower = 0;
	}
	this->power = newPower;
}
void Weapon::setDupability(int newDupability)
{
	if (newDupability < 0)
	{
		newDupability = 0;
	}
	this->dupability = newDupability;
}


void Weapon::setIsTaken(bool isTaken)
{
	if (this != NULL)
	{
		this->isTaken = isTaken;
	}
}
int Weapon::getPower()
{
	return power;
}
int Weapon::getDupability()
{
	return dupability;
}


bool Weapon::getIsTaken()
{
	return this->isTaken;
}

const string Weapon::getType()
{
	return "Weapon";
}

Weapon * Weapon::factory(string type)//за лесно добавяне на различни видове
{
	if (type == "Weapon")
	{
		return new Weapon(0, 0);
	}
	return nullptr;
}

void Weapon::read(istream & in)
{
	int power, dupability;
	in >> power >> dupability;
	setPower(power);
	setDupability(dupability);
}

void Weapon::save(ostream & out)
{
	out << getType() << " ";
	out << getPower() << " " << getDupability() << endl;
}

bool Weapon::isUseable()
{
	return (getDupability() > 0);
}
bool Weapon::canBeTaken()
{
	return getDupability() > 0 && !getIsTaken();
}