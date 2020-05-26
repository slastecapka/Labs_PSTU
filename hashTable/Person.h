#pragma once

#include <iostream>
using namespace std;

class Person
{
private:
	string fName, sName, tName;
	string passport; // key
	string adress;

public:
	Person() {}
	Person(string f, string s, string t, string p, string a) { fName = f; sName = s; tName = t; passport = p; adress = a; }
	~Person() { }

	string getPassport() { return passport; }

	int getHashCode();	// получение хэш-кода ключа - номер паспорта
	friend ostream& operator<< (ostream& out, const Person& p);
};
