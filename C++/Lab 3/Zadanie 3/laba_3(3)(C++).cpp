#include <locale.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float x1, x2, dx=0, x,i,eps;
	cout << "Vvedite |X|>1:"; cin >> x;
	cout << "Vvedite X1:"; cin >> x1;
	cout << "Vvedite X2:"; cin >> x2;
	cout << "Vvedite SHAG:"; cin >> dx;
	cout << "Vvedite Tochnost eps(0<eps<1):"; cin >> eps;
	if (x2 < x1 || dx < 0)
	{
	    cout << "Конечная точка всегда больше начальной и шаг не может быть отрицательынм" << endl;
		return 0;
	}
	if (eps < 0 || eps >1)
	{
		cout << "Написано же,что 0<eps<1" << endl;
		return 0;
	}
	float a = x, y = a; // первый член ряда и начальное значение суммы
	for (i = x1; i<x2; i+=dx)
	{
		x *= 1 / x + (1 / (3 * pow(x, 3))) + (1 / (5 * pow(x, 5)));
		y += a; // добавление члена ряда к сумме
		cout << "Значение функции:" << y << " для x=" << x << " За кол-во итераций:" << i << endl;
	}
	cout << endl;
	//cout << "Значение функции:" << y << " для x=" << x << " За кол-во итераций:" << i << endl;
	return 0;
}
