#pragma once

#include <iostream>
using namespace std;

class Time
{
private:
	int min, sec;

public:
	Time() { min = sec = 0; }
	Time(int m, int s) { min = m; sec = s; }
	Time(const Time& t) { min = t.min; sec = t.sec; }
	~Time() {}
	int getMin() { return min; }
	int getSec() { return sec; }
	void setMin(int m) { min = m; }
	void setSec(int s) { sec = s; }
	Time& operator= (const Time& t);
	friend istream& operator>> (istream& in, Time& t);
	friend ostream& operator<< (ostream& out, const Time& t);
	Time operator+ (int s);
	bool operator== (const Time& t);
	bool operator!= (const Time& t);
};
