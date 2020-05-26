#pragma once

#include <iostream>
#include <deque>
#include "Time.h"
using namespace std;

// ����� 
void print(deque<Time>& deq);

// ����� ������������� � ���������� � �����
void addMax(deque<Time>& deq);

// �������� � ������������ ���������
void deleteWithKey(deque<Time>& deq);

// ����� �������� ����� ���� ��������
Time findAvg(deque<Time>& deq);

// ���������� �������� ���� ���������
void updateWithAvg(deque<Time>& deq);
