#include "std_lib_facilities.h"
#include <stdio.h>
using namespace std;
//Funkcija 1: Prima neoznacen ceo broj i vraca njegovu heksadecimalnu vrednost u formatu stringa
string foo1(unsigned int x) {
	
	string res = "";
	char a;
	while (x > 0) {
		a = (char)((x % 16) + '0');
		if (a < '0' || a > '9') {
			a += 7;
		}
		res = a + res;
		x /= 16;
	}

	return res;
}
//Funkcija 3: Prima string reprezentaciju heksadecimalnog celog broja (pozitivnog ili negativnog) i vraca internu (dekadnu) vrednost
//tog broja. U slucaju nevalidnog unosa (recimo slova koje nisu hex cifre) baca exception koristeci pomocnu error funkciju
int foo3(string a) {
	int res = 0;

	int op;
	bool negative = false;

	for (int i = 0; i < a.size(); i++) {
		if (i == 0 && a[i] == '-') {
			negative = true;
			continue;
		}
		op = pow(16, (a.size() - i - 1));

		if (op == 0) {
			op = 1;
		}
		if (a[i] >= '0' && a[i] <= '9') {
			res += (a[i] - '0') * op;
		}
		else if (a[i] >= 'A' && a[i] <= 'F') {
			res += (a[i] - '0' - 7) * op;
		}
		else if (a[i] >= 'a' && a[i] <= 'f') {
			res += (a[i] - 87) * op;
		}
		else {
			error("Nevalidna hex cifra");
			break;
		}
	}
	if (a[0] == '-') {
		return -1 * res;
	}
	return res;
}
//Funkcija 2: Prima 2 string reprezentacije heksadecimalnih brojeva, koristeci funkciju 3 ih konvertuje u int, a onda ih sabira i vraca
//string reprezentaciju rezultata. Ako je rezultat negativan, baca exception.
string foo2(string a, string b) {
	int x = foo3(a);
	int y = foo3(b);
	if (x + y < 0) {
		error("Rezultat manji od 0");
	}
	return foo1(x + y);
}

int main() {
	try {
		cout << foo2("12ca3f", "aa3");
	}
	catch (exception e) {
		cout << e.what() << endl;
		return 1;
	}
}