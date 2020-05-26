#pragma once

#include "Vector.h"
#include "Event.h"

class Dialog:public Vector
{
protected:
	int EndState;

public:
	Dialog(void);
	~Dialog(void);
	virtual void GetEvent(TEvent& event);		// получить событие
	virtual int Execute();						// бесконечное выполнение
	virtual void HandleEvent(TEvent& event);	// обработка события
	virtual void ClearEvent(TEvent& event);		// очистка события после обработки
	int Valid();								// проверка EndState
	void EndExec();								// обарботка события "конец работы"
};

