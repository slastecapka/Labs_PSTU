#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class Book
{
private:
	int id;
	string name;
	string author;
	int year;
	string house;
	bool isDelete;

public:
	Book() { id = year = 0; name = author = house = ""; isDelete = false; }
	Book(int id, string n, string a, int y, string h, bool del) { this->id = id; name = n; author = a; year = y; house = h; isDelete = del; }
	Book(const Book& b) { id = b.id; name = b.name; author = b.author; year = b.year; house = b.house; isDelete = b.isDelete; }
	~Book() {}

	int getId() { return id; }
	string getName() { return name; }
	void setName(string n) { name = n; }
	string getAuthor() { return author; }
	void setAuthor(string a) { author = a; }
	int getYear() { return year; }
	void setYear(int y) { year = y; }
	string getHouse() { return house; }
	void setHouse(string h) { house = h; }
	bool getIsDelete() { return isDelete; }
	void setIsDelete(bool del) { isDelete = del; }

	Book& operator= (const Book& b);
	// стандартные потоки
	friend istream& operator>> (istream& in, Book& b);
	friend ostream& operator<< (ostream& out, const Book& b);
	// файловые потоки
	friend fstream& operator>> (fstream& fin, Book& b);
	friend fstream& operator<< (fstream& fout, const Book& b);
};
