#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void SetRandom(deque<float>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = 5 - rand() % 10;
        arr.push_back(x); //push_back добавляет в конец элемент значение,которого задано параметром "x"
    }
}
void Prosmotr(deque<float>& arr) //обращение к элементам посредством индекса
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
bool Poisk_predikat1(float item)
{   //предикат-ф-ция,которая возвращает логическое значение,т.е. да/нет
    return item > 0;
}
void SetIterator(deque<float>& arr, deque<float>::iterator& iter, int position)
{
    iter = arr.begin();
    for (int i = 0; i <= position; i++, iter++);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    deque<float> d1;
    SetRandom(d1, 10);
    cout << "Заполнение рандомными числами с помощью индекса: ", Prosmotr(d1);
    cout << "Заполнение рандомными числами с помощью итератора: ", Prosmotr_iterator(d1);
    deque<float>::iterator iter = min_element(d1.begin(), d1.end());
    cout << "Минимальный элемент:" << *iter << endl;
    iter = find(d1.begin(), d1.end(), -3); //find-поиск совпадающих элементов и возвращение итератора для первого найденного совпадения
    if (iter != d1.end())
    {
        cout << "Заданный элемент найден" << endl;
    }
    else
    {
        cout << "Заданный элемент не найден" << endl;
    }
    // элементы> 0
    int cnt = count_if(d1.begin(), d1.end(), Poisk_predikat1); //count_if-возвращает кол-во элементов,удолетворяющих диапазону
    cout << "Кол-во элементов >0: " << cnt << endl;
    deque<float>::iterator iter_new_start, iter_new_end;
    SetIterator(d1, iter_new_start, 3);
    SetIterator(d1, iter_new_end, 7);
    d1.erase(iter_new_start, iter_new_end); //erase-удаляет элементы в диапазоне от start до end и возвращает итератор для элемента, расположенного за последним удаленным элементом
    cout << "Удаление элементов после iter_new_start: ", Prosmotr(d1);
    SetIterator(d1, iter_new_start, 3);
    d1.insert(iter_new_start, 100); //insert-вставляет значение "100" перед элементом,заданным параметром iter_new_start и возвращает итератор для этого элемента
    cout << "Тоже самое + добавление элемента со значением 100: ", Prosmotr_iterator(d1);
}