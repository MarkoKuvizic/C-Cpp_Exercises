#pragma once
#include <vector>
#include <string>
using namespace std;
/*
	Klasa modeluje jednog igraca u igri, prati njegove rezultate i osvojene poene, i sadrzi metodu za pisanje u fajl

	Autor: Marko Kuvizic SV38-2021
	Poslednja izmena: 8.01.2023. 21:04
*/
class Player {
public:
	Player(string name);
	void dump(string file);	//Metoda za pisanje u fajl
	void round(int result, int goal, int mistakeTolerance);	//Metoda racuna osvojene poene za igraca u ovoj rundi i prelazi na sledecu
	vector<int> getPoints();
	vector<int> getResults();
	vector<string> getExpressions();
	void pushExpression(string str);
	void pushPoints(int p);
	void pushResult(int r);
	string getName();
private:
	vector<int> points;
	vector<string> expressions;
	vector<int> results;
	string name;
};