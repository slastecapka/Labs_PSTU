#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Vector
{
private:
	int size;
	vector<T> v;

public:
	Vector();
	Vector(int n);
	~Vector();
	
	void print();
	void addMax();
	void deleteWithKey();
	T findAvg();
	void updateWithAvg();
};

template<class T>
Vector<T>::Vector()
{
	size = 0;
}

template<class T>
Vector<T>::Vector(int n)
{
	size = n;
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
}

template<class T>
Vector<T>::~Vector()
{
}

template<class T>
void Vector<T>::print()
{
	auto iter = v.begin();
	while (iter != v.end())
	{
		cout << *iter << "\t\t";
		iter++;
	}
	cout << endl;
}

template<class T>
void Vector<T>::addMax()
{
	auto iter = v.begin();
	T max = *iter++;
	while (iter != v.end())
	{
		if (*iter > max)
			max = *iter;
		iter++;
	}
	v.insert(v.end(), max);
}

template<class T>
void Vector<T>::deleteWithKey()
{
	T a;
	cout << "a?\n"; cin >> a;
	auto iter = v.begin();
	while (iter != v.end())
	{
		if (*iter == a)
		{
			v.erase(iter);
			return;
		}
		iter++;
	}
	cout << "Haven't this key\n";
}

template<class T>
T Vector<T>::findAvg()
{
	T avg = 0;
	auto iter = v.begin();
	while (iter != v.end())
	{
		avg = *iter + avg;
		iter++;
	}
	return avg / v.size();
}

template<class T>
void Vector<T>::updateWithAvg()
{
	T avg = findAvg();
	auto iter = v.begin();
	while (iter != v.end())
	{
		*iter = *iter + avg;
		iter++;
	}
}
