#pragma once
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class List {
private:
    Node* node;
public:
    Node* head = NULL;
    List()
    {
        Node* head = NULL;
    }
    int size()
    {
        node = head;
        int k = 0;
        while (node != NULL)
        {
            k++;
            node = node->next;
        }
        return k;
    }
    //void add_front(int data) //ф-ция добавления элемента в начало списка
    //{
    //    node = new Node; // создали новый элемент
    //    node->data = data; // записали в него значение
    //    node->next = head; // предыдущее начало записали как следующее
    //    head = node; // поставили созданный элемент в начало
    //}
    void add_back(int data) 
    {
        node = new Node; // создали новый элемент
        node->data = data; // записали в него значение
        node->next = NULL; // предыдущее начало записали как NULL
        if (head == NULL) // если начало не равно NULL
        {
            head = node; // поставили созданный элемент в конец
        }
        else
        {
            Node* curr = head; //текущий элемент равен началу
            while (curr->next != NULL) //предыдущее начало текущего элемент не равно NULL
            {
                curr = curr->next; // предыдущее начало записали как следующее
            }
            curr->next = node; // поставили текущий элемент в конец
        }
    }
    void del(Node** node, int key) //ф-ция удаления элемента из списка
    {
        bool flag = false;
        Node* curr, * prev;
        prev = NULL;
        for (curr = *node; curr != NULL; prev = curr, curr = curr->next)
        {
            if (curr->data == key)
            {
                flag = true;
                if (prev == NULL)
                {
                    *node = curr->next;
                }
                else
                {
                    prev->next = curr->next;
                }
                delete curr;
            }
        }
        if (!flag)
        {
            cout << "Нет таких элементов,которые можно удалить" << endl;
        }
    }
    void find(int index) //Функция получения элемента по его индексу 
    {
        if (index >= 0 && index < size())
        {
            Node* node = head;
            int ans, k = 0;
            while (node != NULL)
            {
                if (k == index)
                {
                    cout << node->data << endl;
                    break;
                }
                node = node->next;
                k++;
            }
        }
        else
        {
            cout << "Элемент с заданным индексом не существует!" << endl;
        }
    }
    void extract(int l, int r) //ф-ция получения части списка между двумя заданными индексами (включительно)
    {
        if (l < r && l >= 0 && r < size())
        {
            Node* node = head;
            int k = 0;
            while (node != NULL)
            {
                if (k >= l && k <= r)
                {
                    cout << node->data << " ";
                }
                k++;
                node = node->next;
            }
        }
        else
        {
            cout << "Данного интервала не существует!" << endl;
        }
    }
    void print() //ф-ция вывода списка на экран
    {
        node = head;
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
    List& operator+(const int& data)  //Перегрузка оператора добавления элемента в конец списка +
    {
        add_back(data);
        return *this;
    }
    List& operator+=(const int& data) //Перегрузка оператора добавления элемента в начало списка +
    {
        add_back(data);
        return *this;
    }
    List& operator-(const int& data) //Перегрузка оператора удаления заданного элемента из списка +
    {
        del(&head, data);
        return *this;
    }
    List& operator[](const int& index) //Перегрузка оператора получения элемента списка по его индексу +
    {
        find(index);
        return *this;
    }
    List& operator()(int l, int r) //Перегрузка оператора вызов функции для вывода части списка +
    {
        extract(l, r);
        return *this;
    }
    List& operator=(List obj) //Перегрузка оператора присваивания +
    {
        swap(head, obj.head);
        return *this;
    }
    List& operator++() //Перегрузка оператора пре-инкремента
    {
        head = head->next;
        return *this;
    }
    List& operator++(int) //Перегрузка оператора пост-инкремента
    {
        head = head->next;
        return *this;
    }
    friend bool operator==(List& lhs, List& rhs);
    friend bool operator!=(List& lhs, List& rhs);
    friend bool operator>(List& lhs, List& rhs);
    friend bool operator<(List& lhs, List& rhs);
    friend bool operator>=(List& lhs, List& rhs);
    friend bool operator<=(List& lhs, List& rhs);
};
bool operator==(List& lhs, List& rhs) //Перегрузка операции проверки двух списков на равенство
{
    Node* a = lhs.head;
    Node* b = rhs.head;
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
        {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    if (lhs.size() != rhs.size())
    {
        return false;
    }
    return true;
}

bool operator!=(List& lhs, List& rhs) //Перегрузка операции проверки двух списков на неравенство
{
    Node* a = lhs.head;
    Node* b = rhs.head;
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
        {
            return true;
        }
        a = a->next;
        b = b->next;
    }
    if (lhs.size() != rhs.size())
    {
        return true;
    }
    return false;
}

bool operator>(List& lhs, List& rhs) //Перегрузка операции ">" для списков равной длины
{
    Node* a = lhs.head;
    Node* b = rhs.head;
    while (a != NULL && b != NULL) {
        if (a->data > b->data) {
            return true;
        }
        a = a->next;
        b = b->next;
    }
    return false;
}

bool operator<(List& lhs, List& rhs) { //Перегрузка операции "<" для списков равной длины
    Node* a = lhs.head;
    Node* b = rhs.head;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            return true;
        }
        a = a->next;
        b = b->next;
    }
    return false;
}

bool operator>=(List& lhs, List& rhs) //Перегрузка операции ">=" для списков равной длины
{
    Node* a = lhs.head;
    Node* b = rhs.head;
    while (a != NULL && b != NULL)
    {
        if (a->data >= b->data)
        {
            return true;
        }
        a = a->next;
        b = b->next;
    }
    return false;
}

bool operator<=(List& lhs, List& rhs)  //Перегрузка операции "<=" для списков равной длины
{
    Node* a = lhs.head;
    Node* b = rhs.head;
    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            return true;
        }
        a = a->next;
        b = b->next;
    }
    return false;
}
