#include <iostream>
#include "Vector.h"
#include "Complex.h"
using namespace std;

int main()
{
	Vector v(5);
	v.add(&Pair(3, 7));
	v.add(&Pair(100, 200));
	v.add(&Complex(33, 77));
	v.add(&Complex(99, -10));
	cout << v << endl;
	return 0;
}