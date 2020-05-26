#pragma once

#include <iostream>
using namespace std;

struct Point		// ���� � ������
{
	double data;
	Point* left;
	Point* right;

	Point(double d)
	{
		data = d;
		left = 0;
		right = 0;
	}
};

class Tree	// ������
{
private:
	Point *root;	// ������

	// ����������� �������
	Point* makePoint(Point* p, int n);		// ������������
	void printPoint(Point* p, int l);		// ������ - ������ ����� �������
	void clearPoint(Point* p);				// ��������
	void findMinPoint(Point* p, double& min); // ����� ������������
	// ������ ������
	Point* addFindPoint(Point* p, double d);   // ���������� ����
	void makeFindPoint(Point* p, Point* newRoot);   // ������ �� ����������������� ������

public:
	Tree();
	~Tree();

	void makeTree(int n);
	void print();
	double findMin();
	void makeFindTree();
};
