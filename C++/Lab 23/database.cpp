#include "database.h"

DBelem::DBelem() :
	name("null"), // �������� �� ���������
	group("null"),
	date("00.00.0000")
{
	// ��������������������
	marks[0] = marks[1] = marks[2] = marks[3] = marks[4] = 0;
}
DBelem::DBelem(String Name, String Group, String Date,int m1, int m2, int m3, int m4, int m5) :
	name(Name), // ������������� ��������
	group(Group),
	date(Date)
{
	// ���������������
	marks[0] = m1;
	marks[1] = m2;
	marks[2] = m3;
	marks[3] = m4;
	marks[4] = m5;
}
void write_string(String str, std::ostream& s)
{
	// �������������������
	char size = str.length();
	// ���������� �����
	s.write(&size, 1);
	// ���������� ������
	s.write(str.c_str(), size);
}
std::ostream& operator << (std::ostream& s, DBelem& el)
{
	// ���������������� name
	write_string(el.name, s);
	// ... group
	write_string(el.group, s);
	// ... date
	write_string(el.date, s);
	// ���������������� marks
	s.write((char*)&el.marks[0], sizeof(el.marks));
	// ���������� �����, ��� ������������� ������
	return s;
}
void read_string(String& str, std::istream& s)
{
	char size;
	// ��������� ������ ������
	s.read(&size, 1);
	// ������� ������ ������
	char tmp[100];
	// ������������� "����� ������"
	tmp[size] = 0x00;
	// ��������� ������
	s.read(tmp, size);
	// ���������� � str ������ �� �������
	str = tmp;
}
std::istream& operator >> (std::istream& s, DBelem& el)
{
	// ������������� name
	read_string(el.name, s);
	// ... group
	read_string(el.group, s);
	// ... date
	read_string(el.date, s);
	// ��������������� marks
	s.read((char*)&el.marks[0], sizeof(el.marks));
	// ���������� �����, ��� �������������� ������
	return s;
}
void Database::add(DBelem& new_data)
{
	// ����������� ������ � ������
	data.push_back(new_data);
}
DBelem& Database::get(const unsigned num)
{
	// ���� ������ � ������� num �� ����������, �� ���������� ������ ������
	if (num >= data.size()) return NullDBelem;
	// ���������� ��������� �� ������
	return data.at(num);
}
void Database::del(const unsigned num)
{
	// ���� ������ � ������� num �� ����������, �� �������
	if (num >= data.size()) return;
	// �������� �������� �� ������������
	DBvector::iterator it = data.begin();
	// ��������� �������� �� ������ � ������� num
	for (unsigned i = 0; i < num; ++i, ++it);
	// ������� ������ �� ������� ��������� ��������
	data.erase(it);
}
int Database::size()
{
	// ���������� ������ �������
	return data.size();
}
void Database::save(String filename)
{
	// �����������������������
	std::ofstream outstr(filename.c_str());
	// �������� ������ ����
	int size = data.size();
	// ��������������������
	outstr.write((char*)&size, sizeof(int));
	// ������� �������� �� �������
	DBvector::iterator it;
	// ����������������
	for (it = data.begin(); it != data.end(); ++it)
		// ��������� ������ �� ���������
		outstr << (*it);
	// ��������� �����
	outstr.close();
}
void Database::load(String filename)
{
	// �������������������������
	std::ifstream instr(filename.c_str());
	// ������������������
	data.clear();
	int size;
	instr.read((char*)&size, sizeof(int));
	// ���� �������� ������
	while (--size >= 0)
	{
		DBelem temp;
		// ��������� ������
		instr >> temp;
		// ��������� ������
		data.push_back(temp);
	}
	// ��������� �����
	instr.close();
}
int MySortObject::field = -1;
int MySortObject::direction = -1;
bool MySortObject::operator() (DBelem A, DBelem B) const
{
	{
		switch (field)
		{
		case Database::FIELD_NAME:
			switch (direction)
			{
			case Database::DIR_FORWARD:
				return A.Name() < B.Name();
			case Database::DIR_BACKWARD:
				return A.Name() > B.Name();
			}
		case Database::FIELD_GROUP:
			switch (direction)
			{
			case Database::DIR_FORWARD:
				return A.Group() < B.Group();
			case Database::DIR_BACKWARD:
				return A.Group() > B.Group();
			}
		case Database::FIELD_MARKS:
		{
			int summ1 = std::accumulate(&A.Mark(0), &A.Mark(5), 0);
			int summ2 = std::accumulate(&B.Mark(0), &B.Mark(5), 0);
			switch (direction)
			{
			case Database::DIR_FORWARD: // ���� ������ ����������
				return summ1 < summ2;
			case Database::DIR_BACKWARD: // ���� �������� ����������
				return summ1 > summ2;
			}
		}
		case Database::FIELD_DATE:
		{
			int data1 = date2int(A.Date());
			int data2 = date2int(B.Date());
			switch (direction) // �������������������
			{
			case Database::DIR_FORWARD: // ��������������������
				return data1 < data2;
			case Database::DIR_BACKWARD: // ����������������������
				return data1 > data2;
			}
		}
		}
		return false;
	}
}
DBelem Database::NullDBelem = DBelem("null", "null", "00.00.0000", 0, 0, 0, 0, 0);
long MySortObject::date2int(String date) const
{
	// ������� atoi ��������� ������ � ����� �����
	// ����� substr ��� string �������� ���������
	// ����� c_str ���������� ��������� �� ������ �������� ������
	int d = atoi(date.substr(0, 2).c_str()); // ����������
	int m = atoi(date.substr(3, 2).c_str()); // �������� ��
	int y = atoi(date.substr(6, 4).c_str()); // �������� ����
	return (y * 12 + m) * 31 + d;// ��������� � �����
}
void Database::sort(int field, int direction)
{
	// ������������� ���� � ����������� ��� ��������������� �������
	MySortObject::field = field;
	MySortObject::direction = direction;
	// ��������������������������������������
	std::sort(data.begin(), data.end(), MySortObject());
}
