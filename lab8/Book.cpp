#include "Book.h"

Book& Book::operator= (const Book& b)
{
	if (this == &b)
		return *this;
	name = b.name;
	author = b.author;
	count = b.count;
	publicHouse = b.publicHouse;
	return *this;
}

void Book::show()
{
	cout << "NAME: " << name << endl;
	cout << "AUTHOR: " << author << endl;
	cout << "COUNT: " << count << endl;
	cout << "HOUSE: " << publicHouse << endl;
}

void Book::input()
{
	cout << "NAME? "; cin >> name;
	cout << "AUTHOR? "; cin >> author;
	cout << "COUNT? "; cin >> count;
	cout << "HOUSE? "; cin >> publicHouse;
}