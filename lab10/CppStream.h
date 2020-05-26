#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include "Time.h"
using namespace std;

class CppStream
{
private:
	ofstream out;
	ifstream in;

public:
	void readTimes(string path);		// ������ �����
	void writeTimes(string path);		// ������ � ����
	int findTime(string path, Time& t);	// ����� � �����
	void removeTimes(string path);		// �������� �� k1 �� k2
	void updateTimes(string path);		// ���������� 1:30
	void appendTimes(string path);		// ���������� � ������
	void closeStreams();				// �������� �������
};