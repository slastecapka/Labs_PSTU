#include <iostream>
#include "CppStream.h"
using namespace std;

string writePath()
{
	string s;
	cout << "Path to file? "; cin >> s;
	return s;
}

int main()
{
	CppStream stream;
	setlocale(LC_ALL, "rus");
	int x;
	do
	{
		try
		{
			cout << "\n1. ������������ ���� � �������\n2. ��������� ����\n3.������� �� ����� �������� �� k1 �� k2\n";
			cout << "4. ��� ������ � �������� ��������� ��������� �� 1:30\n5. �������� K ��������� � ������\n6.�������� �����\n7.�����\n";
			cout << "->";
			cin >> x;
			switch (x)
			{
			case 1:
				stream.writeTimes(writePath());
				break;
			case 2:
				stream.readTimes(writePath());
				break;
			case 3:
				stream.removeTimes(writePath());
				break;
			case 4: 
				stream.updateTimes(writePath());
				break;
			case 5: 
				stream.appendTimes(writePath());
				break;
			case 6:
				system("cls");
				break;
			case 7:
				return 0;
			}
		}
		catch (exception ex)
		{
			cout << ex.what() << endl;
			stream.closeStreams();
		}
	} while (true);
}