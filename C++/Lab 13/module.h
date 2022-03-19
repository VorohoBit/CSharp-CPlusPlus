#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <locale.h>
using namespace std;
class human
{
protected:
	char fio[30];
	char data[15];
	char pol[10];
	int a;
	int b;
public:
	virtual void SetStorona1(int a, int b) {
		this->a = a;
		this->b = b;
		cout << endl << "Площадь:" << a * b;
	}
	virtual void SetFio(const char* family) { strcpy(fio, family); }
	//virtual void print() { cout << endl << "Plochad:" << a*b; }
	virtual void func() {}; //чистая виртуальная ф-ция
};

class student : public human
{
private:
	char type[20];
	char speciality[20];
	int kurs;
public:
	virtual void SetStorona1(int a, int b)
	{
		cout << endl << "Периметр:" << 2 * (a + b);
	} //переопределение базовой ф-ции
	student();
	~student();
	void func() override
	{
		cout << "Вызвана чистая виртуальная ф-ция для student" << endl;
	}
	void SetData(const char* data);
	void SetPol(const char* pol);
	void SetType(const char* type);
	void SetSpec(const char* speciality);
	void SetKurs(int kurs);
	const char* getFio() const;
	const char* getData() const;
	const char* getPol() const;
	const char* getType() const;
	const char* getSpec() const;
	int getKurs() const;
};

class professor : public human
{
private:
	char tema[20];
	int shifr;
public:
	void print() { cout << endl << "Class professor:" << fio; }
	professor();
	~professor();
	void func() override
	{

		cout << "Вызвана чистая виртуальня ф-ция для Professor " << endl;
	}
	void SetData(const char* data);
	void SetPol(const char* pol);
	void SetTema(const char* tema);
	void SetShifr(int shifr);
	const char* getFio() const;
	const char* getData() const;
	const char* getPol() const;
	const char* getTema() const;
	int getShifr() const;
};
