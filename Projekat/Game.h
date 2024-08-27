#pragma once
#include "Player.h"
#include "PermutationGenerator.h"
using namespace std;
/*
	Klasa se koristi za pracenje toka igre

	Autor: Marko Kuvizic SV38-2021
	Poslednja izmena: 8.01.2023. 09:32
*/
class Game {
public:
	Game(string p1, string p2, string file);	//p1 i p2 su imena igraca
	void round();	//Funkcija za igranje jedne runde
	void playP1();
	void playP2();
	void play();
private:
	Generator gen;	//Generator varijacija
	Player p1;
	Player p2;
	int roundCounter;	//Brojac rundi
};