#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int x, k = 0;
	string str;
	cout << "Введите строку:"; getline(cin,str);
	x = size(str);
	for (int i = 0; i < x; i++)
	{
		if ((str[i] > 96) && (str[i] < 123)) k++;
	}
	cout << "Кол-во строчных латинских букв:" << k << endl;
	return 0;

}
