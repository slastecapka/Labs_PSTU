#pragma once

#include "Object.h"

class Vector
{
private:
	Object** beg;
	int size;
	int cur;

public:
	Vector();
	Vector(int);
	~Vector();

	void add(Object* obj);
	friend ostream& operator<< (ostream& out, const Vector& v);
};
