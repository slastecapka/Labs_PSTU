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
	void readTimes(string path);		// чтение файла
	void writeTimes(string path);		// запись в файл
	int findTime(string path, Time& t);	// поиск в файле
	void removeTimes(string path);		// удаление от k1 до k2
	void updateTimes(string path);		// добавление 1:30
	void appendTimes(string path);		// добавление в начало
	void closeStreams();				// закрытие потоков
};