#include <iostream>
#include "Time.h"
#include "Vector.h"
using namespace std;

int main()
{
	Vector<int> vInt(4, 3);
	Vector<float> vFloat(5, 0);
	cout << "Read Float vector 5 elements\n";
	cin >> vFloat;
	Vector<double> vDouble(3, 4.5);
	cout << "vInt: " << vInt << endl;
	cout << "vFloat: " << vFloat << endl;
	cout << "vDouble: " << vDouble << endl;
	cout << "vInt[2] = " << vInt[2] << endl;
	cout << "vFloat size = " << vFloat() << endl;
	cout << "vDouble * 3: " << (vDouble * 3) << endl;

	Time t;
	Vector<Time> vTime(3, t);
	cout << "Read Time vector 3 elements\n";
	cin >> vTime;
	cout << "vTime: " << vTime << endl;
	cout << "vTime[1] = " << vTime[1] << endl;
	cout << "vTime size = " << vTime() << endl;
	cout << "vTime*3: " << (vTime * 3) << endl;
	return 0;
}