#pragma once
#include <string>  // директива препроцесора для зручної роботи зі строками

using namespace std;  // використання імен std

struct Flight
{  // структура для зберігання часу польоту
	double Hours;
	double Minutes;
};

struct Avia
{  // cтруктура авіарейсу
	double Number;
	string Type;
	Flight Time;
};