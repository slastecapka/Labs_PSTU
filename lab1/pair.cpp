#include <iostream>
#include "Pair.h"
using namespace std;

void Pair::init(double f, double s)
{
	first = f;
	second = s;
}

void Pair::read() 
{
	do
	{
		cout << "Read first: ";
		cin >> first;
		cout << "Read second: ";
		cin >> second;
		if (second >= first)
			break;
		cout << "Error, second <= first, repeat ...\n";
	} while (true);
}

void Pair::show()
{
	cout << "[" << first << ", " << second << "]\n";
}

bool Pair::rangeCheck(double x)
{
	if (x >= first && x <= second)
		return true;
	return false;
}