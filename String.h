/*
David Ankory 206780066
Workshop in C ++
Exercise 3 Question 3
The h file includes the names of the functions and their definition
*/
#pragma once
class String
{
private:
	void setString(const char*);

	int len; // cache length
	char* array;
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	String& operator=(const String&);

	// concatenation operator
	String operator+(const String&);

	// subscript operator
	char& at(int index);
	char& operator[](int index);

	// relational operators
	bool operator==(const String&);
	bool operator<(const String&);
	bool operator>(const String&);
	bool operator<=(const String&);
	bool operator>=(const String&);
	bool operator!=(const String&);

	int length() { return len; }
	bool empty() { return length() == 0; }

	bool contains(const String&);
	String substr(int start, int end);

	void print();

	String insert(int index, const char* str);
};


