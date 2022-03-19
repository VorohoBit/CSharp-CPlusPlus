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
	T* arr; //укзатель на стэк
	int size; //макс. кол-во элементов в стэке
	int top; //позиция текущего элемента в стэке
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
	void push(const T& val)   //ф-ция добавления элемента в стек
	{
		assert(top < size);
		arr[top++] = val;
	}
	T pop() //ф-ция удаления элемента из стека
	{
		assert(top > 0);
		arr[top--];
		return top;
	}
	const T& peek(int num) //ф-ция возвращает n-й элемент от вершины стека
	{
		assert(num <= top);
		return arr[top - num];
	}
	void print() //ф-ция вывода стека на экран
	{
		for (int i = top - 1; i >= 0; i--)
			cout << "|" << setw(4) << arr[i]  << endl;
	}
	Stack<T>& operator ++() //перегрузка оператора ++
	{
		for (int i = 0; i < size; i++) {
			arr[i]++;
			cout << arr[i] << " ";
		}
		return *this;
	}
	Stack<T>& operator --() //перегрузка оператора --
	{
		for (int i = 0; i < size; i++) {
			arr[i]--;
			cout << arr[i] << " ";
		}
		return *this;
	}
	Stack<T>& operator +(const Stack<T>& tmp) //перегрузка оператора +
	{
		for (int i = 0; i < size; i++)
			arr[i] += tmp.arr[i];
		return *this;
	}
	bool operator !() //перегрузка оператора !
	{
		int num=0;
		for (int i = 0; i < size; i++) if(arr[i] != 0)
		{
			num++;
		}
		cout << "Сработала перегрузка оператора !" << endl;
		return num==0;
	}
	bool operator ==(const Stack& tmp) //перегрузка оператора ==
	{
		for (int i = 0; i < size; i++)
			if (arr[i] != tmp.arr[i]) {
				return false;
			}
		cout << "Сработала перегрузка оператора ==" << endl;
		return true;
	}
	bool operator !=(const Stack& tmp) //перегрузка оператора !=
	{
		//cout << "Сработала перегрузка оператора !=" << endl;
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