#include "Vector.h"

#include "Book.h"

Vector::Vector()
{
	beg = 0;
	size = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	size = n;
	curr = 0;
}

Vector::~Vector()
{
	if (curr != 0)
		delete[] beg;
	beg = 0;
}

void Vector::add()
{
	if (curr == size)
	{
		cout << "Error. Not place for add\n";
		return;
	}
	int sw;
	cout << "What add?\n1. Print\n2. Book\n"; cin >> sw;
	Object* obj;
	if (sw == 1)
		obj = new Print();
	else if (sw == 2)
		obj = new Book();
	else
		return;
	obj->input();
	beg[curr++] = obj;
}

void Vector::del()
{
	if (curr == 0)
	{
		cout << "Error. Group is empty\n";
		return;
	}
	delete beg[--curr];
}

void Vector::show()
{
	if (curr == 0)
		cout << "Empty\n";
	Object** p = beg;
	for (int i = 0; i < curr; i++, p++)
	{
		(*p)->show();
		cout << endl;
	}
}

int Vector::operator() ()
{
	return curr;
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < curr; i++, p++)
		{
			(*p)->HandleEvent(e);
			cout << endl;
		}
	}
}