#include <iostream>
#include <sstream>
#include "Calculator.h"

using namespace std;





template<typename T>
TokenStream<T>::TokenStream(string s) : buffer(), full(false), str(s) {}
template<typename T>
TokenStream<T>::TokenStream(string s, vector<string> vv) : buffer(), full(false), str(s), v(vv), vCopy(vv) {}

template<typename T>
Token<T> TokenStream<T>::getToken()
{
	if (full) {
		full = false;
		return buffer;
	}

	char tmp;
	str >> tmp;
	switch (tmp) {
	case '0': case '1': case '2': case '3':
	case '4': case '5': case '6': case '7':
	case '8': case '9': case '.': {
		str.putback(tmp);

		double val;
		str >> val;

		return Token<T>('8', val);
	}
	case '(':
	case ')':
	case ';':
	case 'q':
	case '+':
	case '*':
	case '-':
	case '/':
		return Token<T>(tmp);
	default:
		cout << "BAD TOKEN";
		throw exception("bad token");
		return Token<T>();
	}
}

template<typename T>
void TokenStream<T>::putBack(Token<T> token)
{
	buffer = token;
	full = true;
}

template<typename T>
void TokenStream<T>::setStr(string s)
{
	str = stringstream(s);
}


template<typename T>
T Calculator<T>::number()
{
	Token<T> token = ts.getToken();
	if (token.kind != '8')
		throw exception("expected number");
	int n = ts.vCopy.size();
	bool found = test;
	if (test == false) {
		
		for (int i = 0; i < n; i++) {
			if (token.value == stoi(*(ts.vCopy.begin() + i))) {
				ts.vCopy.erase(ts.vCopy.begin() + i);
				found = true;
				break;
			}
		}
	}
	
	if (!found) {
		throw exception("Koriscen je broj koji nije dostupan");
	}
	return token.value;
}

template<typename T>
T Calculator<T>::expression();

template<typename T>
T Calculator<T>::primary()
{
	Token<T> token = ts.getToken();
	switch (token.kind) {
	case '(': {
		double lval = expression();
		token = ts.getToken();
		if (token.kind != ')')
			throw exception("unmatched '('");
		return lval;
	}
	default:
		ts.putBack(token);
		return number();
	}
}

template<typename T>
T Calculator<T>::term()
{
	T lval = primary();

	while (true) {
		Token<T> token = ts.getToken();

		switch (token.kind) {
		case '*':
			lval *= primary();
			break;
		case '/':
			lval /= primary();
			break;
		default:
			ts.putBack(token);
			return lval;
		}
	}
}

template<typename T>
Calculator<T>::Calculator(string s, vector<string> v) :ts(TokenStream<T>(s, v)), test(false) {}
template<typename T>
void Calculator<T>::init(string s)
{
	ts = TokenStream<T>(s, ts.v);
}
template<typename T>
Calculator<T>::Calculator(string s, vector<string> v, bool test) : ts(TokenStream<T>(s, v)), test(test) {};




template<typename T>
T Calculator<T>::expression()
{
	ts.vCopy = vector<string>(ts.v);
	T lval = term();
	while (true) {
		Token<T> token = ts.getToken();

		switch (token.kind) {
		case '+':
			lval += term();
			break;
		case '-':
			lval -= term();
			break;
		default:
			ts.putBack(token);
			return lval;
		}
	}
}
template<typename T>
Token<T>::Token(char ch, T val) : kind(ch), value(val) {}
template<typename T>
Token<T>::Token(char ch) : kind(ch), value(0) {}

template<typename T>
Token<T>::Token() : kind('x'), value(0) {}