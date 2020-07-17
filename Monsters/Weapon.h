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
	Weapon(int power = 0, int dupability = 0) //:power(p), dupability(d) {};
	{
		setPower(power);
		setDupability(dupability);
		isTaken = false;
	}
	void setPower(int power);
	void setDupability(int dupability);
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