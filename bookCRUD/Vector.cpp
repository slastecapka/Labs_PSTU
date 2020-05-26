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
		if (it->getIsDelete() == false)	 // без пометки
			count++;
	return count;
}

void Vector::show()
{
	if (len() == 0)
		cout << "Пустой\n";
	int i = 1;
	for (auto it = vec.begin(); it != vec.end(); it++, i++)
		if (it->getIsDelete() == false)	// без пометки
			cout << "Номер: " << i << endl << (*it) << endl;
}

void Vector::add(int pos)
{
	if (pos != 0)
		pos--;
	if (pos < 0 || pos>vec.size())
		throw exception("Ошибка. Неверный номер");
	Book book(this->lastInsertId++, "", "", 0, "", false);
	cin >> book;
	if (pos == 0 || vec.size() == 0)	// в конец
		vec.insert(vec.end(), book);
	else
		vec.insert(vec.begin() + pos, book); // по номеру
	lastDelete = vec.end();
	cout << "Успешное добавление\n";
}

void Vector::deleteById(int id)
{
	for(auto it = vec.begin(); it != vec.end(); it++)
		if ((*it).getId() == id && it->getIsDelete() == false)
		{
			lastDelete = it;
			it->setIsDelete(true);
			cout << "Успешное удаление\n";
			return;
		}
	throw exception("Нет книги с заданным идентификатором");
}

void Vector::deleteByPos(int pos)
{
	if (pos < 1 || pos > vec.size())
		throw exception("Ошибка. Неверная позиция");
	auto it = vec.begin() + pos - 1;
	lastDelete = it;
	it->setIsDelete(true);
	cout << "Успешное удаление\n";
}

void Vector::updateByPos(int pos)
{
	if (pos < 1 || pos > vec.size())
		throw exception("Ошибка. Неверная позиция");
	auto it = vec.begin() + pos - 1;
	cout << (*it) << endl;
	cin >> (*it);
}

void Vector::cancelLastDelete()
{
	if (lastDelete == vec.end())
		throw exception("Ошибка. Ничего не удалялось");
	lastDelete->setIsDelete(false);		// убираем пометку
	lastDelete = vec.end();				// ставим в конец
	cout << "Успешная отмена удаления\n";
}

bool Vector::deleteByIsDelete()
{
	int count = 0;
	for (auto it = vec.begin(); it != vec.end(); it++)
		if ((*it).getIsDelete() == true)	// считаем количество пометок
			count++;
	return count > vec.size() / 2;	// если больше половины
}

void Vector::open(string path)
{
	stream.open(path.c_str(), ios::in | ios::binary);
	if (!stream.is_open())
		throw exception("Ошибка. Не удалось открыть файл");
	if (vec.size() != 0)
		vec.clear();
	stream >> lastInsertId;
	Book b;
	do
	{
		stream >> b;		// читаем по объектно
		if (stream.eof())
			break;
		vec.push_back(b);
	} while (true);
	cout << "Успешное открытие\n";
}

void Vector::save(string path)
{
	stream.open(path.c_str(), ios::out | ios::trunc | ios::binary);
	if(!stream.is_open())
		throw exception("Ошибка. Не удалось открыть файл");
	stream << lastInsertId << endl;
	if (deleteByIsDelete() == true)
	{
		for (auto it = vec.begin(); it != vec.end(); it++)
			if (it->getIsDelete() == false)
				stream << (*it) << endl;	// записываем по объектно
	}
	else
		for (auto it = vec.begin(); it != vec.end(); it++)
			stream << (*it) << endl;
	cout << "Успешное сохранение\n";
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
		throw exception("Ошибка. Конечная дата меньше начальной");
	for (auto it = vec.begin(); it != vec.end(); it++)
		if (it->getYear() >= y1 && it->getYear() <= y2)
			cout << (*it) << endl;

}