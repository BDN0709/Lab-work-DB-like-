#pragma once
#include <iostream> // ��������� ���������� �����-������ �����
#include <cstdlib> // ��������� ���������� �������� ��� ������ ������ � ��������
#include <string>  // ��������� ������������ ��� ������ ������ � ��������
#include "Structs.h" // ��������� ���������� .h-����� � ������ ��������
#include "ProtFunc.h"  // ���������� .h-����� ��� ������� ����������� ����� �������� �������

using namespace std;  // ������������ �������� ���� std ��� �������� ������ ����

void Menu(Avia* List, const int& size, int& atList) // ������� ��������� �������
{
	while (true)
	{
		system("cls");  // �������� ������
		double answer;  // ����� "�������"
		cout << "0 - ������� �������� " << endl;
		cout << "1 - ������ ������� � ������� " << endl;
		cout << "2 - ������� ������ �������� " << endl;
		cout << "3 - ������� ������ �������� �� �������� ����� ����� " << endl;
		cout << "4 - ������ ������� � ��������� ����� ������� " << endl;
		cin >> answer;
		while (!cin || answer != int(answer) || answer < 0 || answer > 4)
		{                  // ���������� �������� �������� �����
			if (!cin)
			{
				cout << "Error: ����� ���� �� ���� ���� ������� �������! " << endl;
				cin.clear();  // �������� ������ �����
				cin.ignore(32767, '\n');  // �������� ������ �����
			}

			else if (answer != int(answer) || answer < 0 || answer > 4)
				cout << "Error: ������ ��������� ����� ����! " << endl;

			cout << "������� ����� ���� �� 0 �� 4: " << endl;
			cin >> answer;
		}
		switch ((int)answer)
		{
		case 0: return; break;
		case 1: AddFlight(List, size, atList); break;
		case 2: PrintList(List, atList); break;
		case 3: PrintType(List, atList); break;
		case 4: PrintTheFastest(List, atList); break;
		}
	}
	return;
}

void AddFlight(Avia* List, const int& size, int& atList)
{  // ������� ��������� �������� � �������
	system("cls");  // �������� ������

	if (atList == size)
	{
		cout << "��������� ���� ����������� ��������� ������� ����� � ������! " << endl;
		cout << "�� ����, ����� ������� �������� � ������ ���������. " << endl;
		system("pause");  // �������� ��������� ����� �� ������
		return;
	}

	cout << "������ ����� �����: ";
	cin >> List[atList].Number;

	while (!cin)
	{
		cout << "Error: ����� ����� �� ���� ���� ������� �������! " << endl;
		cin.clear();  // �������� ������ �����
		cin.ignore(32767, '\n');  // �������� ������ �����
		cout << "������ ����� �����: ";
		cin >> List[atList].Number;
	}

	cin.clear();  // �������� ������ �����
	cin.ignore(32767, '\n');  // �������� ������ �����

	cout << "������ ��� �����: ";
	getline(cin, List[atList].Type);  // �������, ��� ����� ���� �������� ������, � �� �� ����� ���������

	cout << "������ ��� ������� ����� #" << List[atList].Number << ": " << endl;

	cout << "������: ";
	cin >> List[atList].Time.Hours;

	while (!cin || List[atList].Time.Hours != int(List[atList].Time.Hours)
		|| List[atList].Time.Hours < 0 || List[atList].Time.Hours > 24)  // ���������� �������� �������� �����
	{
		if (!cin)
		{
			cout << "Error: ������� ����� ������� �� ���� ���� ������ �������! " << endl;
			cin.clear();  // �������� ������ �����
			cin.ignore(32767, '\n');  // �������� ������ �����
		}
		else if (List[atList].Time.Hours != int(List[atList].Time.Hours))
			cout << "Error: ������� ����� ������� �� ���� ���� ������ ������� ������! " << endl;
		else if (List[atList].Time.Hours < 0 || List[atList].Time.Hours > 24)
			cout << "Error: ������� ����������� ��������! " << endl;

		cout << "������ ������� ����� ������� (�� 0 �� 24) ����� #" << List[atList].Number << ": " << endl;
		cin >> List[atList].Time.Hours;
	}

	cout << "�������: ";
	cin >> List[atList].Time.Minutes;

	while (!cin || List[atList].Time.Minutes != int(List[atList].Time.Minutes)
		|| List[atList].Time.Minutes < 0 || List[atList].Time.Minutes > 60)  // ���������� �������� �������� �����
	{
		if (!cin)
		{
			cout << "Error: ������� ������ ������� �� ���� ���� ������ �������! " << endl;
			cin.clear();  // �������� ������ �����
			cin.ignore(32767, '\n');  // �������� ������ �����
		}
		else if (List[atList].Time.Minutes != int(List[atList].Time.Minutes))
			cout << "Error: ������� ������ ������� �� ���� ���� ������ ������� ������! " << endl;
		else if (List[atList].Time.Minutes < 0 || List[atList].Time.Minutes > 60)
			cout << "Error: ������� ����������� ��������! " << endl;

		cout << "������ ������� ������ ������� (�� 0 �� 60) ����� #" << List[atList].Number << ": " << endl;
		cin >> List[atList].Time.Minutes;
	}

	atList++;
	return;
}

void PrintList(Avia* List, const int atList)
{  // ������� ������ ������ ��������
	system("cls");  // �������� ������

	if (!atList)
	{
		cout << "� ������ �� ���� ������� ��������!" << endl;
		system("pause");  // �������� ��������� ����� �� ������
		return;
	}

	for (int i = 0; i < atList; i++)
	{
		cout << "����� ��������: " << List[i].Number << endl;
		cout << "��� �����: " << List[i].Type << endl;
		cout << "��� �������: " << List[i].Time.Hours << ':' << List[i].Time.Minutes << endl;

		for (int j = 0; j < 44; j++)
			cout << "--";                // ������������ �� ����������
		cout << endl;
	}

	system("pause");  // �������� ��������� ����� �� ������
	return;
}

void PrintType(Avia* List, const int atList)
{  // ������� ��� ������ �������� � �������� ����� �����
	system("cls");  // �������� ������

	if (!atList)
	{
		cout << "� ������ �� ���� ������� ��������!" << endl;
		system("pause");  // �������� ��������� ����� �� ������
		return;
	}

	cin.clear();  // �������� ������ �����
	cin.ignore(32767, '\n');  // �������� ������ �����
	string type;

	cout << "������ ��� �����, �� ���� ������ ������ �������: ";
	getline(cin, type);  // �������, ��� ����� ���� �������� ������, � �� �� ����� ���������

	bool work = false;
	for (int i = 0; i < atList; i++)
		if (List[i].Type == type)
		{
			work = true;

			cout << "����� ��������: " << List[i].Number << endl;
			cout << "��� �����: " << List[i].Type << endl;
			cout << "��� �������: " << List[i].Time.Hours << ':' << List[i].Time.Minutes << endl;

			for (int j = 0; j < 44; j++)
				cout << "--";                // ������������ �� ����������
			cout << endl;
		}

	if (!work)
	{
		cout << "�� ����, ������ � ����� �� ��� ���� ���� " << type << "." << endl;
		cout << "�������� ����������� ������ �� ��������� �� ���. " << endl;
	}

	system("pause");  // �������� ��������� ����� �� ������
	return;
}

void PrintTheFastest(Avia* List, const int atList)
{  // ������� ��� ������ �������� � ��������� ����� �������
	system("cls");  // �������� ������

	if (!atList)
	{
		cout << "� ������ �� ���� ������� ��������!" << endl;
		system("pause");  // �������� ��������� ����� �� ������
		return;
	}

	Avia Fastest = List[0];  // ��������� "�����������" �������

	for (int i = 0; i < atList; i++)
	{
		if (List[i].Time.Hours < Fastest.Time.Hours)
			Fastest = List[i];
		else if (List[i].Time.Hours == Fastest.Time.Hours && List[i].Time.Minutes < Fastest.Time.Minutes)
			Fastest = List[i];
	}

	cout << "���� � ��������� ����� �������: " << endl;

	for (int j = 0; j < 44; j++)
		cout << "--";                // ������������ �� ����������
	cout << endl;

	cout << "����� ��������: " << Fastest.Number << endl;
	cout << "��� �����: " << Fastest.Type << endl;
	cout << "��� �������: " << Fastest.Time.Hours << ':' << Fastest.Time.Minutes << endl;

	for (int j = 0; j < 44; j++)
		cout << "--";                // ������������ �� ����������
	cout << endl;

	system("pause");  // �������� ��������� ����� �� ������
	return;
}