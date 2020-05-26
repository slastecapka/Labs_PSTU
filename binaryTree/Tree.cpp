#include "Tree.h"

Tree::Tree()
{
	root = 0;
}

Tree::~Tree()
{
	clearPoint(root);
}

//ОЧИЩЕНИЕ
void Tree::clearPoint(Point* root)
{
	if (!root) 
		return;
	clearPoint(root->left);
	clearPoint(root->right);
	delete root;
	return;
}

// ФОРМИРОВАНИЕ
Point* Tree::makePoint(Point* root, int n)
{
	Point* p = root;
	int nl, nr;
	if (n == 0) {		// если закончили добавлять в поддеревьях
		p = 0;
		return p;
	}
	nl = n / 2;			// Кол-во узлов в левом 
	nr = n - nl - 1;	// и правом поддеревьях
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
	cout << "Успешное формирование\n";
}

// ПЕЧАТЬ
void Tree::printPoint(Point* root, int l)
{
	Point* p = root;
	if (p)
	{
		printPoint(p->right, l + 5);
		for (int i = 0; i < l; i++)	 // для приличного вида - отступы
			cout << " ";
		cout << p->data << endl;
		printPoint(p->left, l + 5);
	}
}

void Tree::print()
{
	printPoint(root, 0);
}


// ПОИСК МИНИМАЛЬНОГО
void Tree::findMinPoint(Point* root, double& min) // передача по ссылке - будет изменяться
{
	if (root)
	{
		findMinPoint(root->left, min);
		if (root->data < min)	// сравниваем
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



// ДЕРЕВО ПОИСКА
Point* Tree::addFindPoint(Point* root, double d)
{
	Point* p = root;
	Point* r = 0; 
	bool ok = false;  //флаг для проверки существования элемента d в дереве
	while (p && !ok)  // пока не конец и пока не нашли
	{
		r = p;
		if (p->data == d) 
			ok = true;         //элемент уже существует                          
		else
			if (d < p->data) 
				p = p->left;    //пойти в левое поддерево
			else 
				p = p->right;    //пойти в правое поддерево
	}
	if (ok)   //если нашли похожий, не добавляем
		return p;  
	Point* temp = new Point(d);     //выделили память
	if (d < r->data) 
		r->left = temp;   // если d < r->data, то добавляем его в левое поддерево
	else 
		r->right = temp;   // если d > r->data, то добавляем его в правое поддерево
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
	cout << "Успешное преобразование\n";
}
