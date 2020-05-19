#pragma once

#include "Pair.h"

class Complex : public Pair
{	
public:
	Complex() :Pair() { }
	Complex(int d, int m) : Pair(d, m) { }
	Complex(const Complex& c) : Pair(c) { }

	Complex& operator= (const Complex& c);
	friend istream& operator>> (istream& in, Complex& c);
	friend ostream& operator<< (ostream& out, const Complex& c);

	Complex operator* (const Complex& c);
	Complex operator- (const Complex& c);
};
