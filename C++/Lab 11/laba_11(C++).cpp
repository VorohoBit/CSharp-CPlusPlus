#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "module.h"
#include <iostream>
#include <locale.h>
#include <cstring>
using namespace std;

//class kvitka
//{
//private:
//    int nomer;
//    char *data;
//    float sum;
//public:
//    kvitka();
//    kvitka(int nomer, const char* data, float sum);
//    kvitka(const kvitka& kvitka);
//    ~kvitka();
//    void SetNomer(int nomer);
//    void SetData(char const* data);
//    void SetSum(float sum);
//    int getNomer() const;
//    const char* getData() const;
//    float getSum() const;
//    void input();
//    void print();
//};

//kvitka::kvitka()
//{
//    this->SetNomer(0);
//    this->data = new char[20];
//    this->SetData("");
//    this->SetSum(0.0);
//}
//kvitka::kvitka(int nomer, const char* data, float sum)
//{
//    this->SetNomer(nomer);
//    this->data = new char[20];
//    this->SetData(data);
//    this->SetSum(sum);
//}
//kvitka::kvitka(const kvitka& kvitka)
//{
//    this->SetNomer(kvitka.getNomer());
//    this->data = new char[20];
//    this->SetData(kvitka.getData());
//    this->SetSum(kvitka.getSum());
//}
//kvitka::~kvitka()
//{
//    delete[] this->data;
//}
//void kvitka::SetNomer(int nomer) // ::указывает на то,что ф-ция SetNomer принадлежит классу kvitka
//{
//    this->nomer = nomer; //this указывает на то,что переменная принадлежит классу
//}
//void kvitka::SetData(const char* data)
//{
//    strcpy(this->data, data); //strcpy копирует  
//}
//void kvitka::SetSum(float sum)
//{
//    this->sum = sum;
//}
//int kvitka::getNomer() const
//{
//    return this->nomer;
//}
//const char* kvitka::getData() const
//{
//    return this->data;
//}
//float kvitka::getSum() const
//{
//    return this->sum;
//}
//void kvitka::input()
//{
//    cout << "Напишите данные в квитанцию:" << endl;
//    cout << "Номер:";
//    int nomer; cin >> nomer; this->SetNomer(nomer);
//    cout << "Дата:";
//    char data[20]; cin >> data; this->SetData(data);
//    cout << "Сумма:";
//    float sum; cin >> sum; this->SetSum(sum);
//}
//void kvitka::print()
//{
//    cout << endl;
//    cout << "Номер:" << this->getNomer() << endl;
//    cout << "Дата:" << this->getData() << endl;
//    cout << "Сумма:" << this->getSum() << endl;
//}

int main()
{
    setlocale(LC_ALL, "Russian");
    kvitka* kvitka_1 = new kvitka();
    kvitka_1->input();
    kvitka_1->print();
    kvitka* kvitka_2 = new kvitka(64,"07.03.2021",20.49);
    kvitka_2->print();
    kvitka* kvitka_3 = new kvitka(*kvitka_1);
    kvitka_3->print();
    kvitka_3->input();
    kvitka_3->print();
    delete kvitka_1;
    delete kvitka_2;
    delete kvitka_3;
    return 0;
}