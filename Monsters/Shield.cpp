#pragma once
#include"pch.h"
#include "Shield.h"

void Shield::setProtection(int protection)
{
	if (protection < 0)
	{
		protection = 0;
	}
	this->protection = protection;
}

void Shield::setDupability(int dupability)
{
	if (dupability < 0)
	{
		dupability = 0;
	}
	this->dupability = dupability;
}

void Shield::setIsTaken(bool isTaken)
{
	if (this != NULL)
	{
		this->isTaken = isTaken;
	}
}

int Shield::getProtection()
{
	return this->protection;
}

Shield * Shield::factory(string type)
{
	if (type == "Shield")
	{
		return new Shield(0, 0);
	}
	return nullptr;
}

void Shield::read(istream & in)
{
	int protection, dupability;
	in >> protection >> dupability;
	setProtection(protection);
	setDupability(dupability);
}

void Shield::save(ostream & out)
{
	out << getType() << " ";
	out << getProtection() << " " << getDupability() << endl;
}

int Shield::getDupability()
{
	return this->dupability;
}

const string Shield::getType()
{
	return "Shield";
}

bool Shield::getIsTaken()
{
	return this->isTaken;
}
bool Shield::isUseable()
{
	return getDupability() > 0;
}

bool Shield::canBeTaken()
{
	return getDupability() > 0 && !getIsTaken();
}
