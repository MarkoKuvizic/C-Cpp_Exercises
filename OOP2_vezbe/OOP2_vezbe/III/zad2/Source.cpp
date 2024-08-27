#include "std_lib_facilities.h"
#include <stdio.h>

void foo(short val1, short val2) {
	if (val1 < val2) {
		cout << val2 << " je veci" << endl;
		cout << val1 << " je manji" << endl;
	}
	else if(val1 > val2) {
		cout << val1 << " je veci" << endl;
		cout << val2 << " je manji" << endl;
	}
	else {
		cout << "Jednaki su" << endl;
	}
	cout << "Zbir: " << val1 + val2 << endl;
	cout << "Razlika: " << val1 - val2 << endl;
	cout << "Proizvod: " << val1 * val2 << endl;
	cout << "Kolicnik: " << val1 / val2 << endl;
}
void foo(int val1, int val2) {
	if (val1 < val2) {
		cout << val2 << " je veci" << endl;
		cout << val1 << " je manji" << endl;
	}
	else if (val1 > val2) {
		cout << val1 << " je veci" << endl;
		cout << val2 << " je manji" << endl;
	}
	else {
		cout << "Jednaki su" << endl;
	}
	cout << "Zbir: " << val1 + val2 << endl;
	cout << "Razlika: " << val1 - val2 << endl;
	cout << "Proizvod: " << val1 * val2 << endl;
	cout << "Kolicnik: " << val1 / val2 << endl;
}
void foo(double val1, double val2) {
	if (val1 < val2) {
		cout << val2 << " je veci" << endl;
		cout << val1 << " je manji" << endl;
	}
	else if (val1 > val2) {
		cout << val1 << " je veci" << endl;
		cout << val2 << " je manji" << endl;
	}
	else {
		cout << "Jednaki su" << endl;
	}
	cout << "Zbir: " << val1 + val2 << endl;
	cout << "Razlika: " << val1 - val2 << endl;
	cout << "Proizvod: " << val1 * val2 << endl;
	cout << "Kolicnik: " << val1 / val2 << endl;
}
void selection() {
	char a;
	string x, y;
	int val1, val2;
	double d1, d2;
	cout << " 1) Short \n 2) Int \n 3) Double" << endl;
	cin >> a;
	switch (a) {
		case '1':
			cin >> x;
			cin >> y;
			val1 = stoi(x);
			val2 = stoi(y);
			if (val1 > 32767 || val2 > 32767) {
				cout << "Preveliki brojevi za short" << endl;
				error("Preveliki brojevi za short");
			}
			foo((short)val1, (short)val2);
			break;
		case '2':
			cin >> x;
			cin >> y;
			foo(stoi(x), stoi(y));
			break;
		case '3':
			cin >> x;
			cin >> y;
			foo(stod(x), stod(y));
			break;
		case 'x':
			exit(0);
	}
}
int main() {
	while (true) {
		try {
			selection();
		}
		catch (...) {
			cout << "Greska" << endl;
			selection();
		}
	}
}