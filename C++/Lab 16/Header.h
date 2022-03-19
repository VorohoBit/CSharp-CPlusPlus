#pragma once
#include <iostream>
using namespace std;
template <typename T> //шаблон класса
//template-означает,что класс будет шаблонным
//typename-использование обобщенных типов данных
//T-название обобщеннного типа данных
//template <typename T>-означает,что используем неизвестный тип данных(сам тип данных узнаём в момент создания такого класса)
class massive
{
private:
	T* arr;
	int maxsize;
	int size;
public:
	massive()
	{
		this->arr = NULL;
		maxsize = 0;
		size = 0;
	}
	massive(const massive& temp)
	{
		size = temp.size;
		maxsize = temp.maxsize;
		arr = new T[this->maxsize];
		for (int i = 0; i < size; i++)
			arr[i] = temp.arr[i];
	}
	massive(int maxsize)
	{
		this->size = 0;
		this->maxsize = maxsize;
		this->arr = new T[this->maxsize];
	}
	~massive()
	{
		delete[] arr;
	}
	void input(int size)
	{
		if (size > maxsize)
		{
			return;
		}
		this->size = size;
		for (int i = 0; i < size; i++)
		{
			cout << "\nPrint element #" << i + 1 << ": "; cin >> arr[i];
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	void  operator= (const massive& obj)
		//massive &
	{
		/*if (this == &obj)
			return *this;*/
		delete[] this->arr;
		arr = new T[obj.size];
		size = obj.size;
		for (int i = 0; i < size; i++)
			arr[i] = obj.arr[i];

		//return *this;
	}
	template <class T>
	//friend massive<T> operator- (const massive<T>& obj);
	massive<T>  operator- (const massive<T>& obj)
	{
		/*if (size != obj.size)
		{
			cout << "Error! Sizes are not equal";
			cout << "Ending program..." << endl;
			exit(0);
		}
		else
		{*/
		for (int i = 0; i < size; i++)
			arr[i] -= obj.arr[i];
		return *this;
		//}
	}
	void o(int number)
	{
		for (int i = 0; i < size; i++)
			arr[i] -= number;
	}
	T & operator[] (int index)
	{
		return this->arr[index];
	}
};