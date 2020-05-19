#include <iostream>
#include "Number.h"
using namespace std;

void printNumber(Number& num)
{ 
	num.show();
}


Number getNumber()
{
	Number temp(6.2174, 7, "62174000");
	return temp;
}


int main()
{
	Number n1;
	cout << "Without param: ";
	n1.show();
	Number n2(4.1, 3, "41000");
	cout << "With param: ";
	n2.show();
	Number n3 = n2;
	cout << "With copy: ";
	n3.show();
	cout << "Setters and getter for n3: ";
	n3.setStr("466400000");
	n3.setMantissa(4.664);
	n3.setExponent(8);
	cout << n3.getStr() << ", M=" << n3.getMantissa() << ", p=" << n3.getExponent() << endl;
	Number n4 = getNumber();
	cout << "With copy #3: ";
	printNumber(n4);
	return 0;
}