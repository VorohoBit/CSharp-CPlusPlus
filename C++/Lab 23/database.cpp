#include "database.h"

DBelem::DBelem() :
	name("null"), // значения по умолчанию
	group("null"),
	date("00.00.0000")
{
	// обнуляеммассивоценок
	marks[0] = marks[1] = marks[2] = marks[3] = marks[4] = 0;
}
DBelem::DBelem(String Name, String Group, String Date,int m1, int m2, int m3, int m4, int m5) :
	name(Name), // устанавливаем значения
	group(Group),
	date(Date)
{
	// заполняеммассив
	marks[0] = m1;
	marks[1] = m2;
	marks[2] = m3;
	marks[3] = m4;
	marks[4] = m5;
}
void write_string(String str, std::ostream& s)
{
	// получаемдлинустроки
	char size = str.length();
	// записываем длину
	s.write(&size, 1);
	// записываем строку
	s.write(str.c_str(), size);
}
std::ostream& operator << (std::ostream& s, DBelem& el)
{
	// записываемстроки name
	write_string(el.name, s);
	// ... group
	write_string(el.group, s);
	// ... date
	write_string(el.date, s);
	// записываеммассив marks
	s.write((char*)&el.marks[0], sizeof(el.marks));
	// возвращаем поток, для множественной записи
	return s;
}
void read_string(String& str, std::istream& s)
{
	char size;
	// считываем размер строки
	s.read(&size, 1);
	// создаем пустую строку
	char tmp[100];
	// устанавливаем "конец строки"
	tmp[size] = 0x00;
	// считываем строку
	s.read(tmp, size);
	// записываем в str данные из массива
	str = tmp;
}
std::istream& operator >> (std::istream& s, DBelem& el)
{
	// загрузкастрок name
	read_string(el.name, s);
	// ... group
	read_string(el.group, s);
	// ... date
	read_string(el.date, s);
	// считываеммассив marks
	s.read((char*)&el.marks[0], sizeof(el.marks));
	// возвращаем поток, для множественного чтения
	return s;
}
void Database::add(DBelem& new_data)
{
	// заталкиваем данные в вектор
	data.push_back(new_data);
}
DBelem& Database::get(const unsigned num)
{
	// если данных с номером num не существует, то возвращаем пустую запись
	if (num >= data.size()) return NullDBelem;
	// возвращаем указатель на запись
	return data.at(num);
}
void Database::del(const unsigned num)
{
	// если данных с номером num не существует, то выходим
	if (num >= data.size()) return;
	// получаем итератор на первуюзапись
	DBvector::iterator it = data.begin();
	// переводим итератор на запись с номером num
	for (unsigned i = 0; i < num; ++i, ++it);
	// удаляем запись на которую указывает итератор
	data.erase(it);
}
int Database::size()
{
	// возвращаем размер вектора
	return data.size();
}
void Database::save(String filename)
{
	// создаемпотомзаписивфайл
	std::ofstream outstr(filename.c_str());
	// получаем размер базы
	int size = data.size();
	// записываемразмербазы
	outstr.write((char*)&size, sizeof(int));
	// создаем итератор по записям
	DBvector::iterator it;
	// перебираемзаписи
	for (it = data.begin(); it != data.end(); ++it)
		// сохраняем запись по итератору
		outstr << (*it);
	// закрываем поток
	outstr.close();
}
void Database::load(String filename)
{
	// создаемпотокчтенияизфайла
	std::ifstream instr(filename.c_str());
	// очищаемтекущуюбазу
	data.clear();
	int size;
	instr.read((char*)&size, sizeof(int));
	// цикл загрузки данных
	while (--size >= 0)
	{
		DBelem temp;
		// считываем запись
		instr >> temp;
		// добавляем запись
		data.push_back(temp);
	}
	// закрываем поток
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
			case Database::DIR_FORWARD: // если прямая сортировка
				return summ1 < summ2;
			case Database::DIR_BACKWARD: // если обратная сортировка
				return summ1 > summ2;
			}
		}
		case Database::FIELD_DATE:
		{
			int data1 = date2int(A.Date());
			int data2 = date2int(B.Date());
			switch (direction) // выбираемнаправление
			{
			case Database::DIR_FORWARD: // еслипрямаясортировка
				return data1 < data2;
			case Database::DIR_BACKWARD: // еслиобратнаясортировка
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
	// функция atoi переводит строку в целое число
	// метод substr для string выделяет подстроку
	// метод c_str возвращаем указатель на массив символов строки
	int d = atoi(date.substr(0, 2).c_str()); // выделяемДД
	int m = atoi(date.substr(3, 2).c_str()); // выделяем ММ
	int y = atoi(date.substr(6, 4).c_str()); // выделяем ГГГГ
	return (y * 12 + m) * 31 + d;// переводим в число
}
void Database::sort(int field, int direction)
{
	// устанавливаем поле и направление для функционального объекта
	MySortObject::field = field;
	MySortObject::direction = direction;
	// сортируемиспользуяфункциональныйобъект
	std::sort(data.begin(), data.end(), MySortObject());
}
