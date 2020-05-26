#include "first.h"

void print(deque<int>& deq)
{
	deque<int>::iterator iter = deq.begin();
	while (iter != deq.end())
	{
		cout << *iter << "\t";
		iter++;
	}
	cout << endl;
}

void addMax(deque<int>& deq)
{
	deque<int>::iterator iter = deq.begin();
	int max = *iter++;
	while (iter != deq.end())
	{
		if (*iter > max)
			max = *iter;
		iter++;
	}
	deq.push_back(max);
}


void deleteWithKey(deque<int>& deq)
{
	int a;
	cout << "a? "; cin >> a;
	deque<int>::iterator iter = deq.begin();
	while (iter != deq.end())
	{
		if (*iter == a)
		{
			deq.erase(iter);
			return;
		}
		iter++;
	}
	cout << "Haven't this key\n";
}

float findAvg(deque<int>& deq)
{
	float avg = 0;
	deque<int>::iterator iter = deq.begin();
	while (iter != deq.end())
	{
		avg += *iter;
		iter++;
	}
	return avg / deq.size();
}

void updateWithAvg(deque<int>& deq)
{
	float avg = findAvg(deq);
	deque<int>::iterator iter = deq.begin();
	while (iter != deq.end())
	{
		*iter += avg;
		iter++;
	}
}