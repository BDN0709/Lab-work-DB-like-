#pragma once
#include "Structs.h" // ��������� ���������� .h-����� � ������ ��������

void Menu(Avia*, const int&, int&);  // �������� ������� ��������� �������
void AddFlight(Avia*, const int&, int&);  // �������� ������� ��� ��������� �������� � �������
void PrintList(Avia*, const int);  // �������� ������� ��� ������ ������ ������ ��������
void PrintType(Avia*, const int); // �������� ������� ��� ������ �������� �� ����� �����
void PrintTheFastest(Avia*, const int); // �������� ������� ��� ������ ������ � ��������� ����� �������

#include "RFunc.h" // ��������� ���������� .h-����� � ��������� ������� ��� �������� ������ ����