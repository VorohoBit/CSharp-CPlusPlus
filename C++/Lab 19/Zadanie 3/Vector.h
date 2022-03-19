#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
template<class T>
class Matrix;
template<class T>
class Vector {
private:
	T* arr;
public:
	int size;
	Vector() 
	{
		this->arr = NULL;
		size = 0;
	}
	//~Vector() 
	//{
	//  delete[] arr;
	//}
	Vector(int size) 
	{
		this->size = size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 10;
	}
	void print() 
	{
		for (int i = 0; i < size; i++) 
		{
			cout << "|";
			cout << setw(4) << arr[i] << setw(4) << "|" << endl;
			cout << endl;
		}
	}
	T& operator[](int index)
	{
		return arr[index];
	}
	template<class T>
	friend ostream& operator << (ostream& out, Vector& tmp);
	template<class T>
	friend Vector operator* (Matrix<T>& tmp);
};

template<class T>
ostream& operator << (ostream& out, Vector<T>& tmp)
{
	for (int i = 0; i < tmp.size; i++)
	{
		out << "|" << setw(4) << tmp[i] << setw(4) << "|" << endl << endl;
	}
	return out;
}
template<class T>
Vector<T> operator * (Vector<T>& vec, Matrix<T>& tmp)
{
	Vector<T> buff(3);
	for (int i = 0; i < tmp.stroka; i++)
	{
		buff[i] = 0;
		for (int j = 0; j < tmp.stolbec; j++)
		{
			buff[i] += vec[j] * tmp(i, j);
		}
	}
	return buff;
}