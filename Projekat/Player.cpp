#include "Player.h"
#include <fstream>
#include <iostream>
using namespace std;

Player::Player(string name):name(name){}

void Player::dump(string file)
{
	ofstream out;
	out.open(file, ios_base::app);
	out << name << " " << "====================" << endl;
	for (int i = 0; i < points.size(); i++) {
		out << i+1 << ". " << results[i] << " " << points[i] << " "<< expressions[i]<< endl;
	}
	
	out.close();
}
void Player::round(int result, int goal, int mistakeTolerance){
	int point = 0;
	if (abs(result - goal) <= mistakeTolerance) {
		point = 30;
	}
	else if (abs(result - goal) <= mistakeTolerance + 1) {
		point = 1;
	}
	points.push_back(point);
	results.push_back(result);
}
vector<int> Player::getPoints()
{
	return points;
}

vector<int> Player::getResults()
{
	return results;
}

vector<string> Player::getExpressions()
{
	return expressions;
}

void Player::pushExpression(string str)
{
	expressions.push_back(str);
}

void Player::pushPoints(int p)
{
	points.push_back(p);
}

void Player::pushResult(int r)
{
	results.push_back(r);
}

string Player::getName()
{
	return name;
}
