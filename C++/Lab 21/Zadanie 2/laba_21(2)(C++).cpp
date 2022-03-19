#include <deque>
#include <algorithm>
#include <iostream>
#include <clocale>
#include <time.h>
using namespace std;
template <typename T>
void SetRandom(deque<T>& arr, int n);
template <typename T>
void Prosmotr(deque<T>& arr);
template <typename T>
void Prosmotr_iterator(deque<T>& arr);
template <typename T>
void SetIterator(deque<T>& arr,typename deque<T>::iterator& iter, int position);

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    deque<float> vec1;
    SetRandom(vec1, 10);
    cout << "Просмотр контейнера #1: ", Prosmotr(vec1);
    cout << endl;
    deque<float>::iterator iter_new_start, iter_new_end;
    SetIterator(vec1, iter_new_start, 3);
    SetIterator(vec1, iter_new_end, 7);
    vec1.erase(iter_new_start, iter_new_end);
    cout << "Удаление элементов в контейнере #1: ", Prosmotr(vec1);
    cout << endl;
    SetIterator(vec1, iter_new_start, 3);
    vec1.insert(iter_new_start, 100);
    cout << "Добавление элемента со значением 100 в контейнере #1: ", Prosmotr(vec1);
    cout << endl;
    cout << "Просмотр контейнера #1 с помощью итератора: ", Prosmotr_iterator(vec1);
    cout << endl;
    deque<float> vec2;
    SetRandom(vec2, 10);
    cout << "Просмотр контейнера #2: ", Prosmotr(vec2);
    cout << endl;
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    cout << "К контейнеру #1 добавляем элементы контейнера #2!" << endl;
    cout << "Просмотр контейнера #1: ", Prosmotr(vec1);
    cout << "Просмотр контейнера #2: ", Prosmotr(vec2);
}
template <typename T>
void SetRandom(deque<T>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = 5 - rand() % 10;
        arr.push_back(x); //push_back добавляет в конец элемент значение,которого задано параметром "x"
    }
}
template <typename T>
void Prosmotr(deque<T>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <typename T>
void Prosmotr_iterator(deque<T>& arr)
{
    deque<float>::iterator iter;
    for (iter = arr.begin(); iter != arr.end(); iter++) //метод begin отправит итератор начало контейнера,end-конец контейнера
    {
        cout << *iter << " ";
    }
    cout << endl;
}
template <typename T>
void SetIterator(deque<T>& arr, typename deque<T>::iterator& iter, int position)
{
    iter = arr.begin();
    for (int i = 0; i <= position; i++, iter++);
}