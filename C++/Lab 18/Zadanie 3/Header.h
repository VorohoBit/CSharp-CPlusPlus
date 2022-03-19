#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;
template <typename T>
class Stack
{
private:
	T* arr; //�������� �� ����
	int size; //����. ���-�� ��������� � �����
	int top; //������� �������� �������� � �����
public:
	template <typename T>
	friend ostream& operator<< (ostream& out,Stack<T>&);
	template <typename T>
	friend istream& operator>> (istream& in, Stack<T>&);
	Stack(int maxsize)
	{
		size = maxsize;
		arr = new T[size];
		top = 0;
	}
	Stack(const Stack<T>& tmp)
	{
		size = tmp.size;
		arr = new T[size];
		top = tmp.top;
		for (int i = 0; i < size; i++) arr[i] = tmp.arr[i];
	}
	~Stack() { delete[] arr; }
	void push(const T& val)   //�-��� ���������� �������� � ����
	{
		assert(top < size);
		arr[top++] = val;
	}
	T pop() //�-��� �������� �������� �� �����
	{
		assert(top > 0);
		arr[top--];
		return top;
	}
	const T& peek(int num) //�-��� ���������� n-� ������� �� ������� �����
	{
		assert(num <= top);
		return arr[top - num];
	}
	void print() //�-��� ������ ����� �� �����
	{
		for (int i = top - 1; i >= 0; i--)
			cout << "|" << setw(4) << arr[i]  << endl;
	}
	Stack<T>& operator ++() //���������� ��������� ++
	{
		for (int i = 0; i < size; i++) {
			arr[i]++;
			cout << arr[i] << " ";
		}
		return *this;
	}
	Stack<T>& operator --() //���������� ��������� --
	{
		for (int i = 0; i < size; i++) {
			arr[i]--;
			cout << arr[i] << " ";
		}
		return *this;
	}
	Stack<T>& operator +(const Stack<T>& tmp) //���������� ��������� +
	{
		for (int i = 0; i < size; i++)
			arr[i] += tmp.arr[i];
		return *this;
	}
	bool operator !() //���������� ��������� !
	{
		int num=0;
		for (int i = 0; i < size; i++) if(arr[i] != 0)
		{
			num++;
		}
		cout << "��������� ���������� ��������� !" << endl;
		return num==0;
	}
	bool operator ==(const Stack& tmp) //���������� ��������� ==
	{
		for (int i = 0; i < size; i++)
			if (arr[i] != tmp.arr[i]) {
				return false;
			}
		cout << "��������� ���������� ��������� ==" << endl;
		return true;
	}
	bool operator !=(const Stack& tmp) //���������� ��������� !=
	{
		//cout << "��������� ���������� ��������� !=" << endl;
		for (int i = 0; i < size; i++)
			if (arr[i] == tmp.arr[i])
			{
				return false;
			}
		 else return true;
	}
	bool operator >(const Stack& tmp)
	{
		bool num = true;
		for (int i = 0; i < size; i++)
			if (arr[i] < tmp.arr[i]) num = false;
		return num;
	}
	bool operator <(const Stack& tmp)
	{
		bool num = true;
		for (int i = 0; i < size; i++)
			if (arr[i] > tmp.arr[i])  num = false;
		return num;
	}
	bool operator <=(const Stack& tmp)
	{
		bool num = true;
		for (int i = 0; i < size; i++)
			if (arr[i] >= tmp.arr[i])  num = false;
		return num;
	}
	bool operator >=(const Stack& tmp)
	{
		bool num = true;
		for (int i = 0; i < size; i++)
			if (arr[i] <= tmp.arr[i]) num = false;
		return num;
	}
};
template<typename T>
ostream& operator<< (ostream& out,Stack<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
		out << tmp.arr[i] << " ";
	return out;
}
template<typename T>
istream& operator>> (istream& in, Stack<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
		in >> tmp.arr[i];
	return in; 
}