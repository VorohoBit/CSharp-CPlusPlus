#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<locale.h>
using namespace std;
class human
{
protected:
	char fio[30];
	char data[15];
	char pol[10];
public:
	human();
	human(const char* fio, const char* data, const char* pol);
	~human();
	void SetFio(const char* fio);
	void SetData(const char* data);
	void SetPol(const char* pol);
	const char* getFio() const;
	const char* getData() const;
	const char* getPol() const;
	void input();
	void print();
};

class student : public human
{
private:
	char type[20];
	char speciality[20];
	int kurs;
public:
	student();
	student(const char* type, const char* speciality, int kurs);
	~student();
	void SetType(const char* type);
	void SetSpec(const char* speciality);
	void SetKurs(int kurs);
	const char* getType() const;
	const char* getSpec() const;
	int getKurs() const;
	void input1();
	void print1();
};

class professor : public human
{
private:
	char tema[20];
	int shifr;
};

human::human()
{
	this->SetFio("");
	this->SetData("");
	this->SetPol("");
}
human::human(const char* fio, const char* data, const char* pol)
{
	this->SetFio(fio);
	this->SetData(data);
	this->SetPol(pol);
}
student::student()
{

}
student::student(const char* type, const char* speciality, int kurs) :human(fio, data, pol)
{
	this->SetType(type);
	this->SetSpec(speciality);
	this->SetKurs(kurs);
}
student::~student()
{
}
human::~human()
{
}
void human::SetFio(const char* fio)
{
	strcpy(this->fio, fio);
}
void human::SetData(const char* data)
{
	strcpy(this->data, data);
}
void human::SetPol(const char* pol)
{
	strcpy(this->pol, pol);
}
const char* human::getFio() const
{
	return this->fio;
}
const char* human::getData() const
{
	return this->data;
}
const char* human::getPol() const
{
	return this->pol;
}
void human::input()
{
	cout << "Заполните данные:" << endl;
	cout << "ФИО:";
	char fio[30]; gets_s(fio); this->SetFio(fio);
	cout << "Дата:";
	char data[15]; gets_s(data); this->SetData(data);
	cout << "Пол:";
	char pol[10]; gets_s(pol); this->SetPol(pol);
}

void human::print()
{
	cout << endl;
	cout << "ФИО:" << this->getFio() << endl;
	cout << "Дата:" << this->getData() << endl;
	cout << "Пол:" << this->getPol() << endl;
}
void student::SetType(const char* type)
{
	strcpy(this->type, type);
}
void student::SetSpec(const char* speciality)
{
	strcpy(this->speciality, speciality);
}
void student::SetKurs(int kurs)
{
	this->kurs = kurs;
}
const char* student::getType() const
{
	return this->type;
}
const char* student::getSpec() const
{
	return this->speciality;
}
int student::getKurs() const
{
	return this->kurs;
}
void student::input1()
{
	cout << "Тип обучения(бюджет/платное):";
	char type[20]; gets_s(type); this->SetType(type);
	cout << "Специальность:";
	char speciality[20]; gets_s(type); this->SetSpec(speciality);
	cout << "Курс:";
	int kurs; cin >> kurs; this->SetKurs(kurs);
}

void student::print1()
{
	cout << endl;
	cout << "Тип обучения(бюджет/платное):" << this->getType() << endl;
	cout << "Специальность:" << this->getSpec() << endl;
	cout << "Курс:" << this->getKurs() << endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	human* human_1 = new human();
	human_1->input();
	human_1->print();
	human* human_2 = new human("Жмышенко Валерий Альбертович", "12.10.2003", "male");
	human_2->print();
	student* student1 = new student();
	student1->input();
	student1->input1();
	student1->print();
	student1->print1();
	delete human_1;
	delete human_2;
	delete student1;
	return 0;
}