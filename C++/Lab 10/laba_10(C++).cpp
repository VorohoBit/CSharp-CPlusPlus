#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <locale.h>
using namespace std;

class kvitka
{
private:
    int nomer;
    char data[20];
    float sum;
public:
    kvitka(); //конструктор-это метод, предназначенный для инициализации объекта и вызывающийся автоматически при его создании.
    ~kvitka();  //деструктор-особый вид метода,применяющийся для освобождения памяти,занимаемой объектом
    //имя деструктора начинается с ~(тильда) потом идет имя класса
    void SetNomer(int nomer);
    void SetData(char const* data);
    void SetSum(float sum);
    int getNomer() const;
    const char* getData() const;
    float getSum() const;
    void print();
};

kvitka::kvitka()
{
}
kvitka::~kvitka()
{
}
void kvitka::SetNomer(int nomer) // ::указывает на то,что ф-ция SetNomer принадлежит классу kvitka
{
    this->nomer= nomer; //this указывает на то,что переменная принадлежит классу
}
void kvitka::SetData(const char* data) 
{
    strcpy(this->data,data); //strcpy копирует  
}
void kvitka::SetSum(float sum)
{
    this->sum=sum;
}
int kvitka::getNomer() const
{
    return this->nomer;
}
const char* kvitka::getData() const
{
    return this->data;
}
float kvitka::getSum() const
{
    return this->sum;
}
void kvitka::print()
{
    cout << "Номер:" << this->getNomer() << endl;
    cout << "Дата:" << this->getData() << endl;
    cout << "Сумма:" << this->getSum() << endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    const int N = 5;
    kvitka arr[N];
    int nomer;
    char data[20];
    float sum;
    for (int i = 0; i < N; i++)
    {
        cout << "Номер квитанции:" << i + 1 << endl;
        cout << "Номер:"; cin >> nomer;
        cout << "Дата:"; cin >> data;
        cout << "Сумма:"; cin >> sum;
        arr[i].SetNomer(nomer);
        arr[i].SetData(data);
        arr[i].SetSum(sum);
    }
    cout << endl;
    for (int i = 0; i < N; i++) arr[i].print();
    cout << "     Номер    | Дата       | Сумма" << endl;
    for (int i = 0; i < N; i++)
    {
        cout.width(14);
        cout << arr[i].getNomer() << "|";
        cout.width(12);
        cout << arr[i].getData() << "|";
        cout << arr[i].getSum() << endl;
    }
    return 0;
}