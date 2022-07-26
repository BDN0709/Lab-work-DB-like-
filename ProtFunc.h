#pragma once
#include "Structs.h" // директива підключення .h-файлу з описом структур

void Menu(Avia*, const int&, int&);  // прототип основної виконавчої функції
void AddFlight(Avia*, const int&, int&);  // прототип функції для додавання авіарейсу в довідник
void PrintList(Avia*, const int);  // прототип функції для виводу усього списку авіарейсів
void PrintType(Avia*, const int); // прототип функції для пошуку авіарейсу за типом літака
void PrintTheFastest(Avia*, const int); // прототип функції для пошуку компанії з найменшим часом польоту

#include "RFunc.h" // директива підключення .h-файлу з реалізацєю функцій для коректної роботи коду