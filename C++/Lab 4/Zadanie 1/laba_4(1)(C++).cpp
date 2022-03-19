#include <iostream>
#include <locale.h>
#include <math.h>
#include <cstdlib>
using namespace std;


 int main()
{
	 /*сумму элементов массива, расположенных после максимального элемента.
	 Упорядочить элементы массива по убыванию модулей.*/
	setlocale(LC_ALL, "Russian");
	int a, b, n;
	int m[100];
	cout << "Введите кол-во элементов массива:"; cin >> n;
	cout << "Начальный массив:" << endl;
	for (int i = 0; i < n; i++)
	{
		m[i] = rand() % 50 - 25;
		cout << " " << m[i];
	}
	cout << endl;

	//поиск последнего максимального элемента
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (m[max] < m[i]) max = i;
		cout << "Позиция последнего максимального числа:" << max + 1 << endl;
		break;
	}

	//подсчитваем сумму после максимального
	int sum = 0;
	for (int i = max + 1; i < n; i++)
	{
		sum += m[i];
		cout << "Сумма чисел после максимального:" << sum << endl;
	}

	//cортировка массива
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (abs(m[i]) > abs(m[j]))
			{
				int temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
	cout << "Сортированный массив:" << endl;
	for (int i = 0; i < n; i++) cout << " " << m[i];
	cout << endl;

	/*количество элементов массива, лежащих в диапазоне от А до В;*/
	cout << "Введите начальный диапозон:"; cin >> a;
	cout << "Введите конечный диапазон:"; cin >> b;
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if ((m[i] > a)&&(m[i]<b)) k++;
	}
	cout << "Кол-во элементов,лежащих в диапазоне от " << a << " до " << b << "равно " << k << endl;
	return 0;
}