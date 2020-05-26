#include "second.h"

// вывод 
void print(deque<Time>& deq)
{
	deque<Time>::iterator iter = deq.begin();
	while (iter != deq.end())
	{
		cout << *iter << "\t\t";
		iter++;
	}
	cout << endl;
}


// поиск максимального и добавление в конец
void addMax(deque<Time>& deq)
{
	deque<Time>::iterator iter = deq.begin();
	Time max = *iter++;
	while (iter != deq.end())
	{
		if (*iter > max)
			max = *iter;
		iter++;
	}
	deq.push_back(max);
}

// удаление с определенным значением
void deleteWithKey(deque<Time>& deq)
{
	Time a;
	cout << "a?\n"; cin >> a;
	deque<Time>::iterator iter = deq.begin();
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

// поиск среднего среди всех значений
Time findAvg(deque<Time>& deq)
{
	Time avg(0, 0);
	deque<Time>::iterator iter = deq.begin();
	while (iter != deq.end())
	{
		avg = *iter + avg;
		iter++;
	}
	return avg / deq.size();
}

// добавление среднего всем значениям
void updateWithAvg(deque<Time>& deq)
{
	Time avg = findAvg(deq);
	deque<Time>::iterator iter = deq.begin();
	while (iter != deq.end())
	{
		*iter = *iter + avg;
		iter++;
	}
}