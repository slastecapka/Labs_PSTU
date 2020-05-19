#pragma once

#include<iostream>
using namespace std;

class Object
{
public:
	Object(void) { }
	virtual void show() = 0;
};
