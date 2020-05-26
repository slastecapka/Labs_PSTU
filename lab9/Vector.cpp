#include "Vector.h"


Vector::Vector(int n, int k)
{
	size = n;
	data = new int[n];
	for (int i = 0; i < n; i++)
		data[i] = k;
}

Vector::Vector(const Vector& v)
{
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

Vector::~Vector()
{
	delete[] data;
	data = 0;
}

Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	if (data != 0)
		delete[] data;
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	return *this;
}

istream& operator>> (istream& in, Vector& v)
{
	if (v.size == 0)
		throw 2;
	for (int i = 0; i < v.size; i++)
	{
		cout << "v[" << i << "]? ";
		in >> v.data[i];
	}
	return in;
}

ostream& operator<< (ostream& out, const Vector& v)
{
	if (v.size == 0)
		throw 3;
	for (int i = 0; i < v.size; i++)
		out << v.data[i] << "\t";
	return out;
}

int& Vector::operator[] (int index)
{
	if (index < size && index >= 0)
		return data[index];
	throw error("Error index");
}

int Vector::operator() ()
{
	return size;
}

Vector& Vector::operator-- ()
{
	if (size == 0)
		throw error("Error. Empty");
	int* temp = new int[size-1];
	for (int i = 1; i < size; i++)
		temp[i-1] = data[i];
	delete[] data;
	data = temp;
	size--;
	return *this;
}

Vector Vector::operator-- (int)
{
	if (size == 0)
		throw error("Error. Empty");
	Vector v = *this;
	int* temp = new int[size - 1];
	for (int i = 0; i < size - 1; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	size--;
	return v;
}
