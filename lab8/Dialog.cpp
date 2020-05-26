#include "Dialog.h"

Dialog::Dialog():Vector()
{
	EndState = 0;
}

Dialog::~Dialog()
{

}

void Dialog::GetEvent(TEvent& event)
{
	string s, param, OpInt = "+-?/qamc"; // строка с символами операций
	char code;
	cout << '>'; cin >> s; code = s[0];
	if (OpInt.find(code) >= 0)	// является ли символ кодом операции
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case '?': event.command = cmShow; break;
		case '/': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break;
		case 'c': event.command = cmClear; break;
		}
		if (s.length() > 1)	// выделяем параметры команды, если они есть
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());	// преобразуем параметр в число
			event.a = A;	// записываем в сообщение
		}
	}
	else
		event.what = evNothing;	// пустое событие
}


int Dialog::Execute()
{
	TEvent event;
	do
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			size = event.a;
			beg = new Object * [size];
			curr = 0;
			ClearEvent(event);
			break;
		case cmAdd:
			add();
			ClearEvent(event);
			break;
		case cmDel:
			del();
			ClearEvent(event);
			break;
		case cmShow:
			show();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		case cmClear:
			system("cls");
			ClearEvent(event);
			break;
		default:
			Vector::HandleEvent(event);
		}
	}
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}

int Dialog::Valid()
{
	if (EndState == 0)
		return 0;
	else
		return 1;
}

void Dialog::EndExec()
{
	EndState = 1;
}
