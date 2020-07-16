#pragma once
#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;
#ifndef WEAPON
#define WEAPON

class Weapon
{
public:
	Weapon(int p = 0, int d = 0) //:power(p), dupability(d) {};
	{
		setPower(p);
		setDupability(d);
		isTaken = false;
	}
	void setPower(int newPower);
	void setDupability(int newDupability);
	void setIsTaken(bool isTaken);
	int getPower();
	int getDupability();
	bool getIsTaken();
	virtual const string getType();
	static Weapon* factory(string type);
	void read(istream& in);
	void save(ostream& out);
	bool isUseable();
	bool canBeTaken();
private:
	int power;
	int dupability;
	bool isTaken;
};

#endif // !WEAPON