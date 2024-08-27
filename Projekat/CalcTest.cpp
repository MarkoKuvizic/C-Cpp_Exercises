#include "PermutationGenerator.h"

#include "CalcTest.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
bool test() {
	fstream f;
	f.open("CalcTest.txt");
	string exp, res;
	while (f >> exp >> res) {
		
		Calculator<double> c(exp, vector<string> {}, true);
		if (c.expression() != stoi(res)) {
			cout << "TEST NIJE PROSAO";
			f.close();
			return false;
		}
	}
	f.close();
	Generator gen("PermTest.txt");
	gen.generate();
	if (gen.getGoal() != gen.getOriginalGoal()) {
		cout << "TEST NIJE PROSAO";
		return false;
	}
	cout << "TEST JE PROSAO";
	return true;
}