#include "Print.h"

Print& Print::operator= (const Print& p)
{
	if (this == &p)
		return *this;
	name = p.name;
	author = p.author;
	return *this;
}

void Print::show()
{
	cout << "NAME: " << name << endl;
	cout << "AUTHOR: " << author << endl;
}

void Print::input()
{
	cout << "NAME? "; cin >> name;
	cout << "AUTHOR? "; cin >> author;
}

void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "NAME: " << name << endl;
			break;
		}
	}
}