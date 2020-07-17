#pragma once
#include"pch.h"
#include<string>
#include<iostream>
#include<stdio.h>

using namespace std;
#ifndef SHIELD
#define SHIELD
class Shield
{
public:
	Shield(int protection = 0, int dupability = 0)
	{
		setProtection(protection);
		setDupability(dupability);
		isTaken = false;
	}
	void setProtection(int protection);
	void setDupability(int dupability);
	void setIsTaken(bool isTaken);
	int getProtection();
	int getDupability();
	virtual const string getType();
	static Shield* factory(string type);
	void read(istream& in);
	void save(ostream& out);
	bool getIsTaken();
	bool isUseable();
	bool canBeTaken();
private:
	int protection;
	int dupability;
	bool isTaken;
};

#endif