#pragma once
#include <iostream>
#include <list>
#include <queue>
using namespace std;

template <class T>
class VectorQueue
{
private:
	int size;
	queue<T> que;

public:
	VectorQueue();
	VectorQueue(int n);
	~VectorQueue();

	list<T> queueToList(queue<T> que);
	queue<T> listToQueue(list<T> l);

	void print();
	void addMax();
	void deleteWithKey();
	T findAvg(queue<T> que);
	void updateWithAvg();
};

template<class T>
VectorQueue<T>::VectorQueue()
{
	size = 0;
}

template<class T>
VectorQueue<T>::VectorQueue(int n)
{
	size = n;
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		que.push(a);
	}
}

template<class T>
VectorQueue<T>::~VectorQueue()
{
}

template<class T>
list<T> VectorQueue<T>::queueToList(queue<T> que)
{
	list<T> l;
	while (!que.empty())
	{
		l.push_back(que.front());
		que.pop();
	}
	return l;
}

template<class T>
queue<T> VectorQueue<T>::listToQueue(list<T> l)
{
	queue<T> que;
	auto iter = l.begin();
	while (iter != l.end())
	{
		que.push(*iter);
		iter++;
	}
	return que;
}

template<class T>
void VectorQueue<T>::print()
{
	list<T> l = queueToList(que);
	while (!que.empty())
	{
		cout << que.front() << "\t\t";
		que.pop();
	}
	que = listToQueue(l);
	cout << endl;
}

template<class T>
void VectorQueue<T>::addMax()
{
	list<T> l = queueToList(que);
	T max = que.front();
	que.pop();
	while (!que.empty())
	{
		if (que.front() > max)
			max = que.front();
		que.pop();
	}
	que = listToQueue(l);
	que.push(max);
}

template<class T>
void VectorQueue<T>::deleteWithKey()
{
	list<T> l;
	T a;
	cout << "a?\n"; cin >> a;
	while (!que.empty())
	{
		if (que.front() != a)
			l.push_back(que.front());
		que.pop();
	}
	que = listToQueue(l);
}

template<class T>
T VectorQueue<T>::findAvg(queue<T> que)
{
	int len = que.size();
	T avg = que.front();
	que.pop();
	while (!que.empty())
	{
		avg = que.front() + avg;
		que.pop();
	}
	return avg / len;
}

template<class T>
void VectorQueue<T>::updateWithAvg()
{
	list<T> l;
	T avg = findAvg(que);
	while (!que.empty())
	{
		l.push_back(que.front() + avg);
		que.pop();
	}
	que = listToQueue(l);
}