#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int x, pos, id, param1, param2;
	string path, param;
	Vector vec;
	do
	{
		try
		{
			cout << "\n1. Вывести на экран\n2. Добавить в конец\n3. Добавить по номеру\n4.Удалить по идентификатору\n5.Удалить по номеру\n";
			cout << "6. Изменить по номеру\n7. Отменить последнее удаление\n8. Сохранить изменения\n9. Загрузить данные\n";
			cout << "10.Поиск по автору\n11. Поиск по периоду написания\n12. Очистить экран\n13.Выход\n>";
			cin >> x;
			switch (x)
			{
			case 1:
				vec.show();
				break;
			case 2: 
				vec.add();
				break;
			case 3: 
				cout << "Номер? "; cin >> pos;
				vec.add(pos);
				break;
			case 4: 
				cout << "Идентификатор? "; cin >> id;
				vec.deleteById(id);
				break;
			case 5: 
				cout << "Номер? "; cin >> pos;
				vec.deleteByPos(pos);
				break;
			case 6: 
				cout << "Номер? "; cin >> pos;
				vec.updateByPos(pos);
				break;;
			case 7: 
				vec.cancelLastDelete();
				break;
			case 8: 
				cout << "Путь? "; cin >> path;
				vec.save(path);
				break;
			case 9: 
				cout << "Путь? "; cin >> path;
				vec.open(path);
				break;
			case 10:
				cout << "Автор? "; cin >> param;
				vec.findByAuthor(param);
				break;
			case 11: 
				cout << "Период даты через пробел? "; cin >> param1 >> param2;
				vec.findByYearPeriod(param1, param2);
				break;
			case 12: 
				system("cls");
				break;
			case 13:
				return 0;
			}
		}
		catch (exception & ex) 
		{
			cout << ex.what() << endl;
		}
	} while (true);
}