#pragma once
#include <iostream>
using namespace std;
// MyString class declaration goes here
class MyString
{
private:
	char *str;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();
	void operator = (const MyString&);
	MyString operator + (const MyString&);
	bool operator == (const MyString&);
	const char* c_str();
};

ostream& operator<<(ostream &, MyString &);