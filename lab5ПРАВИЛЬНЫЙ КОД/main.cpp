#include <iostream>
#include "Vector.h"
#include "Complex.h"
using namespace std;

int main()
{
	Vector v(5);
	Pair p1(3, 7);
	Pair p2(100, 200);
	Complex c1(33, 77);
	Complex c2(99, -10);
	cout << "c1 - " << c1 << endl;
	cout << "c2 - " << c2 << endl;
	cout << "c1 * c2 = " << (c1 * c2) << endl;
	cout << "c1 - c2 = " << (c1 - c2) << endl;
	cout << "Vector\n";
	v.add((Object*)&p1);
	v.add((Object*)&p2);
	v.add((Object*)&c1);
	v.add((Object*)&c2);

	cout << v << endl;
	return 0;
}