#include <iostream>
#include <deque>
#include <algorithm>
#include <clocale>
#include <math.h>
using namespace std;
void SetRandom(deque<float>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = 5 - rand() % 10;
        arr.push_back(x); //push_back добавляет в конец элемент значение,которого задано параметром "x"
        //arr.push_front(x)-специальный метод для deque,который добавляет элемент в начало контейнера
    }
}
void Prosmotr_iterator(deque<float>& arr) //обращение к элементам посредством итератора
{   //итератор-интерфейс,предостовляющий доступ к элементам коллекции(массива/контейнера) и навигацию по ним
    deque<float>::iterator iter;
    for (iter = arr.begin(); iter != arr.end(); iter++) //метод begin отправит итератор начало контейнера,end-конец контейнера
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    deque<float> d1;
    SetRandom(d1, 10);
    cout << "Заполнение рандомными числами с помощью итератора: ", Prosmotr_iterator(d1);
                                              //ищем позицию максимального числа и сумму после максимального
    // 1 способ
    int max = 0;
    for (int i = 1; i < d1.size(); i++)
    {
        if (d1[max] < d1[i]) max = i;
    }
    cout << "Позиция последнего максимального числа:" << max+1 << endl;
    int sum = 0;
    for (int i = max+1; i < d1.size(); i++)
    {
        sum += d1[i];
    }
    cout << "Сумма чисел после максимального:" << sum << endl;
    //2 способ
    deque<float>::iterator iter;
    int max0 = 0;
    for (iter = d1.begin(); iter != d1.end(); iter++)
    {
        if (d1[max0] < *iter) max0 = (*iter);
    }
    cout << "Позиция последнего максимального числа с помощью итератора: " << max0 + 1 << endl;
    int sum0 = 0;
    //2 способ
    deque<float>::iterator iter_new_start, iter_new_end;
    //SetIterator(d1, iter_new_start, max0);
    for (iter_new_start = d1.begin() + max0 + 1; iter_new_start != d1.end(); iter_new_start++)
    {
        sum0 += (*iter_new_start);
    }
    cout << "Сумма чисел после максимального с помощью итератора: " << sum0 << endl;
                                              //кол-во элементов в диапазоне от a до b
    int k = 0;
    int a; cout << "Введите начальный диапазон: "; cin >> a;
    int b; cout << "Введите конечный диапазон: "; cin >> b;
    for (int i = 0; i < d1.size(); i++)
    {
        if ((d1[i] > a) && (d1[i] < b)) k++;
    }
    cout << "Кол-во элементов,лежащих в диапазоне от " << a << " до " << b << " равно " << k << endl;
                                              //сортировка по модулю по убыванию
    for (int i = 0; i < d1.size(); i++)
        for (int j = 0; j < d1.size(); j++)
            if (abs(d1[i]) > abs(d1[j]))
            {
                int temp = d1[i];
                d1[i] = d1[j];
                d1[j] = temp;
            }
    cout << "Сортированный массив:" << endl;
    for (int i = 0; i < d1.size(); i++) cout << " " << d1[i];
    cout << endl;
}