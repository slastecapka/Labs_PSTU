#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time A;
	Time B(5, 40);
	cout << "Read time interval A\n";
	cin >> A;
	Time C = A;
	cout << A << B << C;
	cout << "Interval C after add 27 sec: " << (C + 27);
	cout << "A == B: " << (A == B) << endl;
	cout << "A != B: " << (A != B) << endl;
	return 0;
}