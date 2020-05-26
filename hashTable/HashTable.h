#pragma once

#include "Person.h"
#include <vector>

struct TableElement			// структура элемент однонаправленного списка
{
	Person p;				// информационное поле
	TableElement* next;		// указатель на следующий элемент

	TableElement(Person& p)	// конструктор
	{
		this->p = p;
		this->next = 0;
	}
};

class HashTable
{
private:
	int size;
	TableElement** table;	// таблица указателей

	int countCollision = 0;	// количество коллизий
	float A = 0.37651;		// коэффициент для хэш-кода
public:
	HashTable(int n);
	~HashTable();

	int getHastCode(int k);	// получение хэш-кода

	void add(Person& p);	// добавление объекта
	void randForm(int n);	// случайное формирование
	void print();			// вывод
	void clear();			// очищение
	int getCountCollision() { return countCollision; }
	void findByKey(string p);

private:
	vector<string> fNames = { "Иванов","Петров","Сидоров","Тесла","Маск","Эйнштейн","Ньютон","Гук","Кюри","Сталин","Ленин","Маркс" };
	vector<string> sNames = { "Иван","Петр","Сидор","Никола","Илон","Альберт","Исаак","Роберт","Мария","Иосиф","Владимир","Карл","Алексей","Михаил","Дмитрий" };
	vector<string> tNames = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович", "Владимирович","Карлович","Алексеевич","Михаилович","Дмитриевич" };
	vector<string> adresses = { "Москва", "Пермь","Екатеринбург","Саратов","Санкт-Петербург","Кубань","Севастополь","Воронеж","Казань","Уфа" };
};
