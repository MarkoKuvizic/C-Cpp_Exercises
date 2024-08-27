#include "std_lib_facilities.h"
#include <stdio.h>


int fib(int n) {
	if (n < 0) {
		error("Negatian broj");
	}
	int x, y;
	if (n == 0 || n == 1) {
		return n;
	}
	cout << "1. " << 1 << endl;
	
	x = 1;
	y = 1;
	int curr = 0;
	for (int i = 1; i < n; i++) {
		curr = y + x;
		if (curr < 0) {
			error("Preveliki broj");
			break;
		}
		x = y;
		y = curr;
		cout << i + 1 << ". " << curr << endl;
	}
	return curr;
}
long fibLong(int n) {
	if (n < 0) {
		error("Negatian broj");
	}
	long x, y;
	if (n == 0 || n == 1) {
		return n;
	}
	cout << "1. " << 1 << endl;

	x = 1;
	y = 1;
	long curr = 0;
	for (int i = 1; i < n; i++) {
		curr = y + x;
		if (curr < 0) {
			error("Preveliki broj");
			break;
		}
		x = y;
		y = curr;
		cout << i + 1 << ". " << curr << endl;
	}
	return curr;
}
long long fibLongLong(int n) {
	if (n < 0) {
		error("Negatian broj");
	}
	long long x, y;
	if (n == 0 || n == 1) {
		return n;
	}
	cout << "1. " << 1 << endl;
	
	x = 1;
	y = 1;
	long long curr = 0;
	for (int i = 1; i < n; i++) {
		curr = y + x;
		if (curr < 0) {
			error("Preveliki broj");
			break;
		}
		x = y;
		y = curr;
		cout << i + 1 << ". " << curr << endl;
	}
	return curr;
}
int main() {
	try {
		fib(100);
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}