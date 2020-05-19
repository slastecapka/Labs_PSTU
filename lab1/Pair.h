#pragma once

//
struct Pair
{
	double first, second;

	void init(double f, double s);
	void read();
	void show();
	bool rangeCheck(double x);
};
