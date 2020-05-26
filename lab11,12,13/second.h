#pragma once

#include <iostream>
#include <deque>
#include "Time.h"
using namespace std;

// вывод 
void print(deque<Time>& deq);

// поиск максимального и добавление в конец
void addMax(deque<Time>& deq);

// удаление с определенным значением
void deleteWithKey(deque<Time>& deq);

// поиск среднего среди всех значений
Time findAvg(deque<Time>& deq);

// добавление среднего всем значениям
void updateWithAvg(deque<Time>& deq);
