#pragma once
#include <iostream>
using namespace std;

class error
{
private:
	string msg;

public:
	error(string s) { msg = s; }
	~error() { }
	string what() { return msg; }
};