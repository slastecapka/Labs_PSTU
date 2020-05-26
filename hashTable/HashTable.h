#pragma once

#include "Person.h"
#include <vector>

struct TableElement			// ��������� ������� ����������������� ������
{
	Person p;				// �������������� ����
	TableElement* next;		// ��������� �� ��������� �������

	TableElement(Person& p)	// �����������
	{
		this->p = p;
		this->next = 0;
	}
};

class HashTable
{
private:
	int size;
	TableElement** table;	// ������� ����������

	int countCollision = 0;	// ���������� ��������
	float A = 0.37651;		// ����������� ��� ���-����
public:
	HashTable(int n);
	~HashTable();

	int getHastCode(int k);	// ��������� ���-����

	void add(Person& p);	// ���������� �������
	void randForm(int n);	// ��������� ������������
	void print();			// �����
	void clear();			// ��������
	int getCountCollision() { return countCollision; }
	void findByKey(string p);

private:
	vector<string> fNames = { "������","������","�������","�����","����","��������","������","���","����","������","�����","�����" };
	vector<string> sNames = { "����","����","�����","������","����","�������","�����","������","�����","�����","��������","����","�������","������","�������" };
	vector<string> tNames = { "��������","��������","���������","����������","��������","�����������","���������","����������","��������","���������", "������������","��������","����������","����������","����������" };
	vector<string> adresses = { "������", "�����","������������","�������","�����-���������","������","�����������","�������","������","���" };
};
