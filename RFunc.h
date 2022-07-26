#pragma once
#include <iostream> // директива потокового вводу-виводу даних
#include <cstdlib> // директива підключення бібліотеки для зручної роботи зі строками
#include <string>  // директива препроцесора для зручної роботи зі строками
#include "Structs.h" // директива підключення .h-файлу з описом структур
#include "ProtFunc.h"  // підключення .h-файлу для повного функціоналу пізніше описаних функцій

using namespace std;  // використання простору імен std для коректної роботи коду

void Menu(Avia* List, const int& size, int& atList) // головна виконавча функція
{
	while (true)
	{
		system("cls");  // очищення консолі
		double answer;  // змінна "відповідь"
		cout << "0 - Закрити програму " << endl;
		cout << "1 - Додати авіарейс в довідник " << endl;
		cout << "2 - Вивести список авіарейсів " << endl;
		cout << "3 - Вивести список авіарейсів із вказаним типом літака " << endl;
		cout << "4 - Знайти авіарейс з мінімальним часом польоту " << endl;
		cin >> answer;
		while (!cin || answer != int(answer) || answer < 0 || answer > 4)
		{                  // комплексна перевірка введених даних
			if (!cin)
			{
				cout << "Error: пункт меню не може бути заданий строкою! " << endl;
				cin.clear();  // очищення буфера вводу
				cin.ignore(32767, '\n');  // очищення буфера вводу
			}

			else if (answer != int(answer) || answer < 0 || answer > 4)
				cout << "Error: обрано неіснуючий пункт меню! " << endl;

			cout << "Виберіть пункт меню від 0 до 4: " << endl;
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
{  // функція додавання авіарейсу в довідник
	system("cls");  // очищення консолі

	if (atList == size)
	{
		cout << "Досягнуто поріг максимально допустимої кількості рейсів в списку! " << endl;
		cout << "На жаль, більше вносити авіарейси у список неможливо. " << endl;
		system("pause");  // затримка виведених даних на консолі
		return;
	}

	cout << "Введіть номер рейсу: ";
	cin >> List[atList].Number;

	while (!cin)
	{
		cout << "Error: номер рейсу не може бути заданий строкою! " << endl;
		cin.clear();  // очищення буфера вводу
		cin.ignore(32767, '\n');  // очищення буфера вводу
		cout << "Введіть номер рейсу: ";
		cin >> List[atList].Number;
	}

	cin.clear();  // очищення буфера вводу
	cin.ignore(32767, '\n');  // очищення буфера вводу

	cout << "Введіть тип літака: ";
	getline(cin, List[atList].Type);  // функція, щоб можна було записати строку, а не до першої прогалини

	cout << "Введіть час польоту рейсу #" << List[atList].Number << ": " << endl;

	cout << "Години: ";
	cin >> List[atList].Time.Hours;

	while (!cin || List[atList].Time.Hours != int(List[atList].Time.Hours)
		|| List[atList].Time.Hours < 0 || List[atList].Time.Hours > 24)  // комплексна перевірка введених даних
	{
		if (!cin)
		{
			cout << "Error: кількість годин польоту не може бути задана строкою! " << endl;
			cin.clear();  // очищення буфера вводу
			cin.ignore(32767, '\n');  // очищення буфера вводу
		}
		else if (List[atList].Time.Hours != int(List[atList].Time.Hours))
			cout << "Error: кількість годин польоту не може бути задана нецілим числом! " << endl;
		else if (List[atList].Time.Hours < 0 || List[atList].Time.Hours > 24)
			cout << "Error: введено недопустиме значення! " << endl;

		cout << "Введіть кількість годин польоту (від 0 до 24) рейсу #" << List[atList].Number << ": " << endl;
		cin >> List[atList].Time.Hours;
	}

	cout << "Хвилини: ";
	cin >> List[atList].Time.Minutes;

	while (!cin || List[atList].Time.Minutes != int(List[atList].Time.Minutes)
		|| List[atList].Time.Minutes < 0 || List[atList].Time.Minutes > 60)  // комплексна перевірка введених даних
	{
		if (!cin)
		{
			cout << "Error: кількість хвилин польоту не може бути задана строкою! " << endl;
			cin.clear();  // очищення буфера вводу
			cin.ignore(32767, '\n');  // очищення буфера вводу
		}
		else if (List[atList].Time.Minutes != int(List[atList].Time.Minutes))
			cout << "Error: кількість хвилин польоту не може бути задана нецілим числом! " << endl;
		else if (List[atList].Time.Minutes < 0 || List[atList].Time.Minutes > 60)
			cout << "Error: введено недопустиме значення! " << endl;

		cout << "Введіть кількість хвилин польоту (від 0 до 60) рейсу #" << List[atList].Number << ": " << endl;
		cin >> List[atList].Time.Minutes;
	}

	atList++;
	return;
}

void PrintList(Avia* List, const int atList)
{  // функція виводу списку авіарейсів
	system("cls");  // очищення консолі

	if (!atList)
	{
		cout << "В списку ще немає жодного авіарейсу!" << endl;
		system("pause");  // затримка виведених даних на консолі
		return;
	}

	for (int i = 0; i < atList; i++)
	{
		cout << "Номер авіарейсу: " << List[i].Number << endl;
		cout << "Тип літака: " << List[i].Type << endl;
		cout << "Час польоту: " << List[i].Time.Hours << ':' << List[i].Time.Minutes << endl;

		for (int j = 0; j < 44; j++)
			cout << "--";                // розмежування між авіарейсами
		cout << endl;
	}

	system("pause");  // затримка виведених даних на консолі
	return;
}

void PrintType(Avia* List, const int atList)
{  // функція для виводу авіарейсу з вказаним типом літака
	system("cls");  // очищення консолі

	if (!atList)
	{
		cout << "В списку ще немає жодного авіарейсу!" << endl;
		system("pause");  // затримка виведених даних на консолі
		return;
	}

	cin.clear();  // очищення буфера вводу
	cin.ignore(32767, '\n');  // очищення буфера вводу
	string type;

	cout << "Введіть тип літака, за яким хочете знайти авіарейс: ";
	getline(cin, type);  // функція, щоб можна було записати строку, а не до першої прогалини

	bool work = false;
	for (int i = 0; i < atList; i++)
		if (List[i].Type == type)
		{
			work = true;

			cout << "Номер авіарейсу: " << List[i].Number << endl;
			cout << "Тип літака: " << List[i].Type << endl;
			cout << "Час польоту: " << List[i].Time.Hours << ':' << List[i].Time.Minutes << endl;

			for (int j = 0; j < 44; j++)
				cout << "--";                // розмежування між авіарейсами
			cout << endl;
		}

	if (!work)
	{
		cout << "На жаль, жодним з рейсів не літає літак типу " << type << "." << endl;
		cout << "Перевірте правильність запиту та спробуйте ще раз. " << endl;
	}

	system("pause");  // затримка виведених даних на консолі
	return;
}

void PrintTheFastest(Avia* List, const int atList)
{  // функція для пошуку авіарейсу з найменшим часом польоту
	system("cls");  // очищення консолі

	if (!atList)
	{
		cout << "В списку ще немає жодного авіарейсу!" << endl;
		system("pause");  // затримка виведених даних на консолі
		return;
	}

	Avia Fastest = List[0];  // екземпляр "найшвидшого" польоту

	for (int i = 0; i < atList; i++)
	{
		if (List[i].Time.Hours < Fastest.Time.Hours)
			Fastest = List[i];
		else if (List[i].Time.Hours == Fastest.Time.Hours && List[i].Time.Minutes < Fastest.Time.Minutes)
			Fastest = List[i];
	}

	cout << "Рейс з мінімальним часом польоту: " << endl;

	for (int j = 0; j < 44; j++)
		cout << "--";                // розмежування між авіарейсами
	cout << endl;

	cout << "Номер авіарейсу: " << Fastest.Number << endl;
	cout << "Тип літака: " << Fastest.Type << endl;
	cout << "Час польоту: " << Fastest.Time.Hours << ':' << Fastest.Time.Minutes << endl;

	for (int j = 0; j < 44; j++)
		cout << "--";                // розмежування між авіарейсами
	cout << endl;

	system("pause");  // затримка виведених даних на консолі
	return;
}