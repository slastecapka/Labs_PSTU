#include "lb12.h"

//first
void print(map<int, int> dic)
{
	for (auto it = dic.begin(); it != dic.end(); it++)
		cout << it->first << ":" << it->second << "\t\t";
	cout << endl;
}

void addMax(map<int, int>& dic)
{
	auto it = dic.begin();
	int max = it->second;
	it++;
	while (it != dic.end())
	{
		if (it->second > max)
			max = it->second;
		it++;
	}
	dic.insert(make_pair(1000000, max));
}


//second
void print(map<int, Time> dic)
{
	for (auto it = dic.begin(); it != dic.end(); it++)
		cout << it->first << " - " << it->second << "\t\t";
	cout << endl;
}

void deleteWithKey(map<int, Time>& dic)
{
	int key;
	cout << "key? "; cin >> key;
	if (dic.erase(key) == 0)
		cout << "Haven't element with this key\n";
}