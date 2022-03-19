#include <iostream>
#include <locale.h>
#include <math.h>
#include <cstdlib>
using namespace std;

void zapolnit(int *m, int n);
void pokaz1(int *m, int n);
int poisk(int *m, int n);
int summa(int *m, int max, int n);
void sort(int *m, int n);
void pokaz2(int *m, int n);
int kol(int a, int b, int *m, int n);

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b, n;
	int m[100];
	cout << "Введите кол-во элементов массива:"; cin >> n;
	cout << "Начальный массив:" << endl;
	zapolnit(m, n);
	pokaz1(m, n);
	poisk(m, n);
	int max = poisk(m, n);
	cout << "Позиция последнего максимального числа:" << max + 1 << endl;
	int sum = summa(m, max, n);
	cout << "Сумма чисел после максимального:" << sum << endl;
	sort(m, n);
	cout << "Сортированный массив:" << endl;
	pokaz2(m, n);
	cout << "Введите начальный диапозон:"; cin >> a;
	cout << "Введите конечный диапазон:"; cin >> b;
	int k = kol(a, b, m, n);
	cout << "Кол-во элементов,лежащих в диапазоне от " << a << " до " << b << " равно " << k << endl;
    return 0;
}
void zapolnit(int* m, int n)
{
	for (int i = 0; i < n; i++) m[i] = rand() % 50 - 25;
}

void pokaz1(int *m, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " " << m[i];
		cout << endl;
	}
}

int poisk(int *m,int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (m[max] < m[i]) max = i;
	}
	return max;
}

int summa(int *m,int max,int n)
{
	int sum = 0;
	for (int i = max + 1; i < n; i++)
	{
		sum += m[i];
	}
	return sum;
}

void sort(int *m,int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (abs(m[i]) > abs(m[j]))
			{
				int temp = m[i];
				m[i] = m[j];
				m[j] = temp;
			}
}

void pokaz2(int* m, int n)
{
	for (int i = 0; i < n; i++) cout << " " << m[i];
	cout << endl;
}

int kol(int a,int b,int *m,int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if ((m[i] > a) && (m[i] < b)) k++;
	}
	return k;
}
