#pragma once

#include <vector>
#include "Book.h"

class Vector
{
private:
	vector<Book> vec;
	int lastInsertId = 1; // ��� ��������������� ���������� ��������������
	 
	vector<Book>::iterator lastDelete = vec.end();	// ��� ������ ���������� ��������

	fstream stream;	// �������� �����

	bool deleteByIsDelete(); // ��� �������� �������� � ��������
public:
	Vector();
	~Vector();

	void show();				// ��������
	void add(int pos=0);		// ����������
	void deleteById(int id);	// �������� �� ��������������
	void deleteByPos(int pos);	// �������� �� ������
	void updateByPos(int pos);	// ��������� �� ������
	void cancelLastDelete();	// ������ ���������� ��������

	int len();					// ���������� �������� ��� �������

	void open(string path);		// ��������
	void save(string path);		// ����������
	void close();				// �������� �������

	void findByAuthor(string a);			// ����� �� �������
	void findByYearPeriod(int y1, int y2);	// ����� �� ������� �������
};
