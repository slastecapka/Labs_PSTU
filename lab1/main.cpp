#include <iostream>
#include "Pair.h"
using namespace std;

Pair& make_pair(double f, double s)
{

	Pair temp;
	if (s < f) {
		cout << "Error, second <= first\n";
		return temp; 
	}
	temp.init(f, s);
	return temp;
}

class Student
{
	string name;
};

int main()
{
	Pair A, B;
	A.init(1, 7);
	B.read();
	A.show();
	B.show();
	cout << "4 in A: " << A.rangeCheck(4)<<endl;
	cout << "2 in B: " << B.rangeCheck(2)<<endl;
	cout << "From function\n";
	double f, s;
	cout << "Read first: ";
	cin >> f;
	cout << "Read second: ";
	cin >> s;
	Pair C = make_pair(f, s);
	C.show();

	return 0;
}