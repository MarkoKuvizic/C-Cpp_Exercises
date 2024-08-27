#pragma once
#include "Game.h"
#include <fstream>
Game::Game(string p1, string p2, string file):p1(p1),p2(p2),roundCounter(0), gen(file)
{

}

void Game::round()
{
	play();
	gen.round();
	roundCounter++;
	if(gen.getAllGoals().size()!=0){
		round();
	}
	else{ 
		play();
		ofstream out;
	
		out.open("Out.txt");
		out.close();
		p1.dump("Out.txt");
		p2.dump("Out.txt");
		gen.dump("Out.txt");
	}
	

}

void Game::playP1()
{
	cout << "Igra " << p1.getName() << "... " << endl;
	string str;
	cin >> str;
	Calculator<double> c(str+";", gen.getV());
	double d;
	try {
		d = c.expression();
	}
	catch (exception e) {
		cout << e.what();
		cout << " Nevalidan izraz" << endl;
		d = -10;
	}
	p1.pushExpression(str);
	p1.round(d, gen.getOriginalGoal(), abs(gen.getOriginalGoal() - gen.getGoal()));

}

void Game::playP2()
{
	cout << "Igra " << p2.getName() << "... " << endl;
	string str;
	cin >> str;
	Calculator<double> c(str + ";", gen.getV());
	double d;
	try {
		d = c.expression();
	}
	catch (exception e) {
		cout << "Nevalidan izraz" << endl;
		d = -10;
	}
	p2.pushExpression(str);
	p2.round(d, gen.getOriginalGoal(), abs(gen.getOriginalGoal() - gen.getGoal()));

}

void Game::play()
{
	gen.generate();
	cout << endl << "TRAZI SE: " << gen.getOriginalGoal() << endl;

	cout << endl << "BROJEVI: " << endl;
	for (string s : gen.getV()) {
		cout << s << " ";
	}
	if (roundCounter % 2 == 0) {
		playP1();
		if (p1.getPoints().back() != 30) {
			playP2();
		}
		else {
			p2.pushExpression("Nije imao priliku da igra");
			p2.pushPoints(0);
			p2.pushResult(0);
		}
	}
	else {
		playP2();
		if (p2.getPoints().back() != 30) {
			playP1();
		}
		else {
			p1.pushExpression("Nije imao priliku da igra");
			p1.pushPoints(0);
			p1.pushResult(0);
		}
	}
	cout << "Racunar je dobio: " << gen.getGoal() << " Izrazom: " << gen.getExpression() << endl;

}
