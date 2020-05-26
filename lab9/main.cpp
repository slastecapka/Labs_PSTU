#include <iostream>
#include "Vector.h"
using namespace std;

int main()
{
	try 
	{
		// ошибка с помощью пользовательского типа
		Vector v1(0);
		cin >> v1;	// ошибка в >> (нельзя ввести пустой)
		cout << v1 << endl;
	}
	catch (int)
	{
		cout << "int ERROR" << endl;
	}

	try
	{
		Vector v2(5, 3);
		cout << v2 << endl;
		cout << v2[-3] << endl;  // ошибка в [] (отрицательный индекс)
	}
	catch (error & e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Vector v3(5, 3);
		cin >> v3;
		cout << v3 << endl;
		cout << "After v3--: " << (v3--) << endl; // удаляется после вывода
		cout << "After --v3: " << (--v3) << endl; // удаляется до вывода
		v3--; v3--; v3--; 
		v3--;	// ошибка в --(int) (пустой)
	}
	catch (error & e)
	{
		cout << e.what() << endl;
	}
}