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
			cout << "\n1. Сформировать случайно\n2. Поиск по номеру паспорта\n3. Вывод\n4. Количество коллизий\n5. Очистить\n6. Выход\n>";
			cin >> x;
			switch (x)
			{
			case 1:
				cout << "Количество? "; cin >> n;
				table.clear();
				table.randForm(n);
				break;
			case 2:
				cout << "Номер пасспорта: "; cin >> param;
				table.findByKey(param);
				break;
			case 3:
				table.print();
				break;
			case 4:
				cout << "Количество = " << table.getCountCollision() << endl;
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