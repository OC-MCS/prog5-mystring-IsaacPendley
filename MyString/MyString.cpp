// MyString implementation file
#include "MyString.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

MyString::MyString()
{
	//Sets the empty string class to null
	str = nullptr;
}

MyString::MyString(const char* s)
{
	//Dynamically allocates space for the string passed in and copies it into a char array being pointed at
	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
}

MyString::MyString(const MyString& other)
{
	str = new char[strlen(other.str) + 1];
	strcpy_s(str, strlen(other.str) + 1, other.str);
}

MyString::~MyString()
{
	//I break things
	delete[] str;
}

void MyString::operator = (const MyString& other)
{
	if (this != &other)
	{
		delete[] str;
		str = new char[strlen(other.str) + 1];
		strcpy_s(str, strlen(other.str), other.str);
	}
}

MyString MyString::operator + (const MyString& other)
{
	//stick the string passed in on the end of our current string
	MyString temp = new char[strlen(str) + strlen(other.str) + 1];
	strcpy_s(temp.str, strlen(str) + 1, str);
	strcat_s(temp.str, (strlen(str) + strlen(other.str)) + 1, other.str);
	return temp;
}

bool MyString::operator == (const MyString& s2)
{
	//compares the two strings to see if they are equal
	if (s2.str && str) {
		if (strlen(str) != strlen(s2.str))
		{
			return false;
		}
		for (int i = 0; i < strlen(s2.str); i++)
		{
			if (this->str[i] != s2.str[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

const char* MyString::c_str()
{
	//call an overloaded output operator that is not a member of MyString but still in the cpp class
	return str;
} 

ostream &operator<<(ostream &strm, MyString &thing) {
	if (thing.c_str()) {
		strm << thing.c_str();
	}
	return strm;
}