#include "Complex.h"

Complex& Complex::operator= (const Complex& c)
{
	if (&c == this)
		return *this;
	first = c.first;
	second = c.second;
	return *this;
}

istream& operator>> (istream& in, Complex& c)
{
	cout << "A ? "; in >> c.first;
	cout << "B? "; in >> c.second;
	return in;
}

ostream& operator<< (ostream& out, const Complex& c)
{
	out << "Complex: ";
	out << c.first;
	out << "+\(";
	out << c.second;
	out << "j\)";
	return out;
}

Complex Complex::operator* (const Complex& c)
{
	Complex temp;
	temp.first = first * c.first - second * c.second;
	temp.second = first * c.first + second * c.second;
	return temp;
}

Complex Complex::operator- (const Complex& c)
{
	return Complex(first - c.first, second - c.second);
}