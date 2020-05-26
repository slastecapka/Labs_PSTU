#include <iostream>
#include <ctime>
#include "Tree.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(0));
	int x, param;
	Tree tr;
	do
	{
		try
		{
			cout << "\n1. ������������ ��������-���������������� ������\n2. ������� ������\n3. ����� �����������\n4. ���������� � ������ ������\n5. �������� �����\n6. �����\n>";
			cin >> x;
			switch (x)
			{
			case 1:
				cout << "����������? "; cin >> param;
				tr.makeTree(param);
				break;
			case 2:
				tr.print();
				break;
			case 3:
				cout << "����������� = " << tr.findMin() << endl;
				break;
			case 4:
				tr.makeFindTree();
				break;
			case 5:
				system("cls");
				break;
			case 6:
				return 0;
			}
		}
		catch (exception & ex)
		{
			cout << ex.what() << endl;
		}
	} while (true);
	return 0;
}