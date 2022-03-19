#pragma once
#include <iostream>
#include <iomanip>
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
	Matrix() 
	{
		this->arr = NULL;
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
		for (int i = 0; i < stroka; i++) arr[i] = new T[stolbec];
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] = rand() % 10;
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
			cout << setw(4) << "|" << endl << endl;
		}
	}
	Matrix& operator = (Matrix<T>& mat) 
	{
		stroka = mat.stroka;
		stolbec = mat.stolbec;
		arr = new T * [stroka];
		for (int i = 0; i < stroka; i++) arr[i] = new T[stolbec];
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i] = mat.arr[i];
		return *this;

	}
	Matrix operator + (Matrix<T>& mat) 
	{
		if (stroka != mat.stroka || stolbec != mat.stolbec)
		{
			cout << "Матрицы сложить невозможно!" << endl;
			return mat;
		}
		Matrix<int> mat1(stroka, stolbec);
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) mat1.arr[i][j] = arr[i][j] + mat.arr[i][j];
		return mat1;
	}
	Matrix operator += (Matrix<T>& mat) 
	{
		if (stroka != mat.stroka || stolbec != mat.stolbec) 
		{
			cout << "Матрицы сложить невозможно!" << endl;
			return mat;
		}
		for (int i = 0; i < stroka; i++) 
			for (int j = 0; j < stolbec; j++) arr[i][j] += mat.arr[i][j];
		return *this;
	}
	Matrix operator -= (Matrix<T>& mat) 
	{
		if (stroka != mat.stroka || stolbec != mat.stolbec)
		{
			cout << "Матрицы сложить невозможно!" << endl;
			return mat;
		}
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] -= mat.arr[i][j];
		return *this;
	}
	Matrix operator - (Matrix<T>& mat) 
	{
		if (stroka != mat.stroka || stolbec != mat.stolbec) 
		{
			cout << "Матрицы вычесть невозможно!" << endl;
			return mat;
		}
		Matrix<int> mat1(stroka, stolbec);
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) mat1.arr[i][j] = arr[i][j] - mat.arr[i][j];
		return mat1;
	}
	T& operator()(int stroka, int stolbec)
	{
		return arr[stroka][stolbec];
	}
	Matrix operator * (Matrix<T>& mat) 
	{
		Matrix<T> mat1(stroka, stolbec);
		T sum = 0;
		for (int x = 0; x < stroka; x++)
			for (int i = 0; i < stroka; i++) 
			{
				for (int j = 0; j < stolbec; j++) sum += (arr[x][j] * mat.arr[j][i]);
				mat1.arr[x][i] = sum;
				sum = 0;
			}
		return mat1;
	}
	Matrix& operator *= (Matrix<T>& mat) 
	{
		Matrix<T> mat1(stroka, stolbec);
		T sum = 0;
		for (int x = 0; x < stroka; x++)
			for (int i = 0; i < stroka; i++) 
			{
				for (int j = 0; j < stolbec; j++) sum += (arr[x][j] * mat.arr[j][i]);
				mat1.arr[x][i] = sum;
				sum = 0;
			}
		*this = mat1;
		return *this;
	}
	Matrix<T>& operator * (float num)
	{
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] *= num;
		return *this;
	}
	Matrix<T>& operator *= (float num) 
	{
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] *= num;
		return *this;
	}
	Matrix<T>& operator + (float num)
	{
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] += num;
		return *this;
	}
	Matrix<T>& operator += (float num)
	{
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] += num;
		return *this;
	}
	Matrix<T>& operator - (float num)
	{
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] -= num;
		return *this;
	}
	Matrix<T>& operator -= (float num)
	{
		for (int i = 0; i < stroka; i++)
			for (int j = 0; j < stolbec; j++) arr[i][j] -= num;
		return *this;
	}
	template<class T>
	friend ostream& operator << (ostream& out, Matrix&);
	template<class T>
	friend istream& operator >> (istream& in, Matrix&);
};
template<class T>
ostream& operator << (ostream& out, Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.stroka; i++) 
	{
		out << "|";
		for (int j = 0; j < matrix.stolbec; j++) out << setw(4) << matrix(i, j);
		out << setw(4) << "|" << endl << endl;
	}
	return out;
}
template<class T>
istream& operator>>(istream& in, Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.stroka; i++)
		for (int j = 0; j < matrix.stolbec; j++) in >> matrix(i, j);
	return in;
}