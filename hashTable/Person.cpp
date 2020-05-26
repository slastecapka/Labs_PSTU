#include "Person.h"

int Person::getHashCode()
{
	int sum = 0;
	for (int i = 0; i < passport.size(); i++)
		sum += (i + 1) * passport[i];
	return sum;
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << p.fName << " " << p.sName << " " << p.tName << ", " << p.passport << ", " << p.adress;
	return out;
}
