#include <iostream>
#include <locale.h>
#define size 10

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, n,choose1,choose2;
	int mas[size][size] = { 0 };
	int MAS[size];
	int right = 1, down;
	using std::endl;
	using std::cout;
	using std::cin;
	//заполняем в массиве "прямоугольник" из единиц
	for (i = 0; i < size - 4; i++)
		for (j = 0; j < size - 4; j++)
			mas[i][j] = 1;
		//вывод массива
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				cout <<  " " << mas[i][j];
			puts("");
		}
		cout << "Куда двигать матрицу? 1-вправо 2-вниз 0-выход" << endl;  cin >> choose1;
		cout << "Насколько двигать?" << endl; cin >> choose2;
		int begin = 0; //начало матрицы
		int position = begin + choose2 - 1; //позиция записи в промежуточный массив
		for (j = 0; j < size; j++)
		{
			for (i = 0; i < size; i++) //копируем числа в промежуточный массив
			{
				if (position >= size - 1) position = begin;
				else position++;
				if (choose1 == right) MAS[position] = mas[j][i];
				else MAS[position] = mas[i][j];
			}
				for (i = 0; i < size; i++) //копируем числа обратно в другом порядке
					if (choose1 == right) mas[j][i] = MAS[i];
					else mas[i][j] = MAS[i];
		}
	return 0;
}