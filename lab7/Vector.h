#pragma once
#include <iostream>
using namespace std;

template <class T>
class Vector
{
private:
	int size;
	T* data;

public:
	Vector(int n, T k);
	Vector(const Vector<T>& v);
	~Vector();

	Vector& operator= (const Vector& v);
	friend ostream& operator<< <>(ostream& out, const Vector<T>& v);
	friend istream& operator>> <>(istream& in, Vector<T>& v);

	T& operator[] (int index); // по индексу
	int operator() ();// определение размера
	Vector<T> operator* (int a); // умножает все элементы на число
};

template<class T>
Vector<T>::Vector(int n, T t)
{
	size = n;
	data = new T[n];
	for (int i = 0; i < n; i++)
		data[i] = t;
}

template<class T>
Vector<T>::Vector(const Vector& v)
{
	size = v.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = v.data[i];
}

template<class T>
Vector<T>::~Vector()
{
	delete[] data;
	data = 0;
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
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

template<class T>
istream& operator>> (istream& in, Vector<T>& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << "v[" << i << "]? ";
		in >> v.data[i];
	}
	return in;
}

template<class T>
ostream& operator<< (ostream& out, const Vector<T>& v)
{
	if (v.size == 0)
		out << "Empty";
	for (int i = 0; i < v.size; i++)
		out << v.data[i] << "\t";
	return out;
}

template<class T>
T& Vector<T>::operator[] (int index)
{
	if (index < size)
		return data[index];
	cout << "Error index. Index > size\n";
}

template<class T>
int Vector<T>::operator() ()
{
	return size;
}

template<class T>
Vector<T> Vector<T>::operator* (int a)
{
	Vector temp(*this);
	for (int i = 0; i < size; i++)
		temp.data[i] = data[i] * a;
	return temp;
}

