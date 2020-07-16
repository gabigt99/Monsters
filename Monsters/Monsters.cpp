#pragma once
#include "pch.h"
#include "Monsters.h"
#include "Dragon.h"
#include "Knight.h"
#include "Vampire.h"
#include "Zombie.h"
//#include "Weapon.h"
//#include "Shield.h"

#ifndef MONSTER
#define MONSTER

Monster::Monster(int health, int attackPower, int armor, const char *name, Weapon* weapon, Shield* shield)
{
	this->setHealth(health);
	this->setAttackPower(attackPower);
	this->setArmor(armor);
	this->name = NULL;
	if (name != NULL)
	{
		this->setName(name);
	}
	if (weapon == NULL)
	{
		this->weapon = weapon;
	}
	else takeWeapon(weapon);
	if (shield == NULL)
	{
		this->shield = shield;
	}
	else takeShield(shield);
}
Monster::Monster(const Monster &other)
{
	name = NULL;
	*this = other;
}


void Monster::setHealth(int health)
{
	if (health < 0)
	{
		health = 0;
	}
	this->health = health;
}
void Monster::setAttackPower(int attackPower)
{
	if (attackPower < 0)
	{
		attackPower = 0;
	}
	this->attackPower = attackPower;
}
void Monster::setArmor(int armor)
{
	if (armor < 0)
	{
		armor = 0;
	}
	this->armor = armor;
}
void Monster::setName(const char *name)
{
	if (this->name != NULL)
	{
		delete this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Monster::takeWeapon(Weapon *weapon)
{
	if (this->weapon != NULL)
	{
		this->weapon->setIsTaken(0);
	}
	if (weapon->canBeTaken())
	{
		this->weapon = weapon;
		weapon->setIsTaken(1);
	}
}
bool Monster::canUseWeapon()
{
	if (this->weapon == NULL)
	{
		return false;
	}
	return (rand() % 2) == 0;
}
bool Monster::isHaveWeapon() const
{
	if (weapon != nullptr)
	{
		return true;
	}
	return false;
}
void Monster::returnWeapon()
{
	if (weapon != NULL && weapon->getIsTaken())
	{
		weapon->setIsTaken(0);
		weapon = NULL;
	}
}
void Monster::restoreWeapon(istream& in)
{
	Weapon* weapon = new Weapon;
	weapon->read(in);
	this->takeWeapon(weapon);
}
void Monster::takeShield(Shield* shield)
{
	if (this->shield != NULL)
	{
		this->shield->setIsTaken(0);
	}
	if (shield->canBeTaken())
	{
		this->shield = shield;
		shield->setIsTaken(1);
	}
}
bool Monster::canUseShield()
{
	if (this->shield == NULL)
	{
		return false;
	}
	return (rand() % 2) == 0;
}

bool Monster::isHaveShield() const
{
	if (shield != nullptr)
	{
		return true;
	}
	return false;
}

void Monster::returnShield()
{
	if (shield != NULL && shield->getIsTaken())
	{
		shield->setIsTaken(0);
		shield = NULL;
	}
}

void Monster::restoreShield(istream & in)
{
	Shield* shield = new Shield;
	shield->read(in);
	takeShield(shield);
}

const int Monster::getHealth()
{
	return this->health;
}
const int Monster::getAttackPower()
{
	return this->attackPower;
}
const int Monster::getArmor()
{
	return this->armor;
}
const char* Monster::getName()
{
	return this->name;
}
Weapon * Monster::getWeapon()
{
	return weapon;
}
Shield * Monster::getShield()
{
	return shield;
}
const string Monster::getType()
{
	return "Monster";
}
Monster* Monster::factory(string type)
{
	if (type == "Monster")
	{
		return new Monster(0, 0, 0, "MnoName");
	}
	if (type == "Dragon")
	{
		return new Dragon(0, 0, 0, "DnoName");
	}
	if (type == "Knight")
	{
		return new Knight(0, 0, 0, "KnoName");
	}
	if (type == "Vampire")
	{
		return new Vampire(0, 0, 0, "VnoName");
	}
	if (type == "Zombie")
	{
		return new Zombie(0, 0, 0, "ZnoName");
	}
	return nullptr;
}
void Monster::read(istream & in)
{
	int health, attackPower, armor;
	in >> health >> attackPower >> armor >> name;
	setHealth(health);
	setAttackPower(attackPower);
	setArmor(armor);
}
void Monster::save(ostream & out)
{
	out << getType() << " ";
	out << getHealth() << " " << Monster::getAttackPower() << " " << Monster::getArmor() << " "; // защото на Дракона се променят показателите
	if (getName() == nullptr)
	{
		out << "NoName" << endl;
	}
	else out << getName() << endl;
}

Monster& Monster::operator = (const Monster &otherMonster)
{
	this->setHealth(otherMonster.health);
	this->setAttackPower(otherMonster.attackPower);
	this->setArmor(otherMonster.armor);
	this->setName(otherMonster.name);
	return *this;
}

bool Monster::isAlive()
{
	return this->getHealth() > 0;
}

Monster* Monster::fight(Monster &opponent)
{
	if (this != &opponent)
	{
		int countMissHits = 0;
		int thisHealth;
		int opponentHealth;
		while (this->isAlive())
		{
			if (countMissHits == 10)
			{
				return nullptr;
			}
			thisHealth = this->getHealth();
			opponentHealth = opponent.getHealth();
			this->hit(opponent);
			if (opponent.isAlive())
			{
				opponent.hit(*this);
			}
			else return (this);
			if (thisHealth == this->getHealth() && opponentHealth == opponent.getHealth())
			{
				countMissHits++;
			}
		}
	}
	return &opponent;
}

int Monster::hit(Monster &opponent)
{
	int damage = this->getAttackPower() - opponent.getArmor();
	bool canUseWeapon = this->canUseWeapon();
	bool canUseShield = opponent.canUseShield();
	if (canUseWeapon && this->weapon->isUseable() && canUseShield && opponent.shield->isUseable())
	{
		damage = this->getAttackPower() + weapon->getPower() - opponent.getArmor() - opponent.shield->getProtection();
		weapon->setDupability(weapon->getDupability() - 1);
		opponent.shield->setDupability(opponent.shield->getDupability() - 1);
	}
	else if (canUseWeapon && this->weapon->isUseable())
	{
		damage = this->getAttackPower() + weapon->getPower() - opponent.getArmor();
		weapon->setDupability(weapon->getDupability() - 1);
	}
	else if (canUseShield && opponent.shield->isUseable())
	{
		damage = this->getAttackPower() - opponent.getArmor() - opponent.shield->getProtection();
		opponent.shield->setDupability(opponent.shield->getDupability() - 1);
	}
	if (damage > 0)
	{
		opponent.setHealth(opponent.getHealth() - damage);
	}
	return damage;
}

void Monster::print() const
{
	if (this->name != NULL)
	{
		cout << this->name << ": ";
	}
	cout << this->health << " "
		<< this->attackPower << " "
		<< this->armor << " "
		<< isHaveWeapon() << " " 
		<< isHaveShield() << endl;
}


Monster::~Monster()
{
	delete this->name;
}

#endif // !MONSTER