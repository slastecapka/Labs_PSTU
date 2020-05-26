#include "fourth.h"

// �� ������� � ������
list<Time> queueToList(queue<Time> que)
{
	list<Time> l;
	while (!que.empty())
	{
		l.push_back(que.front());
		que.pop();
	}
	return l;
}

// �� ������ � �������
queue<Time> listToQueue(list<Time> l)
{
	queue<Time> que;
	auto iter = l.begin();
	while (iter != l.end())
	{
		que.push(*iter);
		iter++;
	}
	return que;
}

void print(queue<Time>& que)
{
	list<Time> l = queueToList(que);
	while (!que.empty())
	{
		cout << que.front() << "\t\t";	// ������� ������
		que.pop();		// ������� ������
	}
	que = listToQueue(l);
	cout << endl;
}

void addMax(queue<Time>& que)
{
	list<Time> l = queueToList(que);
	Time max = que.front();
	que.pop();
	while (!que.empty())
	{
		if (que.front() > max)	// ���� ������������
			max = que.front();
		que.pop();
	}
	que = listToQueue(l);
	que.push(max);	// ��������� � �����
}

void deleteWithKey(queue<Time>& que)
{
	list<Time> l;
	Time a;
	cout << "a?\n"; cin >> a;
	while (!que.empty())
	{
		if (que.front() != a)		// ���� �� ����� 
			l.push_back(que.front()); // ���������
		que.pop();
	}
	que = listToQueue(l);
}

Time findAvg(queue<Time> que)
{
	int len = que.size();
	Time avg = que.front();
	que.pop();
	while (!que.empty())
	{
		avg = que.front() + avg;
		que.pop();
	}
	return avg / len;
}

void updateWithAvg(queue<Time>& que)
{
	list<Time> l;
	Time avg = findAvg(que);
	while (!que.empty())
	{
		l.push_back(que.front() + avg);
		que.pop();
	}
	que = listToQueue(l);
}