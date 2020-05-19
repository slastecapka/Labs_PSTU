#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	Vector A(4, 7);
	Vector B(6);
	cin >> B;
	Vector C = B;
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	cout << "C: " << C << endl;
	cout << "B[3]=" << B[3] << endl;
	cout << "A length = " << A() << endl;
	cout << "C*3: " << (C * 3) << endl;

	Iterator a = B.first();
	++a;
	cout << "B - Iterator after first()++: " << (*a) << endl;
	++a; ++a; ++a; ++a;
	cout << "B - Iterator before (a-3): " << (*a) << endl;
	cout << "B - Iterator after (a-3): " << *(a - 4) << endl;
	
	cout << "A with iterator: ";
	for (Iterator it = A.first(); it != A.last(); ++it)
		cout << (*it) << "\t";
	cout << endl;
	return 0;
}