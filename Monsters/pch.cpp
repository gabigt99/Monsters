#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include "Tournament.h"
#include "Vampire.h" 
#include "Dragon.h"
#include "Knight.h"
#include "Zombie.h"
#include "Schema.h"
#include "DirectElemination.h"
#include "EverybodyVSeverybody.h"
#include "Mixed.h"
#include "Arena.h"

using namespace std;

void test1()
{
	Weapon w1(12, 20);
	Weapon w2(15, 3);

	Shield sh1(12, 10);
	Shield sh2(16, 8);

	Monster A1(70, 23, 17, "A1Monster");
	Monster B1(93, 24, 23, "B1Monster");
	Dragon d1(90, 100, 90, "Dragon1");
	Dragon d2(110, 100, 100, "Dragon2");
	Knight k1(100, 100, 100, "Knight1");
	Vampire v1(100, 21, 23, "Vampire1");
	Vampire v2(111, 100, 100, "Vampire2");
	Zombie z1(80, 24, 12, "Zombie1");
	Zombie zom1(29, 21, 34, "Zom1Zombie");

	DirectElemination s1;
	ofstream out1("Tournament1.txt");
	Tournament T1(&out1);
	T1.getSchema(&s1);
	T1.addFighter(A1);
	T1.addFighter(B1);
	T1.addFighter(d1);
	T1.addFighter(d2);
	T1.addFighter(k1);
	T1.addFighter(v1);
	T1.addFighter(v2);
	T1.addFighter(z1);
	T1.addFighter(zom1);

	T1.addWeapon(w1);
	T1.addWeapon(w2);

	T1.addShield(sh1);
	T1.addShield(sh2);


	Weapon w3(12, 20);
	Weapon w4(15, 3);

	Shield sh3(12, 10);
	Shield sh4(16, 8);

	Monster A2(70, 23, 17, "A2Monster");
	Monster B2(93, 24, 23, "B2Monster");
	Dragon d3(90, 100, 90, "Dragon3");
	Dragon d4(40, 100, 100, "Dragon4");
	Knight k2(100, 100, 100, "Knight2");
	Vampire v3(100, 21, 23, "Vampire3");
	Vampire v4(111, 100, 100, "Vampire4");
	Zombie z2(80, 24, 12, "Zombie2");
	Zombie zom2(29, 21, 34, "ZomZombie2");

	EverybodyVSeverybody s2;
	ofstream out2("Tournament2.txt");
	Tournament T2(&out2);
	T2.getSchema(&s2);
	T2.addFighter(A2);
	T2.addFighter(B2);
	T2.addFighter(d3);
	T2.addFighter(d4);
	T2.addFighter(k2);
	T2.addFighter(v3);
	T2.addFighter(v4);
	T2.addFighter(z2);
	T2.addFighter(zom2);

	T2.addWeapon(w3);
	T2.addWeapon(w4);

	T2.addShield(sh3);
	T2.addShield(sh4);


	Weapon w5(100, 20);
	Weapon w6(150, 3);

	Shield sh5(120, 10);
	Shield sh6(160, 8);

	Monster A3(70, 23, 17, "A3Monster");
	Monster B3(93, 24, 23, "B3Monster");
	Dragon d5(110, 120, 100, "Dragon5");
	Dragon d6(110, 120, 100, "Dragon6");
	Knight k3(100, 100, 100, "Knight3");
	Vampire v5(100, 21, 23, "Vampire5");
	Vampire v6(80, 92, 69, "Vampire6");
	Zombie z3(80, 24, 12, "Zombie3");
	Zombie zom3(29, 21, 34, "ZomZombie3");

	Mixed s3;
	Schema &p = static_cast<EverybodyVSeverybody&> (s3);
	ofstream out3("Tournament3.txt");
	Tournament T3(&out3);
	T3.getSchema(&p);
	T3.addFighter(A3);
	T3.addFighter(B3);
	T3.addFighter(d5);
	T3.addFighter(d6);
	T3.addFighter(k3);
	T3.addFighter(v5);
	T3.addFighter(v6);
	T3.addFighter(z3);
	T3.addFighter(zom3);

	T3.addWeapon(w5);
	T3.addWeapon(w6);

	T3.addShield(sh5);
	T3.addShield(sh6);


	Arena Ar;
	Ar.addTournament(T1);
	Ar.addTournament(T2);
	Ar.addTournament(T3);
	Ar.startTournaments();
	
	ofstream out("ArenaSerial.txt");
	Ar.serializationOfTournaments(out); // става и със cout

	/*Monster A(110, 23, 17, "AMonster");
	DirectElemination s;
	Tournament T;
	T.getSchema(&s);
	T.addFighter(A);

	//ifstream in("monsters.txt");
	//T.operator>>(in);
	//T.fight();
	//T.print();

	ifstream innn("schema.txt");
	T.restoreSchema(innn);
	T.print();*/
}
void test2()
{
	Arena Ar;
	ifstream in("ArenaSerial.txt");
	Ar.deserializationOfTournaments(in);
	Ar.startTournaments();
}
int main()
{
	//test1();
	test2();
}