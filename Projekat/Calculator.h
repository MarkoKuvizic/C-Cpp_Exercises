#pragma once
#include <string>
#include <sstream>
#include <vector>

using namespace std;
template <typename T>
class Token {
public:
	Token(char ch, T val);
	Token(char ch);
	Token();
	char kind;
	T value;
};
template <typename T>
class TokenStream {
public:
	TokenStream(string s);
	TokenStream(string s, vector<string> vv);
	Token<T> getToken();
	void putBack(Token<T> token);
	vector<string> v;
	vector<string> vCopy;
	void setStr(string s);
protected:
	Token<T> buffer;
	bool full;
	stringstream str;

};
template <typename T>
class Calculator {
public:
	Calculator(string s, vector<string> v);
	void init(string s);
	Calculator(string s, vector<string> v, bool test);
	//void init(string str);
	// init(string str, vector<string> vv);
	T expression();
	T term();
	T number();
	T primary();
	bool test;
private:
	TokenStream<T> ts;
};
#include "Calculator.cpp"
