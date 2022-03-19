#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class massive
{
private:
	double* arr;
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
        arr = new double[this->maxsize];
		for (int i = 0; i < size; i++)
			arr[i] = temp.arr[i];
	}
	massive(int maxsize)
	{
		this->size = 0;
		this->maxsize = maxsize;
		this->arr = new double[this->maxsize];
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
		this->size=size;
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
		arr = new double[obj.size];
		size = obj.size;
		for (int i = 0; i < size; i++)
			arr[i] = obj.arr[i];

		//return *this;
	}
	friend massive operator- (const massive& obj);
	massive  operator- (const massive& obj)
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
	void poisk_po_indekcy(const massive &obj,int num) 
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == num) cout << "somehing:"<<obj.arr[i];
			//obj.arr[i] = num;
			
				//cout << endl << this->arr[num];
		}
	}
	void o(int number)
	{
		for (int i = 0; i < size; i++) 
		arr[i] -= number;
	}
	double& operator[] (int index)
	{
		return this->arr[index];
	}
};