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
    //void add_front(int data) //�-��� ���������� �������� � ������ ������
    //{
    //    node = new Node; // ������� ����� �������
    //    node->data = data; // �������� � ���� ��������
    //    node->next = head; // ���������� ������ �������� ��� ���������
    //    head = node; // ��������� ��������� ������� � ������
    //}
    void add_back(int data) 
    {
        node = new Node; // ������� ����� �������
        node->data = data; // �������� � ���� ��������
        node->next = NULL; // ���������� ������ �������� ��� NULL
        if (head == NULL) // ���� ������ �� ����� NULL
        {
            head = node; // ��������� ��������� ������� � �����
        }
        else
        {
            Node* curr = head; //������� ������� ����� ������
            while (curr->next != NULL) //���������� ������ �������� ������� �� ����� NULL
            {
                curr = curr->next; // ���������� ������ �������� ��� ���������
            }
            curr->next = node; // ��������� ������� ������� � �����
        }
    }
    void del(Node** node, int key) //�-��� �������� �������� �� ������
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
            cout << "��� ����� ���������,������� ����� �������" << endl;
        }
    }
    void find(int index) //������� ��������� �������� �� ��� ������� 
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
            cout << "������� � �������� �������� �� ����������!" << endl;
        }
    }
    void extract(int l, int r) //�-��� ��������� ����� ������ ����� ����� ��������� ��������� (������������)
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
            cout << "������� ��������� �� ����������!" << endl;
        }
    }
    void print() //�-��� ������ ������ �� �����
    {
        node = head;
        while (node != NULL)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
    List& operator+(const int& data)  //���������� ��������� ���������� �������� � ����� ������ +
    {
        add_back(data);
        return *this;
    }
    List& operator+=(const int& data) //���������� ��������� ���������� �������� � ������ ������ +
    {
        add_back(data);
        return *this;
    }
    List& operator-(const int& data) //���������� ��������� �������� ��������� �������� �� ������ +
    {
        del(&head, data);
        return *this;
    }
    List& operator[](const int& index) //���������� ��������� ��������� �������� ������ �� ��� ������� +
    {
        find(index);
        return *this;
    }
    List& operator()(int l, int r) //���������� ��������� ����� ������� ��� ������ ����� ������ +
    {
        extract(l, r);
        return *this;
    }
    List& operator=(List obj) //���������� ��������� ������������ +
    {
        swap(head, obj.head);
        return *this;
    }
    List& operator++() //���������� ��������� ���-����������
    {
        head = head->next;
        return *this;
    }
    List& operator++(int) //���������� ��������� ����-����������
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
bool operator==(List& lhs, List& rhs) //���������� �������� �������� ���� ������� �� ���������
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

bool operator!=(List& lhs, List& rhs) //���������� �������� �������� ���� ������� �� �����������
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

bool operator>(List& lhs, List& rhs) //���������� �������� ">" ��� ������� ������ �����
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

bool operator<(List& lhs, List& rhs) { //���������� �������� "<" ��� ������� ������ �����
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

bool operator>=(List& lhs, List& rhs) //���������� �������� ">=" ��� ������� ������ �����
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

bool operator<=(List& lhs, List& rhs)  //���������� �������� "<=" ��� ������� ������ �����
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
