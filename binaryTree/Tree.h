#pragma once

#include <iostream>
using namespace std;

struct Point		// узел в дереве
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

class Tree	// дерево
{
private:
	Point *root;	// корень

	// РЕКУРСИВНЫЕ ФУНКЦИИ
	Point* makePoint(Point* p, int n);		// формирование
	void printPoint(Point* p, int l);		// печать - проход слева направо
	void clearPoint(Point* p);				// очищение
	void findMinPoint(Point* p, double& min); // поиск минимального
	// ДЕРЕВО ПОИСКА
	Point* addFindPoint(Point* p, double d);   // добавление узла
	void makeFindPoint(Point* p, Point* newRoot);   // проход по сбалансированному дереву

public:
	Tree();
	~Tree();

	void makeTree(int n);
	void print();
	double findMin();
	void makeFindTree();
};
