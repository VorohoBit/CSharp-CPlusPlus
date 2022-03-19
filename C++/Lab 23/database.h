#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>  //для работы с числовыми алгоритмами STL
#include <fstream>  //для работы с файловыми потоками
typedef std::string String;
struct DBelem
{
private:// сделаем эти свойства закрытыми
	String name; // ФИОстудента
	String group; // группа
	String date; // датапоступления (дд.мм.гггг)
	int marks[5]; // оценки за экзамены
public:
	String& Name() { return name; }
	// возвращает указатель на group
	String& Group() { return group; }
	// возвращаетуказательнаdate
	String& Date() { return date; }
	// возвращает указатель на элемент массива marks
	int& Mark(int index) { return marks[index]; }
	DBelem();
	DBelem(String Name, String Group, String Date,int m1, int m2, int m3, int m4, int m5);
	friend std::ostream& operator << (std::ostream& s, DBelem& el);
	friend std::istream& operator >> (std::istream& s, DBelem& el);
};

typedef std::vector<DBelem> DBvector;

class Database
{
private:
static DBelem NullDBelem; // статическое свойство "пустая запись"
DBvector data; // списокданных
public:
	// конструктор класса
	Database() {};
	void add(DBelem& new_data);
	DBelem& get(const unsigned num);
	void del(const unsigned num);
	int size();
	void save(String filename);
	void load(String filename);
	enum // перечисление для выбора поля для сортировки
	{
		FIELD_NAME, // имя
		FIELD_GROUP, // группа
		FIELD_DATE, // дата
		FIELD_MARKS // оценки
	};
	enum // перечисление для выбора направления сортировки
	{
		DIR_FORWARD, // прямое направление
		DIR_BACKWARD // обратное направление
	};
	void sort(int field, int direction);
};

class MySortObject
{
public:
	static int field; // номер поля для сортировки
	static int direction;
	bool operator() (DBelem A, DBelem B) const;
	long date2int(String date) const;
};