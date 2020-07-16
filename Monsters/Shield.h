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
	Shield(int p = 0, int d = 0) 
	{
		setProtection(p);
		setDupability(d);
		isTaken = false;
	}
	void setProtection(int p);
	void setDupability(int d);
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