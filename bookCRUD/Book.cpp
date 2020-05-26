#include "Book.h"

Book& Book::operator= (const Book& b)
{
	if (this == &b)
		return *this;
	id = b.id;
	name = b.name;
	author = b.author;
	year = b.year;
	house = b.house;
	isDelete = b.isDelete;
	return *this;
}

istream& operator>> (istream& in, Book& b)
{
	cout << "NAME? "; in>> b.name;
	cout << "AUTHOR? "; in >> b.author;
	cout << "YEAR? "; in >> b.year;
	cout << "HOUSE? "; in >> b.house;
	return in;
}

ostream& operator<< (ostream& out, const Book& b)
{
	out << "NAME: " << b.name<<endl;
	out << "AUTHOR: " << b.author<<endl;
	out << "YEAR: " << b.year<<endl;
	out << "HOUSE: " << b.house<<endl;
	return out;
}

fstream& operator>> (fstream& fin, Book& b)
{
	fin >> b.id >> b.name >> b.author >> b.year >> b.house >> b.isDelete;
	return fin;
}

fstream& operator<< (fstream& fout, const Book& b)
{
	fout << b.id << " " << b.name << " " << b.author << " " << b.year << " " << b.house << " " << b.isDelete;
	return fout;
}
