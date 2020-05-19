#include "Pair.h"

Pair& Pair::operator= (const Pair& p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}

istream& operator>> (istream& in, Pair& p)
{
	cout << "first? "; in >> p.first;
	cout << "second? "; in >> p.second;
	return in;
}

ostream& operator<< (ostream& out, const Pair& p)
{
	return (out << "Pair: (" << p.first << ", " << p.second << ")");
}

Pair Pair::operator+ (const Pair& p)
{
	return Pair(first + p.first, second + p.second);
}

void Pair::show()
{
	cout << *this << endl;
}