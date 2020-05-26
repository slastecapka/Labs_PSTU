#pragma once

#include <iostream>
#include <map>
#include "Time.h"
using namespace std;

//first
void print(map<int, int> dic);

void addMax(map<int, int>& dic);


//second
void print(map<int, Time> dic);

void deleteWithKey(map<int, Time>& dic);

//third
template <class K, class V>
class VectorMap
{
private:
	map<K, V> dic;

public:
	VectorMap(int n);
	~VectorMap();

	void print();
	V findAvg(map<K, V> dic);
	void updateWithAvg();
};

template <class K, class V>
VectorMap<K, V>::VectorMap(int n)
{
	K key;
	V value;
	for (int i = 0; i < n; i++)
	{
		cout << "key? "; cin >> key;
		cout << "value? "; cin >> value;
		dic.insert(make_pair(key, value));
	}
}

template <class K, class V>
VectorMap<K, V>::~VectorMap()
{
}

template <class K, class V>
void VectorMap<K, V>::print()
{
	for (auto it = dic.begin(); it != dic.end(); it++)
		cout << it->first << ":" << it->second << "\t\t";
	cout << endl;
}

template <class K, class V>
V VectorMap<K, V>::findAvg(map<K, V> dic)
{
	V avg = 0;
	for (auto it = dic.begin(); it != dic.end(); it++)
		avg = it->second + avg;
	return avg / dic.size();
}

template <class K, class V>
void VectorMap<K, V>::updateWithAvg()
{
	V avg = findAvg(dic);
	for (auto it = dic.begin(); it != dic.end(); it++)
		it->second = it->second + avg;
}
