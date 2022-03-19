#include <deque>
#include <set>
#include <algorithm>
#include <iterator>
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
void SetIterator(deque<T>& arr, typename deque<T>::iterator& iter, int position);


int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    deque<float> vec1;
    int n = 0;
    SetRandom(vec1, 10);
    deque<float> vec2;
    SetRandom(vec2, 10);
    cout << "Просмотр контейнера(deque): ", Prosmotr(vec1);
    cout << endl;
    cout << "Просмотр контейнера(deque): ", Prosmotr(vec2);
    cout << endl;
    cout << "Выберите сортировку! 1-По возрастанию,2-по убыванию" << endl; cin >> n;
    if (n == 1) cout << "Вы выбрали сортировку по возрастанию!" << endl;
    else if (n == 2) cout << "Вы выбрали сортировку по убыванию!" << endl;
    switch (n)
    {
    case 1:
    {
        sort(vec1.begin(), vec1.end());
        cout << "Контейнер(deque) после сортировки по возрастанию: ", Prosmotr(vec1);
        break;
    }
    case 2:
    {
        sort(vec1.begin(), vec1.end(), greater<float>());
        cout << "Контейнер(deque) после сортировки по убыванию: ", Prosmotr(vec1);
        break;
    }
    default: cout << "По-русски же написано 1 или 2"; break;
    }
    deque<float>::iterator iter;
    iter = find(vec1.begin(), vec1.end(), -3);
    if (iter != vec1.end())
    {
        cout << "Заданный элемент найден" << endl;
    }
    else
    {
        cout << "Заданный элемент не найден" << endl;
    }
    multiset<float> multi1(vec2.begin(),vec2.end());
    cout << "Элементы deque теперь элементы multiset: ";
    for (auto i : multi1)
    {
        cout << i << " ";
    }
    cout << endl;
   /* multiset<float> multi2(vec1.begin(), vec1.end());*/
    deque<float> vec3(multi1.begin(), multi1.end());
    deque<float> vec4;
    SetRandom(vec4, 10);
    for (int i = 0; i < 10; i++)
    {
        vec4[i] = vec3[i] + vec1[i];
        cout << vec4[i] << " ";
    }
    
    //cout << "Мы добавили элементы deque в multiset: ";
    //copy(vec1.begin(), vec1.end(), ostream_iterator<float>(cout," "));
    //copy(vec1.begin(), vec1.end(), back_inserter(multi1));
    //cout << endl;

    //multiset<float>::iterator it = multi1.begin();
    //cout << "Отсортированный вариант: " << endl;
    //for (int i = 1; it != multi1.end(); i++, it++) 
    //{
    //    cout << *it << " ";
    //}
    //sort(multi1.begin(), multi1.end());
    /*int m = 0;
    cout << "Выберите сортировку! 1-По возрастанию,2-по убыванию" << endl; cin >> m;
    if (m == 1) cout << "Вы выбрали сортировку по возрастанию!" << endl;
    else if (m == 2) cout << "Вы выбрали сортировку по убыванию!" << endl;
    switch (m)
    {
    case 1:
    {
        sort(multi1.begin(), multi1.end());
        cout << "Контейнер(multiset) после сортировки по возрастанию: ";
        for (auto i : multi1)
        {
            cout << i << endl;
        }
        break;
    }
    case 2:
    {
        sort(multi1.begin(), multi1.end(), greater<float>());
        cout << "Контейнер(multiset) после сортировки по убыванию: ";
        for (auto i : multi1)
        {
            cout << i << endl;
        }
        break;
    }
    default: cout << "По-русски же написано 1 или 2"; break;
    }*/
   /* multi1.insert(multi1.end(), vec1.begin(), vec1.end());*/
    /*deque<float>::iterator iter_new_start, iter_new_end;
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
    cout << "Просмотр контейнера #2: ", Prosmotr(vec2);*/
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
