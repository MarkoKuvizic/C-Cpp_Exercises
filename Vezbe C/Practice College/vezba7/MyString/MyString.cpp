#include "MyString.h"

#include <cstring>

//-----------------------------------------------------------
// HELPER FUNCTIONS
//-----------------------------------------------------------
void copyString(char* dst, const char* src)
{
	strcpy(dst, src);
	dst[strlen(src)] = '\0';
}

bool compareString(const char* src1, const char* src2)
{
	if (strcmp(src1, src2) == 0)
		return true;
	return false;
}
//-----------------------------------------------------------
//-----------------------------------------------------------

MyString::MyString(int length, char* buf) :len(length) {
	this->buf = new char[len+1];
	copyString(this->buf, buf);
}

MyString::MyString(char* b)
{
	len = strlen(b);
	this->buf = new char[len + 1];
	copyString(this->buf, b);
}

MyString::MyString(MyString& str):len(str.len)
{
	buf = new char[len + 1];
	copyString(buf, str.buf);
}

MyString::MyString() :len(0)
{
	this->buf = nullptr;
}

int MyString::length()
{
	return len;
}

char MyString::operator[](int i)
{
	if (i >= len || i < 0) {
		throw std::out_of_range("INDEX OUT OF RANGE");
	}
	return buf[i];
}

MyString MyString::operator=(char c)
{
	delete[] buf;
	this->len = 1;
	this->buf = new char[2];
	this->buf[0] = c;
	this->buf[1] = '\0';
	return *this;
	
}

MyString MyString::operator=(MyString s)
{
	delete[] buf;
	std::cout << s << "HEJ";

	this->len = s.len;
	this->buf = new char[s.len + 1];
	copyString(this->buf, s.buf);
	return *this;
}

MyString MyString::operator=(char* c)
{
	delete[] buf;

	this->len = strlen(c);
	this->buf = new char[this->len + 1];
	copyString(this->buf, c);
	return *this;
}

MyString operator+(const MyString& left, const MyString& right) {
	MyString mstr = MyString();
	mstr.buf = new char[left.len + right.len + 1];
	copyString(mstr.buf, left.buf);
	copyString(mstr.buf + left.len, right.buf);
	mstr.len = strlen(mstr.buf);
	return mstr;
}

MyString MyString::operator+(char* str)
{
	MyString mstr = MyString();
	mstr.buf = new char[len + strlen(str)+1];
	copyString(mstr.buf, buf);
	copyString(mstr.buf + len, str);
	mstr.len = strlen(mstr.buf);
	return mstr;
}

/*MyString& MyString::operator+(char c)
{
	MyString s = MyString();
	s.buf = new char[this->len + 2];
	copyString(s.buf, buf);
	s.buf[len] = c;
	s.buf[len+1] = '\0';

	s.len = strlen(s.buf);
	std::cout << s;
	return s;
}*/
MyString& MyString::operator+(char c)
{
	char cc[1] = { c };
	return *this + cc;
}

MyString::~MyString()
{
	delete[] buf;
}

std::istream& operator>>(std::istream& in, MyString& str)
{
	char* temp = new char[256];
	in >> temp;
	str.buf = new char[strlen(temp) + 1];
	copyString(str.buf, temp);
	str.len = strlen(str.buf);
	delete[] temp;
	return in;
}

MyString& operator+(char* str, MyString& s)
{
	return MyString();
}

MyString& operator+(char c, MyString& s)
{
	return MyString();
}



std::ostream& operator<<(std::ostream& out, MyString& str)
{
	out << str.buf;
	return out;
}
