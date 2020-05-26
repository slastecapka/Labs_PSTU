#include "CppStream.h"

void CppStream::writeTimes(string path)
{
	out.open(path);
	if (!out.is_open())
		throw exception("���� �� ��������");
	int n;
	cout << "N? "; cin >> n;
	if (n < 1)
		throw exception("������� �������� ����� 0");
	for (int i = 0; i < n; i++)
	{
		Time t;
		cin >> t;		// ������ ������
		out << i << " " << t << endl; // ���������� � ����
	}
	out.close();
}

void CppStream::readTimes(string path)
{
	in.open(path);
	if (!in.is_open())
		throw exception("���� �� ��������");
	int i, m, s;
	char c;
	do
	{
		in >> i >> m >> c >> s;	// ������ ������
		if (in.eof())
			break;
		cout << m << c << s << endl;	// ������� �� �����
	} while (true);
	in.close();
}

int CppStream::findTime(string path, Time& t)
{
	in.open(path);
	if (!in.is_open())
		throw exception("���� �� ��������");
	int i, m, s;
	char c;
	do
	{
		in >> i >> m >> c >> s;		// ������ ������
		if (in.eof())
			throw exception("��� ������ ���������");
		Time obj(m, s);
		if (obj == t)	// ���������
			break;
	} while (true);
	in.close();
	return i;
}

void CppStream::removeTimes(string path)
{
	in.open(path);
	if (!in.is_open())
		throw exception("�� ������ path");
	in.close();
	out.open("temp.txt");
	if (!out.is_open())
		throw exception("�� ���� ������� ��� ������");
	Time k1, k2;
	cout << "k1?\n";
	cin >> k1;
	cout << "k2?\n";
	cin >> k2;
	int ind1 = findTime(path, k1); // ������� ������� ����� � �����
	int ind2 = findTime(path, k2);
	if (ind1 > ind2)
		throw exception("k2 ��������� �� k1");
	in.open(path);
	int i, m, s;
	char c;
	do
	{
		in >> i >> m >> c >> s;
		if (in.eof())
			break;
		if (i >= ind1 && i <= ind2)		// ���������� ����� ����� ���������
			continue;
		out << i << " " << m << c << s << endl;
	} while (true);
	in.close();
	out.close();
	if (remove(path.c_str()) != 0)		// ������� ������
		throw exception("���� �� ������");
	if (rename("temp.txt", path.c_str()) != 0)	// ��������������� �����
		throw exception("���� �� ������������");
}

void CppStream::updateTimes(string path)
{
	in.open(path);
	if (!in.is_open())
		throw exception("�� ������ path");
	out.open("temp.txt");
	if (!out.is_open())
		throw exception("�� ���� ������� ��� ������");
	Time t;
	cout << "Time? ";
	cin >> t;
	int i, m, s;
	char c;
	do
	{
		in >> i >> m >> c >> s;
		if (in.eof())
			break;
		Time temp(m, s);
		if (t == temp)		// ���� ����� ������ ����������
			temp = temp + 90;
		out << i << " " << temp << endl;
	} while (true);
	in.close();
	out.close();
	if (remove(path.c_str()) != 0)
		throw exception("���� �� ������");
	if (rename("temp.txt", path.c_str()) != 0)
		throw exception("���� �� ������������");
}

void CppStream::appendTimes(string path)
{
	in.open(path);
	if (!in.is_open())
		throw exception("�� ������ path");
	out.open("temp.txt");
	if (!out.is_open())
		throw exception("�� ���� ������� ��� ������");
	int K;
	cout << "K? "; cin >> K;
	if (K < 0)
		throw exception("���������� ������ ���� �� ����� 0");
	int i, m, s, k;
	char c;
	for (k = 0; k < K; k++)		// ��������� � ������
	{
		Time t;
		cin >> t;
		out << k << " " << t << endl;
	}
	do			// ������������ ����������
	{
		in >> i >> m >> c >> s;
		if (in.eof())
			break;
		out << i + k << " " << m << c << s << endl;
	} while (true);
	in.close();
	out.close();
	if (remove(path.c_str()) != 0)
		throw exception("���� �� ������");
	if (rename("temp.txt", path.c_str()) != 0)
		throw exception("���� �� ������������");
}

void CppStream::closeStreams()
{
	in.close();
	out.close();
}