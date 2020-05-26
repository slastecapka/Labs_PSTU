#pragma once

#include <iostream>
#include <queue>
#include <list>
#include "Time.h"
using namespace std;

// из очереди в список
list<Time> queueToList(queue<Time> que);

// из списка в очередь
queue<Time> listToQueue(list<Time> l);

void print(queue<Time>& que);

void addMax(queue<Time>& que);

void deleteWithKey(queue<Time>& que);

Time findAvg(queue<Time> que);

void updateWithAvg(queue<Time>& que);
