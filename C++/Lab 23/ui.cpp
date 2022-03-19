#include "ui.h"
#include "database.h"

void uiPrintTableHead() {
	std::cout << "+-------+--------------------------------+--------+"
		<< "------------+-----------+" << std::endl
		<< "| ����� | ��� �������� | ������ |"
		<< " ���� | ������ |" << std::endl
		<< "+-------+--------------------------------+--------+"
		<< "------------+-----------+" << std::endl;
}
void uiPrintTableRow(int n, Database& db) {
	if (n < 0 || n >= db.size()) return;
	DBelem elem = db.get(n);
	// ����������� setw ������������� ������������ �� ������
	std::cout << "| " << std::setw(5) << (n + 1)
		<< " | " << std::setw(30) << elem.Name()
		<< " | " << std::setw(6) << elem.Group()
		<< " | " << std::setw(10) << elem.Date()
		<< " | " << elem.Mark(0) << " " << elem.Mark(1) << " "
		<< elem.Mark(2) << " " << elem.Mark(3) << " " << elem.Mark(4)
		<< " |" << std::endl;
}
void uiPrintTable(Database& db) {
	uiPrintTableHead();
	for (int i = 0; i < db.size(); i++)
		uiPrintTableRow(i, db);
}
void uiAddNewElement(Database& db) {
	char name[31];
	char group[7];
	char date[11];
	int marks[5];
	std::cout << "���������� ������ ��������\n" << std::endl;
	std::cout << " ��� ��������: ";
	std::cin.getline(name, 31); // ��������� ������ ������ 30 ��������
	std::cout << " ������: ";
	std::cin.getline(group, 7);
	std::cout << " ���� �����������: ";
	std::cin.getline(date, 11);
	std::cout << " ������ �� ��������: ";
	// ��������� ������������������ �����
	std::cin >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
	// ������� "����� ������" ����� ����� �����
	std::cin.ignore(10, '\n');
	// ������� ����� ������
	DBelem elem;
	elem.Name() = name;
	elem.Group() = group;
	elem.Date() = date;
	elem.Mark(0) = marks[0];
	elem.Mark(1) = marks[1];
	elem.Mark(2) = marks[2];
	elem.Mark(3) = marks[3];
	elem.Mark(4) = marks[4];
	// ��������� ����� ������
	db.add(elem);
}
void uiDeleteElement(Database& db) {
	std::cout << "�������� ������\n" << std::endl;
	std::cout << "���������� ���� (�/�) ?";
	char ch;
	std::cin >> ch; // ��������� ������
	// ������� ����� �����
	std::cin.ignore(10, '\n');
	if (ch == '�' || ch == '�') // ���� ������ "�"
		uiPrintTable(db); // ������� ��� �������
	std::cout << "������� ����� ���������� ��������: ";
	int num;
	std::cin >> num; // ��������� ����� ������
	// ������� ����� �����
	std::cin.ignore(10, '\n');
	if (num > 0 && num <= db.size()) // ���� ����� ����������
		db.del(num - 1); // ������� ������
}
void uiEditElement(Database& db) {
	std::cout << "�������������� ������\n" << std::endl;
	std::cout << "���������� ���� (�/�) ?";
	char ch;
	std::cin >> ch;
	std::cin.ignore(10, '\n');
	if (ch == '�' || ch == '�')
		uiPrintTable(db);
	std::cout << "������� ����� �������������� ��������: ";
	int num;
	std::cin >> num;
	std::cin.ignore(10, '\n');
	if (num > 0 && num <= db.size())
	{
		DBelem elem = db.get(num - 1);
		char name[31];
		char group[7];
		char date[11];
		int marks[5];
		int N;
		std::cout << "������� ���� �������������� ��������(1-���,2-������,3-����,4-������):" << std::endl;
		std::cin>> N;
		switch (N)
		{
		case 1:
			std::cin.ignore();
			std::cout << " ��� ��������: " << elem.Name() << std::endl;
			std::cout << " ��� ��������: ";
			std::cin.getline(name, 31);
			db.get(num - 1).Name() = name;
			break;
		case 2:
			std::cin.ignore();
			std::cout << " ������: " << elem.Group() << std::endl;
			std::cout << " ������: ";;
			std::cin.getline(group, 7);
			db.get(num - 1).Group() = group;
			break;
		case 3:
			std::cin.ignore();
			std::cout << " ���� �����������: " << elem.Date() << std::endl;
			std::cout<< " ���� ����������� : ";
			std::cin.getline(date, 11);
			db.get(num - 1).Date() = date;
			break;
		case 4:
			std::cin.ignore();
			std::cout << " ������ �� ��������: "<< elem.Mark(0) << " "
				<< elem.Mark(1) << " " << elem.Mark(2) << " "
				<< elem.Mark(3) << " " << elem.Mark(4) << std::endl;
			std::cout<< " ������ �� ��������: ";
			std::cin>> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
			std::cin.ignore(10, '\n');
			db.get(num - 1).Mark(0) = marks[0];
			db.get(num - 1).Mark(1) = marks[1];
			db.get(num - 1).Mark(2) = marks[2];
			db.get(num - 1).Mark(3) = marks[3];
			db.get(num - 1).Mark(4) = marks[4];
			break;
		}
	}
}
void uiSearchElement(Database& db) {
	std::cout << "����� �������\n" << std::endl;
	char search[31];
	std::cout << "������� ����� ��� ������: ";
	std::cin.getline(search, 31);
	bool found = false;
	// ���������� ��� ������
	for (int i = 0; i < db.size(); i++) {
		DBelem e = db.get(i);
		bool current = false;
		// ���� ��������� � ������
		if (strstr(e.Name().c_str(), search) != NULL) current = true;
		if (strstr(e.Group().c_str(), search) != NULL) current = true;
		if (strstr(e.Date().c_str(), search) != NULL) current = true;
		// ���� ��������� �������
		if (current) {
			if (!found) {
				uiPrintTableHead(); // ������� �����
				found = true;
			}
			uiPrintTableRow(i, db); // ������� ��������� ������
		}
	}
	if (!found)
		std::cout << "������ �� �������" << std::endl;
}
void uiLoadDatabase(Database& db) {
	std::cout << "�������� ���� ������\n" << std::endl;
	std::cout << "������� ��� �����: ";
	char filename[30];
	std::cin.getline(filename, 30);
	db.load(filename);
}
void uiSaveDatabase(Database& db) {
	std::cout << "���������� ���� ������\n" << std::endl;
	std::cout << "������� ��� �����: ";
	char filename[30];
	std::cin.getline(filename, 30);
	db.save(filename);
}
void uiSortElement(Database& db) {
	int field, direct;
	std::cout << "���������� �������\n" << std::endl;
	std::cout << "������� ���� ��� ����������:\n" << std::endl;
	std::cout << " 1. ��� ��������\n"
		<< " 2. ������\n"
		<< " 3. ���� �����������\n"
		<< " 4. ������ �� ��������\n"
		<< "?";
	std::cin >> field;
	std::cin.ignore(10, '\n');
	field--;
	std::cout << "������� ������������ ����������:\n" << std::endl;
	std::cout << " 1. �� �����������\n"
		<< " 2. �� ��������\n"
		<< "?";
	std::cin >> direct;
	std::cin.ignore(10, '\n');
	direct--;
	if ((field >= 0 && field < db.size()) &&
		(direct >= 0 && direct <= 1))
		db.sort(field, direct);
}
void uiShowMenu() {
	std::cout << " ����\n\n"
		<< " 1. �������� �������\n"
		<< " 2. ������������� �������\n"
		<< " 3. ������� �������\n"
		<< " 4. ����������� ��� ������\n"
		<< " 5. ����� �������\n"
		<< " 6. ����������� ������\n"
		<< " 7. ��������� ���� ������\n"
		<< " 8. ��������� ���� ������\n"
		<< " 9. �����\n"
		<< "�������� ��������: ";
}