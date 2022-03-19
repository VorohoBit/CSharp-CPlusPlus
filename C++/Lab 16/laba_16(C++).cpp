#include "Header.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
    int N;
    while (true)
    {
        cout << "Что вы хотите выбрать?(1-вычитание векторов,2-доступ по индесу,3-вычесть из вектора число,4-выход):"; cin >> N;
        if (N == 1) cout << "Вы выбрали вычитание векторов" << endl;
        else if (N == 2) cout << "Вы выбрали доступ по индексу" << endl;
        else if (N == 3) cout << "Вы выбрали вычесть из вектора" << endl;
        else if (N == 4) cout << "Вы выбрали выход из программы" << endl;
        switch (N)
        {
        case 1:
        {
            massive<double> massive1(10);
            massive<double> massive2(10);
            massive1.input(5);
            massive2.input(5);
            massive2 = massive2 - massive1;
            massive2.print();
            cout << endl;
            break;
        }
        case 2:
        {
            massive<double> massive1(10);
            massive<double> massive2(10);
            massive1.input(5);
            cout << massive1[3] << endl;
            cout << endl;
            break;
        }
        case 3:
        {
            massive<double> massive1(10);
            massive1.input(5);
            double number = 0;
            cout << "Введите число,на которое хотите вычесть вектор:" << endl; cin >> number;
            massive1.o(number);
            massive1.print();
            cout << endl;
            break;

        }
        case 4:
        {
            return 0; break;
        }
        default: {cout << "Вы выбрали неправильное значение" << endl; break; }
        }

    }
}