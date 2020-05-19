#include "Vector.h"


Vector::Vector(int n, int k)
{
	size = n;
	data = new int[n];
	for (int i = 0; i < n; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}

Vector::Vector(const Vector& v)
{
	size = v.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
	beg = v.beg;
	end = v.end;
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
	beg = v.beg;
	end = v.end;
	return *this;
}

istream& operator>> (istream& in, Vector& v)
{
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
		out << "Empty";
	for (int i = 0; i < v.size; i++)
		out << v.data[i]<<"\t";
	return out;
}

int& Vector::operator[] (int index)
{
	if (index < size)
		return data[index];
	cout << "Error index. Index > size\n";
}

int Vector::operator() ()
{
	return size;
}

Vector Vector::operator* (int a)
{
	Vector temp(size);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] * a;
	return temp;
}

Iterator& Iterator::operator-(int n)
{
	for (int i = 0; i < n; i++)
		--elem;
	return *this;
}
