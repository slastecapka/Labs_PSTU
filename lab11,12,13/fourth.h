#pragma once

#include <iostream>
#include <queue>
#include <list>
#include "Time.h"
using namespace std;

// �� ������� � ������
list<Time> queueToList(queue<Time> que);

// �� ������ � �������
queue<Time> listToQueue(list<Time> l);

void print(queue<Time>& que);

void addMax(queue<Time>& que);

void deleteWithKey(queue<Time>& que);

Time findAvg(queue<Time> que);

void updateWithAvg(queue<Time>& que);
