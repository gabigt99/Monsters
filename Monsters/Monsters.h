#pragma once
#include "pch.h"
#include "Weapon.h"
#include "Shield.h"
#include<string>
#include<iostream> 
#include<stdio.h>
#include<stddef.h>
#include<string.h>


using namespace std;

class Monster
{
private:
	int attackPower;
	int armor;
	char *name;
protected:
	int health;
	Weapon *weapon;
	Shield *shield;
public:
	Monster(int health = 0, int attackPower = 0, int armor = 0, const char *name = NULL, Weapon* weapon = NULL, Shield* shield = NULL);
	Monster(const Monster &m);
	virtual void setHealth(int health);
	void setAttackPower(int attackPower);
	void setArmor(int armor);
	void setName(const char *name);
	void takeWeapon(Weapon *w);
	virtual bool canUseWeapon();
	bool isHaveWeapon() const;
	void returnWeapon();
	void restoreWeapon(istream& in);
	void takeShield(Shield* s);
	virtual bool canUseShield();
	bool isHaveShield() const;
	void returnShield();
	void restoreShield(istream& in);
	const int getHealth();
	virtual const int getAttackPower();
	virtual const int getArmor();
	const char* getName();
	Weapon* getWeapon();
	Shield* getShield();
	virtual const string getType();
	static Monster* factory(string type);
	void read(istream& in);
	void save(ostream& out);
	Monster& operator = (const Monster &m);
	virtual bool isAlive();
	Monster* fight(Monster &m);
	virtual int hit(Monster& m);
	void print() const;
	virtual ~Monster();
};

