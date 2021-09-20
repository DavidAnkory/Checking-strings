/*
David Ankory 206780066
Workshop in C ++
Exercise 3 Question 2
The date.cpp file Includes all the codes of the functions
*/
#include <iostream>
#include "String.h"
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

String::String(const char* str)//set the str
{
	setString(str);
}

String::String() : String("") {}

String::String(const String& str) : String(str.array)
{
}

String::~String()
{
	delete[] array;
}

String& String::operator=(const String& str)
{
	if (&str != this) {
		delete[] array;

		setString(str.array);
	}

	return *this;
}


char& String::at(int index)
{
	if (index < 0 || index > len); // throw exception

	return array[index];
}

char& String::operator[](int index) {
	if (index < 0 || index > len); // throw exception
		//cout << "ERROR\n";

	return array[index];
}

bool String::operator==(const String& str)//chek if they are eqel even in small laters or big letter
{
	bool flag = true;
	int HSCI1 = 0;//the letter frome array
	int HSCI2 = 0;//the letter frome str
	if (len == str.len)//one chek
	{
		for (size_t i = 0; i < len; i++)
		{
			HSCI1 = (int)array[i];//get the haski value
			HSCI2 = (int)str.array[i];
			if (HSCI1 == HSCI2 + 32 || HSCI1 + 32 == HSCI2 || HSCI1 == HSCI2)//if ther is A and a
			{
				flag;//true
			}
			else
			{
				return false;//return not eqal
			}
		}
		return flag;
	}
	else//not even heve a chech the are eqoal
	{
		return false;
	}
}

bool String::operator<(const String& str)
{
	return strcmp(array, str.array) < 0;//strcmp chek
}

bool String::operator>(const String& str)
{
	return strcmp(array, str.array) > 0;
}

bool String::operator<=(const String& str)
{
	return strcmp(array, str.array) <= 0;
}

bool String::operator>=(const String& str)
{
	return strcmp(array, str.array) >= 0;
}

bool String::operator!=(const String& str)
{
	return strcmp(array, str.array) != 0;
}


void String::setString(const char* str)// deep copy
{

	if (str == NULL)//if is empty
		str = "";

	len = strlen(str);
	array = new char[len + 1];
	strcpy(array, str);
}

void String::print()
{
	cout << array << endl;
}

String String::insert(int index, const char* str)
{
	String cut_str;//nee cut string
	int len_str = strlen(str);//get the len of str

	if (index < 0 || index > len_str)//not in the range
	{
		cout << "ERROR\n";
		return cut_str;
	}

	cut_str.len = len + len_str + 1;//+1 for '\0'
	char* array = new char[cut_str.len];//new dinamic str

	for (int i = 0; i < index; i++)//copy until the index is needed
		array[i] = this->array[i];

	array[index] = '\0';//get null
	strcat(array, str);//fat the strings

	for (int i = index; i < this->len; i++)//get the else frome the string
		array[i + len_str] = this->array[i];

	array[len_str + len] = '\0';//get the null

	cut_str.array = array;//get the data
	array = NULL;

	return cut_str;
}