//************************************
// Isaac N Pendley
// 04/08/2019
// Program 5 MyString 
// Programming 2
//************************************
// test driver code goes here
#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{

	MyString s1;
	MyString s2("billy");
	MyString s3(s2);
	char a[] = "hello";
	MyString s4(a);
	MyString s5 = " world";
	MyString s6 = s4 + s5;
	MyString s7 = " world";
	bool equal = s5 == s7;

	if (!equal)
	{
		cout << "Inequal strings\n";
	}
	else {
		cout << "Equal Strings\n";
	}
	cout << s5;
	int temp;
	cin >> temp;
	return 0;
}