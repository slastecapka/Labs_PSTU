#include <iostream>
#include "first.h"
#include "second.h"
#include "Vector.h"
#include "fourth.h"
#include "VectorQueue.h"

#include "lb12.h"

#include "lb13.h"
using namespace std;

void lab11()
{
	// first
	deque<int> deqInt = { 4, 8, 1, 10, -5, 4, 2 };
	cout << "Start: ";  print(deqInt);
	addMax(deqInt); cout << "After add: "; print(deqInt);
	deleteWithKey(deqInt); cout << "After delete: "; print(deqInt);
	updateWithAvg(deqInt); cout << "After update: "; print(deqInt);
	cout << endl;

	// second
	deque<Time> deqTime = { Time(10,20), Time(4,3), Time(100, 20), Time(4,33) };
	cout << "Start: ";  print(deqTime);
	addMax(deqTime); cout << "After add: "; print(deqTime);
	deleteWithKey(deqTime); cout << "After delete: "; print(deqTime);
	updateWithAvg(deqTime); cout << "After update: "; print(deqTime);
	cout << endl;

	// third
	cout << "Read int vector(5) with space: ";
	Vector<int> deqClass(5);
	cout << "Before: "; deqClass.print();
	deqClass.addMax(); cout << "After add: "; deqClass.print();
	deqClass.deleteWithKey(); cout << "After delete: "; deqClass.print();
	deqClass.updateWithAvg(); cout << "After update: "; deqClass.print();
	cout << endl;

	// fourth
	queue<Time> queTime; 
	queTime.push(Time(10, 20)); queTime.push(Time(4, 3)); queTime.push(Time(100, 20)); queTime.push(Time(4, 33));
	cout << "Before: ";  print(queTime);
	addMax(queTime); cout << "After add: "; print(queTime);
	deleteWithKey(queTime); cout << "After delete: "; print(queTime);
	updateWithAvg(queTime); cout << "After update: "; print(queTime);
	cout << endl;

	//fifth
	cout << "Read int VectorQueue(5) with space: ";
	VectorQueue<int> queInt(5);
	cout << "Before: "; queInt.print();
	queInt.addMax(); cout << "After add: "; queInt.print();
	queInt.deleteWithKey(); cout << "After delete: "; queInt.print();
	queInt.updateWithAvg(); cout << "After update: "; queInt.print();
	cout << endl;
}

void lab12()
{
	// first
	map<int, int> mapInt;
	mapInt.insert(make_pair(1, 7)); mapInt.insert(make_pair(2, -5));
	mapInt.insert(make_pair(3, 1)); mapInt.insert(make_pair(4, 10));
	mapInt.insert(make_pair(5, 4)); mapInt.insert(make_pair(6, 8));
	cout << "Before: "; print(mapInt);
	addMax(mapInt); cout << "After add: "; print(mapInt);
	cout << endl;

	//second
	map<int, Time> mapTime;
	mapTime.insert(make_pair(1, Time(10, 20))); mapTime.insert(make_pair(2, Time(4, 3)));
	mapTime.insert(make_pair(3, Time(100, 20))); mapTime.insert(make_pair(4, Time(4, 33)));
	cout << "Before: "; print(mapTime);
	deleteWithKey(mapTime); cout << "After delete: "; print(mapTime);
	cout << endl;

	//third
	VectorMap<int, int> vMap(4);
	cout << "Before: "; vMap.print();
	vMap.updateWithAvg(); cout << "After update: "; vMap.print();
	cout << endl;
}

bool operator== (const Time& item, const Time& value)
{
	return item == value;
}

void lab13()
{
	// first
	deque<Time> deqTime = { Time(10,20), Time(4,3), Time(100, 20), Time(4,33) };
	// ÂÛÂÎÄ
	auto printTime = [](Time& t) { cout << t.getMin() << ":" << t.getSec() << "\t"; };
	cout << "Before: ";  for_each(deqTime.begin(), deqTime.end(), printTime); cout << endl;
	// ÄÎÁÀÂËÅÍÈÅ ÌÀÊÑÈÌÀËÜÍÎÃÎ Â ÊÎÍÅÖ
	auto max = max_element(deqTime.begin(), deqTime.end());
	deqTime.push_back(*max);
	cout << "After add: "; for_each(deqTime.begin(), deqTime.end(), printTime); cout << endl;
	//  ÓÄÀËÅÍÈÅ ÏÎ ÊËŞ×Ó
	Time a;
	cout << "a?\n"; cin >> a;
	auto elem = find(deqTime.begin(), deqTime.end(), a);
	if (elem != deqTime.end())
	{
		auto timeEqual = [elem](Time& t2) { return *elem == t2; };
		elem = remove_if(deqTime.begin(), deqTime.end(), timeEqual);
		deqTime.erase(elem, deqTime.end());
		cout << "After delete: "; for_each(deqTime.begin(), deqTime.end(), printTime); cout << endl;
	}
	else
		cout << "Havent't element\n";
	// ÏÎÈÑÊ ÑĞÅÄÍÅÃÎ
	Time avg;
	auto findAvg = [&avg](Time& t) { avg = t + avg; };
	for_each(deqTime.begin(), deqTime.end(), findAvg);
	avg = avg / deqTime.size();
	// ÄÎÁÀÂËÅÍÈÅ ÑĞÅÄÍÅÃÎ ÊÎ ÂÑÅÌ
	auto sumAvg = [&avg](Time& t) { t = t + avg; };
	for_each(deqTime.begin(), deqTime.end(), sumAvg);
	cout << "After update: "; for_each(deqTime.begin(), deqTime.end(), printTime); cout << endl;
	// ÑÎĞÒÈĞÎÂÊÀ
	sort(deqTime.begin(), deqTime.end());
	cout << "After sort: "; for_each(deqTime.begin(), deqTime.end(), printTime); cout << endl;
	cout << endl;

	// second
	queue<Time> que; 
	list<Time> temp;
	// ÊÎÏÈĞÎÂÀÍÈÅ Â ÑÏÈÑÎÊ
	que.push(Time(10, 20)); que.push(Time(4, 3)); que.push(Time(100, 20)); que.push(Time(4, 33));
	for (int i = 0; i < que.size(); i++)
	{
		temp.push_back(que.front());
		que.pop();
	}
	// ÂÛÂÎÄ
	cout << "Before: ";  for_each(temp.begin(), temp.end(), printTime); cout << endl;
	cout << "Î÷åğåäü ñêîïèğîâàíà â list è ïîëíîñòüş áóäåò ïîâòîğÿòü ôóíêöèîíàë deque<Time>, âûïîëíåíèå àíîëîãè÷íî\n";
	cout << endl;

	// third
	multimap<int, Time> map;
	map.insert(make_pair(1, Time(10, 20))); map.insert(make_pair(9, Time(4, 3)));
	map.insert(make_pair(3, Time(100, 20))); map.insert(make_pair(7, Time(4, 33)));
	// ÂÛÂÎÄ
	auto printPair = [](pair<int, Time> p) {cout << p.first << " - " << p.second<<"\t\t"; };
	cout << "Before: ";  for_each(map.begin(), map.end(), printPair); cout << endl;
	// ÄÎÁÀÂËÅÍÈÅ ÌÀÊÑÈÌÀËÜÍÎÃÎ
	auto pairGreater = [](pair<int, Time> p1, pair<int, Time> p2) { return p1.second < p2.second;  };
	auto maxPair = max_element(map.begin(), map.end(), pairGreater);
	map.insert(make_pair(10000000, maxPair->second));
	cout << "After add: ";  for_each(map.begin(), map.end(), printPair); cout << endl;
	// ÓÄÀËÅÍÈÅ ÏÎ ÊËŞ×Ó
	int key;
	cout << "key? "; cin >> key;
	auto findKey = [key](pair<int, Time> t) {return t.first == key; };
	auto findPair = find_if(map.begin(), map.end(), findKey);
	if (findPair != map.end())
	{
		map.erase(key);
		cout << "After delete: ";  for_each(map.begin(), map.end(), printPair); cout << endl;
	}
	else
		cout << "Havent't key\n";
	// ÏÎÈÑÊ ÑĞÅÄÍÅÃÎ
	avg = Time(0, 0);
	auto findAvgMap = [&avg](pair<int, Time> t) { avg = t.second + avg; };
	for_each(map.begin(), map.end(), findAvgMap);
	avg = avg / deqTime.size();
	// ÄÎÁÀÂËÅÍÈÅ ÊÎ ÂÑÅÌ
	auto sumAvgMap = [&avg](pair<int, Time> t) { t.second = t.second + avg; };
	for_each(map.begin(), map.end(), sumAvgMap);
	cout << "After update: "; for_each(map.begin(), map.end(), printPair); cout << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "1. lab 11\n2. lab12\n3. lab13\n>";
	int x; cin >> x;
	switch(x)
	{
	case 1: lab11();  break;
	case 2: lab12(); break;
	case 3: lab13();  break;
	}
	return 0;
}