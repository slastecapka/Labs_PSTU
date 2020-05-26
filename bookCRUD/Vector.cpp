#include "Vector.h"

Vector::Vector()
{ 

}

Vector::~Vector()
{
	vec.clear();
}

int Vector::len() 
{
	int count = 0;
	for (auto it = vec.begin(); it != vec.end(); it++)
		if (it->getIsDelete() == false)	 // ��� �������
			count++;
	return count;
}

void Vector::show()
{
	if (len() == 0)
		cout << "������\n";
	int i = 1;
	for (auto it = vec.begin(); it != vec.end(); it++, i++)
		if (it->getIsDelete() == false)	// ��� �������
			cout << "�����: " << i << endl << (*it) << endl;
}

void Vector::add(int pos)
{
	if (pos != 0)
		pos--;
	if (pos < 0 || pos>vec.size())
		throw exception("������. �������� �����");
	Book book(this->lastInsertId++, "", "", 0, "", false);
	cin >> book;
	if (pos == 0 || vec.size() == 0)	// � �����
		vec.insert(vec.end(), book);
	else
		vec.insert(vec.begin() + pos, book); // �� ������
	lastDelete = vec.end();
	cout << "�������� ����������\n";
}

void Vector::deleteById(int id)
{
	for(auto it = vec.begin(); it != vec.end(); it++)
		if ((*it).getId() == id && it->getIsDelete() == false)
		{
			lastDelete = it;
			it->setIsDelete(true);
			cout << "�������� ��������\n";
			return;
		}
	throw exception("��� ����� � �������� ���������������");
}

void Vector::deleteByPos(int pos)
{
	if (pos < 1 || pos > vec.size())
		throw exception("������. �������� �������");
	auto it = vec.begin() + pos - 1;
	lastDelete = it;
	it->setIsDelete(true);
	cout << "�������� ��������\n";
}

void Vector::updateByPos(int pos)
{
	if (pos < 1 || pos > vec.size())
		throw exception("������. �������� �������");
	auto it = vec.begin() + pos - 1;
	cout << (*it) << endl;
	cin >> (*it);
}

void Vector::cancelLastDelete()
{
	if (lastDelete == vec.end())
		throw exception("������. ������ �� ���������");
	lastDelete->setIsDelete(false);		// ������� �������
	lastDelete = vec.end();				// ������ � �����
	cout << "�������� ������ ��������\n";
}

bool Vector::deleteByIsDelete()
{
	int count = 0;
	for (auto it = vec.begin(); it != vec.end(); it++)
		if ((*it).getIsDelete() == true)	// ������� ���������� �������
			count++;
	return count > vec.size() / 2;	// ���� ������ ��������
}

void Vector::open(string path)
{
	stream.open(path.c_str(), ios::in | ios::binary);
	if (!stream.is_open())
		throw exception("������. �� ������� ������� ����");
	if (vec.size() != 0)
		vec.clear();
	stream >> lastInsertId;
	Book b;
	do
	{
		stream >> b;		// ������ �� ��������
		if (stream.eof())
			break;
		vec.push_back(b);
	} while (true);
	cout << "�������� ��������\n";
}

void Vector::save(string path)
{
	stream.open(path.c_str(), ios::out | ios::trunc | ios::binary);
	if(!stream.is_open())
		throw exception("������. �� ������� ������� ����");
	stream << lastInsertId << endl;
	if (deleteByIsDelete() == true)
	{
		for (auto it = vec.begin(); it != vec.end(); it++)
			if (it->getIsDelete() == false)
				stream << (*it) << endl;	// ���������� �� ��������
	}
	else
		for (auto it = vec.begin(); it != vec.end(); it++)
			stream << (*it) << endl;
	cout << "�������� ����������\n";
}

void Vector::close()
{
	if (stream.is_open())
		stream.close();
}

void Vector::findByAuthor(string a)
{
	for (auto it = vec.begin(); it != vec.end(); it++)
		if (it->getAuthor() == a)
			cout << (*it) << endl;
}

void Vector::findByYearPeriod(int y1, int y2)
{
	if (y2 < y1)
		throw exception("������. �������� ���� ������ ���������");
	for (auto it = vec.begin(); it != vec.end(); it++)
		if (it->getYear() >= y1 && it->getYear() <= y2)
			cout << (*it) << endl;

}