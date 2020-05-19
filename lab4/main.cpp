#include <iostream>
#include "Complex.h"
using namespace std;

void f1(Pair& p)
{
	p.setFirst(1000);
	p.setSecond(2000);
	cout << p << endl;
}

Pair f2()
{
	return Complex(200, -200);
}

int main()
{
	Pair p1;
	cin >> p1;
	Pair p2(33, 66);
	cout << p1 << endl;
	cout << p2 << endl;
	cout << "p1 + p2 = " << (p1 + p2) << endl;

	Complex c1;
	cin >> c1;
	Complex c2(10, 10);
	cout << c1 << endl;
	cout << c2 << endl;
	cout << "c1 * c2 =" << (c1 * c2) << endl;
	cout << "c1 - c2 = " << (c1 - c2) << endl;

	// Принцип подстановки
	f1(c1);
	Pair p3 = f2();
	cout << p3 << endl;
	return 0;
}