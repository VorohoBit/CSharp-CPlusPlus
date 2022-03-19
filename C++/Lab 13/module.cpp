#include "module.h"
#define _CRT_SECURE_NO_WARNINGS
student::student()
{
}
professor::professor()
{
}
student::~student()
{
}
professor::~professor()
{
}

//методы класса для студента
//2)
void student::SetData(const char* data)
{
	strcpy(this->data, data);
}
//3)
void student::SetPol(const char* pol)
{
	strcpy(this->pol, pol);
}
//4)
void student::SetType(const char* type)
{
	strcpy(this->type, type);
}
//5)
void student::SetSpec(const char* speciality)
{
	strcpy(this->speciality, speciality);
}
//6)
void student::SetKurs(int kurs)
{
	this->kurs = kurs;
}
//7)
const char* student::getFio() const
{
	return this->fio;
}
//8)
const char* student::getData() const
{
	return this->data;
}
//9)
const char* student::getPol() const
{
	return this->pol;
}
//10)
const char* student::getType() const
{
	return this->type;
}
//11)
const char* student::getSpec() const
{
	return this->speciality;
}
//12)
int student::getKurs() const
{
	return this->kurs;
}

//методы класса для профессора
//2)
void professor::SetData(const char* data)
{
	strcpy(this->data, data);
}
//3)
void professor::SetPol(const char* pol)
{
	strcpy(this->pol, pol);
}
//4)
void professor::SetTema(const char* tema)
{
	strcpy(this->tema, tema);
}
//5)
void professor::SetShifr(int shifr)
{
	this->shifr = shifr;
}
//6)
const char* professor::getFio() const
{
	return this->fio;
}
//7)
const char* professor::getData() const
{
	return this->data;
}
//8)
const char* professor::getPol() const
{
	return this->pol;
}
//9)
const char* professor::getTema() const
{
	return this->tema;
}
//10)
int professor::getShifr() const
{
	return this->shifr;
}