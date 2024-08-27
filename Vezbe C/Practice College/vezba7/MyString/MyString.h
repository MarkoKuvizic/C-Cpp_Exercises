#pragma once

#include <iostream>

class MyString
{
	private: 
		int len;
		char* buf;
	public:
		MyString(int length, char* buf);
		MyString(char* buf);
		MyString(MyString& str);
		MyString();
		int length();
		char operator[](int i);
		MyString operator=(char c);
		MyString operator=(MyString str);
		MyString operator=(char* c);
		friend std::ostream& operator<<(std::ostream& out, MyString& str);
		friend std::istream& operator>>(std::istream& in, MyString& str);
		friend MyString operator+(const MyString& left, const MyString& right);
		MyString operator+(char* str);
		friend MyString& operator+(char* str, MyString& s);
		MyString& operator+(char c);
		friend MyString& operator+(char c, MyString& s);
		~MyString();
};

