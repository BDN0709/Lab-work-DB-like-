#pragma once
#include <string>  // ��������� ������������ ��� ������ ������ � ��������

using namespace std;  // ������������ ���� std

struct Flight
{  // ��������� ��� ��������� ���� �������
	double Hours;
	double Minutes;
};

struct Avia
{  // c�������� ��������
	double Number;
	string Type;
	Flight Time;
};