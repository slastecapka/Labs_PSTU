#pragma once

#include <iostream>
#include "Error.h"
using namespace std;

class Vector
{
private:
	int size;
	int* data;

public:
	Vector(int s, int k = 0);
	Vector(const Vector& v);
	~Vector();

	Vector& operator= (const Vector& v);
	friend ostream& operator<< (ostream& out, const Vector& v);
	friend istream& operator>> (istream& in, Vector& v);

	int& operator[] (int index); // �� �������
	int operator() ();// ����������� �������

	Vector& operator-- ();	// ����������
	Vector operator-- (int); // �����������
};
