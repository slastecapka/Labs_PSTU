#include "Number.h"

Number::Number(float m, int e, string s)
{
	mantissa = m;
	exponent = e;
	str = s;
}

Number::Number()
{
	mantissa = 1,201;
	exponent = 6;
	str = "1201000";
}

Number::Number(const Number& num)
{
	mantissa = num.mantissa;
	exponent = num.exponent;
	str = num.str;
}

Number::~Number()
{
	str.clear();
}

float Number::getMantissa()
{
	return mantissa;
}

int Number::getExponent()
{
	return exponent;
}

string Number::getStr()
{
	return str;
}

void Number::setMantissa(float m)
{
	mantissa = m;
}

void Number::setExponent(int e)
{
	exponent = e;
}

void Number::setStr(string s)
{
	str = s;
}

void Number::show()
{
	cout << str << ", M=" << mantissa << ", p=" << exponent << endl;
}