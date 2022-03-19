#pragma once
#include <iostream>
using namespace std;
template<class T>
class Vector;
template<class T>
class Matrix
{
private:
	T** arr;
public:
	int stroka;
	int stolbec;
	Matrix() {
		arr = NULL;
		stroka = 0;
		stolbec = 0;
	}
	~Matrix() 
	{
		delete[] * arr;
	}
	Matrix(int stroka) 
	{
		this->stroka = stroka;
		stolbec = 1;
		arr = new T * [stroka];
		for (int i = 0; i < stroka; i++)
			arr[i] = new T[stolbec];
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++)
				arr[i][j] = rand() % 10;
	}
	Matrix(int stroka, int stolbec)
	{
		this->stroka = stroka;
		this->stolbec = stolbec;
		arr = new T * [stroka];
		for (int i = 0; i < stroka; i++)
			arr[i] = new T[stolbec];
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++)
				arr[i][j] = rand() % 10;
	}
	void print()
	{
		for (int i = 0; i < stroka; i++) 
		{
			cout << "|";
			for (int j = 0; j < stolbec; j++)
				cout << setw(4) << arr[i][j];
			cout << setw(4) << "|" << endl;
			cout << endl;
		}
	}
	T& operator()(int stroka, int stolbec)
	{
		return arr[stroka][stolbec];
	}
	Matrix operator * (Matrix<T>& tmp) 
	{
		Matrix<T> tmp_1(stroka, stolbec);
		T sum = 0;
		for (int x = 0; x < stroka; x++)
			for (int i = 0; i < stroka; i++)
			{
				for (int j = 0; j < stolbec; j++)
					sum += (arr[x][j] * tmp.arr[j][i]); //строка умножается на 1-ый столбец,потом на 2-ой и т.д.(цикл повторяется)
				tmp_1.arr[x][i] = sum; //записываем это значение
				sum = 0;
			}
		return tmp_1;
	}
	template<class T>
	friend ostream& operator << (ostream& out, Matrix& tmp);
};
template<class T>
ostream& operator << (ostream& out, Matrix<T>& tmp)
{
	for (int i = 0; i < tmp.stroka; i++) {
		out << "|";
		for (int j = 0; j < tmp.stolbec; j++)
			out << setw(4) << tmp(i, j);
		out << setw(4) << "|" << endl << endl;
	}
	return out;
}