#include "second.h"

// ����� 
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


// ����� ������������� � ���������� � �����
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

// �������� � ������������ ���������
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

// ����� �������� ����� ���� ��������
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

// ���������� �������� ���� ���������
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