#pragma once
#include <iostream>
#include <clocale>
#include <cassert>
using namespace std;

class Queue
{
private:
    int* arr;
    int size = 100;
    int begin, end;
    friend Queue& operator --(Queue& tmp);
    friend Queue& operator --(Queue& tmp, int);
public:
    Queue()
    {
        arr = new int[size];
        begin = 0, end = 0;
    }
    void print()
    {
        for (int i = begin + 1; i < end + 1; i++)
            cout << arr[i] << " ";
    }
    void push(int num)
    {
        if (end + 1 == begin || (end + 1 == size && !begin))
        {
            cout << "Очередь полна" << endl;
        }
        end++;
        if (size == end) end = 0;
        arr[end] = num;
    }
    void pop()
    {
        if (begin == end)
        {
            cout << "Очередь пуста" << endl;
        }
        begin++;
        if (begin == size) begin = 0;
    }
    int sizee()
    {
        int s = 0;
        for (int i = begin; i < end; i++) s++;
        return s;
    }
    int back()
    {
        return arr[end];
    }
    int front()
    {
        return arr[begin + 1];
    }
    Queue& operator ++()
    {
        cout << endl;
        cout << "Префикс ++" << endl;
        for (int i = begin; i <= end; i++) arr[i] *= 10;
        return*this;
    }
    Queue& operator ++(int k)
    {
        cout << endl;
        cout << "Постфикс ++" << endl;
        for (int i = begin; i <=end; i++) arr[i] *= 2;
        return *this;
    }
};
Queue& operator --(Queue& temp)
{
    cout << endl;
    cout << "Префикс --" << endl;
    for (int i = temp.begin; i <= temp.end; i++) temp.arr[i] *= 10;
    return temp;
}
Queue& operator --(Queue& temp, int k)
{
    cout << endl;
    cout << "Постфикс --" << endl;
    for (int i = temp.begin; i <= temp.end; i++) temp.arr[i] = temp.arr[i] * 2 + k;
    return temp;
}