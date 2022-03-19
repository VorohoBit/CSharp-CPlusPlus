#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template<class T>
class Matrix;
template<class T>
class Vector 
{
private:
	T* arr;
public:
	int size;
	Vector() 
	{
		this->arr = NULL;
		size = 0;
	}
	/*~Vector() 
	{
	delete[] arr;
	}*/
	Vector(int size) 
	{
		this->size = size;
		arr = new T[size];
		for (int i = 0; i < size; i++) arr[i] = rand() % 10;
	}
	void print() 
	{
		for (int i = 0; i < size; i++) cout << "|" << setw(4) << arr[i] << setw(4) << "|" << endl << endl;
	}
	T& operator[](int num) 
	{
		return arr[num];
	}
	Vector<T>& operator = (const Vector<T>& tmp)
	{
		delete[] this->arr;
		arr = new T[tmp.size];
		size = tmp.size;
		for (int i = 0; i < size; i++) arr[i] = tmp.arr[i];
		return *this;
	}
	Vector<T> operator + (Vector<T>& tmp)
	{
		Vector<T> buff(3);
		for (int i = 0; i < size; i++) buff.arr[i] = arr[i] - tmp.arr[i];
		return buff;
	}
	Vector<T>& operator += (Vector<T>& tmp)
	{
		for (int i = 0; i < size; i++) arr[i] += tmp.arr[i];
		return *this;
	}
	Vector<T>& operator -= (Vector<T>& tmp)
	{
		for (int i = 0; i < size; i++) arr[i] -= tmp.arr[i];
		return *this;
	}
	Vector<T> operator * (Vector<T>& tmp)
	{
		Vector buff(3);
		for (int i = 0; i < size; i++) buff.arr[i] = arr[i] * tmp.arr[i];
		return buff;
	}
	Vector<T>& operator *= (Vector<T>& tmp)
	{
		for (int i = 0; i < size; i++) arr[i] *= tmp.arr[i];
		return *this;
	}
	Vector<T>& operator ++()
	{
		for (int i = 0; i < size; i++) arr[i]++;
		return *this;
	}
	Vector<T>& operator --()
	{
		for (int i = 0; i < size; i++) arr[i]--;
		return *this;
	}
	Vector<T> operator/(const Vector<T>& tmp)
	{
		Vector<T> buff(3);
		for (int i = 0; i < size; i++) buff.arr[i] = arr[i] / tmp.arr[i];
		return buff;
	}
	Vector<T>& operator/=(const Vector<T>& tmp)
	{
		for (int i = 0; i < size; i++) arr[i] /= tmp.arr[i];
		return *this;
	}
	Vector<T> operator -(const Vector<T>& tmp)
	{
		Vector<T> buff(3);
		for (int i = 0; i < size; i++) buff.arr[i] = arr[i] - tmp.arr[i];
		return buff;
	}
	template<class T>
	friend ostream& operator << (ostream& out, Vector&);
	template<class T>
	friend istream& operator >> (istream& in, Vector&);
	template<class T>
	friend Vector operator * (Matrix<T>& mat);
};

template<class T>
ostream& operator << (ostream& out, Vector<T>& vector)
{
	for (int i = 0; i < vector.size; i++) out << "|" << setw(4) << vector[i] << setw(4) << "|" << endl << endl;
	return out;
}
template<class T>
istream& operator >> (istream& in, Vector<T>& vector)
{
	for (int i = 0; i < vector.size; i++) in >> vector[i];
	return in;
}
template<class T>
Vector<T> operator * (Vector<T>& vec, Matrix<T>& mat)
{
	Vector<T> Res(3);
	for (int i = 0; i < mat.stroka; i++)
	{
		Res[i] = 0;
		for (int j = 0; j < mat.stolbec; j++) Res[i] += vec[j] * mat(i, j);
	}
	return Res;
}
template<class T>
Vector<T> operator *= (Vector<T>& vec, Matrix<T>& mat)
{
	for (int i = 0; i < mat.stroka; i++)
		for (int j = 0; j < mat.stolbec; j++) vec[j] *=mat(i, j);
	return vec;
}