#include "Header.h"
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	FLOAT fl_1;
	cin >> fl_1;
	FLOAT fl_2;
	cin >> fl_2;
	float obj1 = fl_1;
	obj1 += obj1 + 2.71;
	int obj2 = fl_2;
	obj2 = obj2 - 1;
	cout << "Тип float:" << obj1 << "\t\tТип int:" << obj2 << "\t\tМинимальное из 2-ух аргументов:" << fl_1.min(fl_1, fl_2);
	return 0;
}