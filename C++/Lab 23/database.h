#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>  //��� ������ � ��������� ����������� STL
#include <fstream>  //��� ������ � ��������� ��������
typedef std::string String;
struct DBelem
{
private:// ������� ��� �������� ���������
	String name; // �����������
	String group; // ������
	String date; // ��������������� (��.��.����)
	int marks[5]; // ������ �� ��������
public:
	String& Name() { return name; }
	// ���������� ��������� �� group
	String& Group() { return group; }
	// ���������������������date
	String& Date() { return date; }
	// ���������� ��������� �� ������� ������� marks
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
static DBelem NullDBelem; // ����������� �������� "������ ������"
DBvector data; // ������������
public:
	// ����������� ������
	Database() {};
	void add(DBelem& new_data);
	DBelem& get(const unsigned num);
	void del(const unsigned num);
	int size();
	void save(String filename);
	void load(String filename);
	enum // ������������ ��� ������ ���� ��� ����������
	{
		FIELD_NAME, // ���
		FIELD_GROUP, // ������
		FIELD_DATE, // ����
		FIELD_MARKS // ������
	};
	enum // ������������ ��� ������ ����������� ����������
	{
		DIR_FORWARD, // ������ �����������
		DIR_BACKWARD // �������� �����������
	};
	void sort(int field, int direction);
};

class MySortObject
{
public:
	static int field; // ����� ���� ��� ����������
	static int direction;
	bool operator() (DBelem A, DBelem B) const;
	long date2int(String date) const;
};