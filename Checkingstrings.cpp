/*
David Ankory 206780066
Workshop in C ++
Exercise 3 Question 3
The code performs various operations between strings
*/
#include <iostream>
#include "String.h"
#include<cstring>
using namespace std;

int main() {

	char temp1[30], temp2[30];
	cin >> temp1;
	cin >> temp2;
	String str1(temp1), str2(temp2);

	int n;//index1
	cin >> n;

	if (str1 == str2)//if is true
	{
		cout << "a=b\n";
	}
	else if (str1 > str2)
	{
		cout << "a>b\n";
	}
	else if (str1 < str2)
	{
		cout << "a<b\n";
	}

	String str3 = str2.insert(n, temp1);//insert the temp string into str2 in index n

	str3.print();//print the new String

	char tav;
	int index;

	cin >> tav >> index;
	if (str3.length() > 0 && index + 1 < str3.length())//in the rang
	{
		str3[index] = tav;
		str3.print();
	}
	else if (!(str1 == str2)||n>str3.length())//the strings are NOT the same
	{
		cout << "ERROR" << endl;
	}

	return 0;
}