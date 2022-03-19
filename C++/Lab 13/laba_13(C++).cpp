#pragma once
#include "module.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <locale.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int N = 0;
	while (true)
	{
		cout << "Кого вы хотите выбрать(1-студент,2-преподователь,3-выход):"; cin >> N;
		if (N == 1)
		{
			cout << "Вы выбрали студента:" << endl;
		}
		else if (N == 2)
		{
			cout << "Вы выбрали преводователя:" << endl;
		}
		else if (N == 3)
		{
			cout << "Вы выбрали выход из программы:" << endl;
		}
		switch (N)
		{
		case 1:
		{
			human human1;
			human* px = &human1;
			student student1;
			human1.SetStorona1(4,2);
			student1.SetStorona1(3,4);
			//px->SetStorona1(2,3);
			px = &student1;
			//px->SetStorona1(2, 3);
			cout << endl;
			px->func();
			cout << endl;
			break;
		}
		case 2:
		{
			human human1;
			human* px = &human1;
			professor professor1;
			human1.SetFio("Александр");
			px = &professor1;
			professor1.SetFio("Генри");
			px = &professor1;
			//px->print();
			cout << endl;
			px->func();
			cout << endl;
			break;
		}
		case 3: {return 0; break; }
		default: cout << "Выберите другое значение:" << endl;
		}
	}
}