#include "Time.h"

Time& Time::operator= (const Time& t)
{
	if (&t == this)
		return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

istream& operator>> (istream& in, Time& t)
{
	cout << "min? "; in >> t.min;
	cout << "sec? "; in >> t.sec;
	while (t.sec > 59)
	{
		t.min++;
		t.sec -= 60;
	}
	return in;
}

ostream& operator<< (ostream& out, const Time& t)
{
	out << t.min << " : " << t.sec;
	return out;
}

Time Time::operator+ (int s)
{
	Time temp;
	sec += s;
	while (sec > 59)
	{
		min++;
		sec -= 60;
	}
	temp.min = min;
	temp.sec = sec;
	return temp;
}

bool Time::operator== (const Time& t)
{
	if (min == t.min && sec == t.sec)
		return true;
	return false;
}

bool Time::operator!= (const Time& t)
{
	if (min != t.min || sec != t.sec)
		return true;
	return false;
}