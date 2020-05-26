#include <iostream>
#include <ctime>
#include "HashTable.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand((unsigned)time(0));
	int x,n;
	string param;
	HashTable table(100);
	do
	{
		try
		{
			cout << "\n1. ������������ ��������\n2. ����� �� ������ ��������\n3. �����\n4. ���������� ��������\n5. ��������\n6. �����\n>";
			cin >> x;
			switch (x)
			{
			case 1:
				cout << "����������? "; cin >> n;
				table.clear();
				table.randForm(n);
				break;
			case 2:
				cout << "����� ���������: "; cin >> param;
				table.findByKey(param);
				break;
			case 3:
				table.print();
				break;
			case 4:
				cout << "���������� = " << table.getCountCollision() << endl;
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
}