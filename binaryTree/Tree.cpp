#include "Tree.h"

Tree::Tree()
{
	root = 0;
}

Tree::~Tree()
{
	clearPoint(root);
}

//��������
void Tree::clearPoint(Point* root)
{
	if (!root) 
		return;
	clearPoint(root->left);
	clearPoint(root->right);
	delete root;
	return;
}

// ������������
Point* Tree::makePoint(Point* root, int n)
{
	Point* p = root;
	int nl, nr;
	if (n == 0) {		// ���� ��������� ��������� � �����������
		p = 0;
		return p;
	}
	nl = n / 2;			// ���-�� ����� � ����� 
	nr = n - nl - 1;	// � ������ �����������
	double param;
	cout << "value? "; cin >> param;
	Point* r = new Point(param);
	r->left = makePoint(r->left, nl);
	r->right = makePoint(r->right, nr);
	return r;
}

void Tree::makeTree(int n)
{
	root = makePoint(root, n);
	cout << "�������� ������������\n";
}

// ������
void Tree::printPoint(Point* root, int l)
{
	Point* p = root;
	if (p)
	{
		printPoint(p->right, l + 5);
		for (int i = 0; i < l; i++)	 // ��� ���������� ���� - �������
			cout << " ";
		cout << p->data << endl;
		printPoint(p->left, l + 5);
	}
}

void Tree::print()
{
	printPoint(root, 0);
}


// ����� ������������
void Tree::findMinPoint(Point* root, double& min) // �������� �� ������ - ����� ����������
{
	if (root)
	{
		findMinPoint(root->left, min);
		if (root->data < min)	// ����������
			min = root->data;
		findMinPoint(root->right,min);
	}
}


double Tree::findMin()
{
	double min = root->data;
	findMinPoint(root, min);
	return min;
}



// ������ ������
Point* Tree::addFindPoint(Point* root, double d)
{
	Point* p = root;
	Point* r = 0; 
	bool ok = false;  //���� ��� �������� ������������� �������� d � ������
	while (p && !ok)  // ���� �� ����� � ���� �� �����
	{
		r = p;
		if (p->data == d) 
			ok = true;         //������� ��� ����������                          
		else
			if (d < p->data) 
				p = p->left;    //����� � ����� ���������
			else 
				p = p->right;    //����� � ������ ���������
	}
	if (ok)   //���� ����� �������, �� ���������
		return p;  
	Point* temp = new Point(d);     //�������� ������
	if (d < r->data) 
		r->left = temp;   // ���� d < r->data, �� ��������� ��� � ����� ���������
	else 
		r->right = temp;   // ���� d > r->data, �� ��������� ��� � ������ ���������
	return temp;
}

void Tree::makeFindPoint(Point* p, Point* NewRoot)
{
	if (p)
	{
		makeFindPoint(p->left, NewRoot);
		addFindPoint(NewRoot, p->data);
		makeFindPoint(p->right, NewRoot);
	}
}

void Tree::makeFindTree()
{
	Point* newRoot = new Point(root->data);
	makeFindPoint(root, newRoot);
	clearPoint(root);
	root = newRoot;
	cout << "�������� ��������������\n";
}
