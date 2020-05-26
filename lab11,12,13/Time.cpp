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
	out << t.min << ":" << t.sec;
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

bool  Time::operator > (const Time& t)
{
	return (min*60 + sec) > (t.min * 60 + t.sec);
}

bool  Time::operator < (const Time& t)
{
	return (min * 60 + sec) < (t.min * 60 + t.sec);
}

Time Time::operator+ (const Time& t)
{
	Time temp(0, 0);
	temp.min = min + t.min;
	temp.sec = sec + t.sec;
	while (temp.sec > 59)
	{
		temp.min++;
		temp.sec -= 60;
	}
	return temp;
}

Time Time::operator/ (int s)
{
	return Time(min / s, sec / s);
}