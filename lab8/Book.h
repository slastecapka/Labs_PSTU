#pragma once

#include "Print.h"
#include "Vector.h"

class Book : public Print
{
private:
	int count;
	string publicHouse;

public:
	Book(void) :Print() { count = 0; publicHouse = "NoHouse"; }
	Book(string n, string a, int c, string h) :Print(n, a) { count = c; publicHouse = h; }
	Book(const Book& b) { name = b.name; author = b.author; count = b.count; publicHouse = b.publicHouse; }
	~Book(void) { }

	Book& operator= (const Book& b);

	void show();
	void input();
};
