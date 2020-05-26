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
			cout << "\n1. ������� �� �����\n2. �������� � �����\n3. �������� �� ������\n4.������� �� ��������������\n5.������� �� ������\n";
			cout << "6. �������� �� ������\n7. �������� ��������� ��������\n8. ��������� ���������\n9. ��������� ������\n";
			cout << "10.����� �� ������\n11. ����� �� ������� ���������\n12. �������� �����\n13.�����\n>";
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
				cout << "�����? "; cin >> pos;
				vec.add(pos);
				break;
			case 4: 
				cout << "�������������? "; cin >> id;
				vec.deleteById(id);
				break;
			case 5: 
				cout << "�����? "; cin >> pos;
				vec.deleteByPos(pos);
				break;
			case 6: 
				cout << "�����? "; cin >> pos;
				vec.updateByPos(pos);
				break;;
			case 7: 
				vec.cancelLastDelete();
				break;
			case 8: 
				cout << "����? "; cin >> path;
				vec.save(path);
				break;
			case 9: 
				cout << "����? "; cin >> path;
				vec.open(path);
				break;
			case 10:
				cout << "�����? "; cin >> param;
				vec.findByAuthor(param);
				break;
			case 11: 
				cout << "������ ���� ����� ������? "; cin >> param1 >> param2;
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