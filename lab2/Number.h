#pragma once

#include <iostream>
using namespace std;

class Number
{
private:
	float mantissa;
	int exponent;
	string str;

public:
	Number();
	Number(float m, int e, string s);
	Number(const Number&);

	~Number();

	float getMantissa();
	int getExponent();
	string getStr();

	void setMantissa(float m);
	void setExponent(int e);
	void setStr(string s);

	void show();
};
