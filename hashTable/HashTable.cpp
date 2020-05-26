#include "HashTable.h"

HashTable::HashTable(int n)
{
	size = n;
	table = new TableElement * [size];
	for (int i = 0; i < size; i++)
		table[i] = 0;		// ��������� ��� ������� � ������ ������
}

HashTable::~HashTable()
{
	clear();
	delete[] table;
}

int HashTable::getHastCode(int k)
{
	float x;
	float sum = k * A;
	int y = modf(k * A, &x) * 10000; // ����� ����� ��������� � x, ������� - � y
	int ind = y % size;	// ������� �� �������
	return ind;
}

void HashTable::add(Person& p)
{
	int ind = getHastCode(p.getHashCode());
	TableElement* el = new TableElement(p);
	if (table[ind] == 0)	// ���� � ������ ��� ��������
	{
		table[ind] = el;
		return;
	}
	countCollision++;
	TableElement* curr = table[ind];
	while (curr->next != 0)	// ����� ���� ����� ������
		curr = curr->next;
	curr->next = el;
}

void HashTable::randForm(int n)
{
	string f, s, t, a, p;
	for (int i = 0; i < n; i++)
	{
		f = fNames[rand() % fNames.size()];
		s = sNames[rand() % sNames.size()];
		t = tNames[rand() % tNames.size()];
		p = "";
		for (int i = 0; i < 10; i++)
			p += (char)(rand() % 10 + (int)'0');
		a = adresses[rand() % adresses.size()];
		Person p(f, s, t, p, a);
		add(p);
	}
	cout << "�������� ������������\n";
}

void HashTable::print()
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] != 0)	// ���� �� ������ ������
		{
			cout << "������ �" << (i + 1)<<endl;
			TableElement* p = table[i];
			while (p != 0)	// ���� �� ����� - ������� ���� ������
			{
				cout << "\t - " << p->p << endl;
				p = p->next;
			}
			cout << endl;
		}
	}
}

void HashTable::clear()
{
	countCollision = 0;
	for (int i = 0; i < size; i++)
	{
		if (table[i] != 0)		// ���� �� ������ ������
		{
			TableElement* prev, * curr = table[i];
			while (curr != 0)
			{
				prev = curr;
				curr = curr->next; // ���� ������
				delete prev;	// ������� ����������
			}
		}
		table[i] = 0;
	}
}

void HashTable::findByKey(string key)
{
	Person p("", "", "", key, "");
	int ind = getHastCode(p.getHashCode());
	if (table[ind] == 0)
	{
		cout << "��� �������� � ����� ������\n";
		return;
	}
	TableElement* curr = table[ind];
	while(curr != 0)
	{
		if (curr->p.getPassport() == key)
		{
			cout << "�������: " << curr->p << endl;
			return;
		}
		curr = curr->next;
	}
	cout << "��� �������� � ����� ������\n";
}
