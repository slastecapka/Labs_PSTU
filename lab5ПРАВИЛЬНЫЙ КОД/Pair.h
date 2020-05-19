#pragma once

#include <iostream>
#include "Object.h"
using namespace std;

class Pair: public Object
{
protected:
	int first, second;

public:
	Pair() { first = second = 0; }
	Pair(int f, int s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() { }
	int getFirst() { return first; }
	int getSecond() { return second; }
	void setFirst(int f) { first = f; }
	void setSecond(int s) { second = s; }

	Pair& operator= (const Pair& p);
	friend istream& operator>> (istream& in, Pair& p);
	friend ostream& operator<< (ostream& out, const Pair& p);
	Pair operator+ (const Pair& p);

	void show();
};
