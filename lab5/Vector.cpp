#include "Vector.h"

Vector::Vector()
{
	beg = 0; 
	size = 0; 
	cur = 0;
}

Vector::Vector(int n)
{
	beg = new Object*[n];
	cur = 0;
	size = n;
}

Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
	beg = 0;
}

void Vector::add(Object* obj)
{
	if (cur < size)
		beg[cur++] = obj;
}

ostream& operator<< (ostream& out, const Vector& v)
{
	if (v.size == 0)
		cout << "Empty\n";
	Object** p = v.beg;
	for (int i = 0; i < v.cur; i++)
	{
		(*p)->show();
		p++;
	}
	return out;
}