#pragma once

#include "Object.h"

class Print : public Object
{
protected:
	string name;
	string author;

public:
	Print(void) { name = "NoName"; author = "NoAuthor"; }
	Print(string n, string a) { name = n; author = a; }
	Print(const Print& p) { name = p.name; author = p.author; }
	~Print() { }
	string getName() { return name; }
	string getAuthor() { return author; }
	void setName(string n) { name = n; }
	void setAuthor(string a) { author = a; }

	Print& operator= (const Print& p);
	
	void show();
	void input();

	void HandleEvent(const TEvent& e);
};
