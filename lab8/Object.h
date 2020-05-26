#pragma once

#include<iostream>
#include "Event.h"
using namespace std;

class Object
{
public:
	Object(void) { }
	virtual void show() = 0;
	virtual void input() = 0;

	virtual void HandleEvent(const TEvent& e) = 0;
};
