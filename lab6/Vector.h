#pragma once

#include <iostream>
using namespace std;

class Iterator
{
	friend class Vector;
private:
	int* elem;

public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }

	bool operator== (const Iterator& it) { return elem == it.elem; }
	bool operator!= (const Iterator& it) { return elem != it.elem; }

	void operator++ () { ++elem; }
	void operator-- () { --elem; }
	int& operator*() const { return *elem; }

	Iterator& operator- (int n);
};

class Vector
{
private:
	int size;
	int* data;

	Iterator beg;
	Iterator end;

public:
	Vector(int s, int k=0);
	Vector(const Vector& v);
	~Vector();

	Vector& operator= (const Vector& v);
	friend ostream& operator<< (ostream& out, const Vector& v);
	friend istream& operator>> (istream& in, Vector& v);

	int& operator[] (int index); // по индексу
	int operator() ();// определение размера
	Vector operator* (int a); // умножает все элементы на число

	Iterator first() { return beg; }
	Iterator last() { return end; }
};
