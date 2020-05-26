#pragma once

#include <vector>
#include "Book.h"

class Vector
{
private:
	vector<Book> vec;
	int lastInsertId = 1; // для автоматического присвоения идентификатора
	 
	vector<Book>::iterator lastDelete = vec.end();	// для отмены последнего удаления

	fstream stream;	// файловый поток

	bool deleteByIsDelete(); // для удаления объектов с пометкой
public:
	Vector();
	~Vector();

	void show();				// просмотр
	void add(int pos=0);		// добавление
	void deleteById(int id);	// удаление по идентификатору
	void deleteByPos(int pos);	// удаление по номеру
	void updateByPos(int pos);	// изменение по номеру
	void cancelLastDelete();	// отмена последнего удаления

	int len();					// количество объектов без пометки

	void open(string path);		// открытие
	void save(string path);		// сохранение
	void close();				// закрытие потоков

	void findByAuthor(string a);			// поиск по авторму
	void findByYearPeriod(int y1, int y2);	// поиск по периоду выпуска
};
