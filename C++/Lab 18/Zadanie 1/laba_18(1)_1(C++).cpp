#include "Header.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Queue queue1, queue2;
    for (int i = 1; i <= 5; i++) 
    {
        queue1.push(i);
    }
    cout << "Изначальная очередь:",queue1.print();
    cout << endl;
    --queue1;
    queue1.print();
    ++queue1;
    queue1.print();
    queue1--;
    queue1.print();
    queue1++;
    queue1.print();
    /////*cout << "введите еще элемент: ";
    ////int n;
    ////cin >> n;
    ////queue1.push(n);
    ////cout << "теперь очередь имеет следующий вид" << endl;
    ////queue1.print();
    ////cout << endl;
    ////cout << "Размер очереди:" << endl;
    ////cout << queue1.sizee();
    ////cout << endl;
    ////cout << "дальний элемент:" << endl;
    ////cout << queue1.back();
    ////cout << endl;
    ////cout << "ближний элемент" << endl;
    ////cout << queue1.front();
    ////cout << endl;
    ////cout << "удаление элемента";
    ////queue1.pop();
    ////cout << endl;
    ////cout << "текущие данные";
    ////queue1.print();
    ////cout << endl;
    ////cout << "еще одно добавление элемента";
    ////queue1.push(n);
    ////queue1.print();
    ////cout << endl;*/
    return 0;
}