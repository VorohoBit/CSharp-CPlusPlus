#include "ui.h"
#include "database.h"

void uiPrintTableHead() {
	std::cout << "+-------+--------------------------------+--------+"
		<< "------------+-----------+" << std::endl
		<< "| Номер | ФИО студента | Группа |"
		<< " Дата | Оценки |" << std::endl
		<< "+-------+--------------------------------+--------+"
		<< "------------+-----------+" << std::endl;
}
void uiPrintTableRow(int n, Database& db) {
	if (n < 0 || n >= db.size()) return;
	DBelem elem = db.get(n);
	// манипулятор setw устанавливаем выравнивание по ширине
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
	std::cout << "ДОБАВЛЕНИЕ НОВОГО ЭЛЕМЕНТА\n" << std::endl;
	std::cout << " ФИО студента: ";
	std::cin.getline(name, 31); // считываем строку длиной 30 символов
	std::cout << " Группа: ";
	std::cin.getline(group, 7);
	std::cout << " Дата поступления: ";
	std::cin.getline(date, 11);
	std::cout << " Оценки за экзамены: ";
	// считываем последовательность чисел
	std::cin >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
	// удаляем "конец строки" после ввода чисел
	std::cin.ignore(10, '\n');
	// создаем новую запись
	DBelem elem;
	elem.Name() = name;
	elem.Group() = group;
	elem.Date() = date;
	elem.Mark(0) = marks[0];
	elem.Mark(1) = marks[1];
	elem.Mark(2) = marks[2];
	elem.Mark(3) = marks[3];
	elem.Mark(4) = marks[4];
	// добавляем новую запись
	db.add(elem);
}
void uiDeleteElement(Database& db) {
	std::cout << "УДАЛЕНИЕ ЗАПИСИ\n" << std::endl;
	std::cout << "Отобразить базу (Д/Н) ?";
	char ch;
	std::cin >> ch; // считываем символ
	// очищаем буфер ввода
	std::cin.ignore(10, '\n');
	if (ch == 'д' || ch == 'Д') // если нажали "Д"
		uiPrintTable(db); // выводим всю таблицу
	std::cout << "Введите номер удаляемого элемента: ";
	int num;
	std::cin >> num; // считываем номер записи
	// очищаем буфер ввода
	std::cin.ignore(10, '\n');
	if (num > 0 && num <= db.size()) // если номер допустимый
		db.del(num - 1); // удаляем запись
}
void uiEditElement(Database& db) {
	std::cout << "РЕДАКТИРОВАНИЕ ЗАПИСИ\n" << std::endl;
	std::cout << "Отобразить базу (Д/Н) ?";
	char ch;
	std::cin >> ch;
	std::cin.ignore(10, '\n');
	if (ch == 'д' || ch == 'Д')
		uiPrintTable(db);
	std::cout << "Введите номер редактируемого элемента: ";
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
		std::cout << "Введите поле редактируемого элемента(1-ФИО,2-ГРУППА,3-ДАТА,4-ОЦЕНКИ):" << std::endl;
		std::cin>> N;
		switch (N)
		{
		case 1:
			std::cin.ignore();
			std::cout << " ФИО студента: " << elem.Name() << std::endl;
			std::cout << " ФИО студента: ";
			std::cin.getline(name, 31);
			db.get(num - 1).Name() = name;
			break;
		case 2:
			std::cin.ignore();
			std::cout << " Группа: " << elem.Group() << std::endl;
			std::cout << " Группа: ";;
			std::cin.getline(group, 7);
			db.get(num - 1).Group() = group;
			break;
		case 3:
			std::cin.ignore();
			std::cout << " Дата поступления: " << elem.Date() << std::endl;
			std::cout<< " Дата поступления : ";
			std::cin.getline(date, 11);
			db.get(num - 1).Date() = date;
			break;
		case 4:
			std::cin.ignore();
			std::cout << " Оценки за экзамены: "<< elem.Mark(0) << " "
				<< elem.Mark(1) << " " << elem.Mark(2) << " "
				<< elem.Mark(3) << " " << elem.Mark(4) << std::endl;
			std::cout<< " Оценки за экзамены: ";
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
	std::cout << "ПОИСК ЗАПИСЕЙ\n" << std::endl;
	char search[31];
	std::cout << "Введите текст для поиска: ";
	std::cin.getline(search, 31);
	bool found = false;
	// перебираем все записи
	for (int i = 0; i < db.size(); i++) {
		DBelem e = db.get(i);
		bool current = false;
		// ищем подстроку в записи
		if (strstr(e.Name().c_str(), search) != NULL) current = true;
		if (strstr(e.Group().c_str(), search) != NULL) current = true;
		if (strstr(e.Date().c_str(), search) != NULL) current = true;
		// если подстрока найдена
		if (current) {
			if (!found) {
				uiPrintTableHead(); // выводим шапку
				found = true;
			}
			uiPrintTableRow(i, db); // выводим найденную строку
		}
	}
	if (!found)
		std::cout << "Записи не найдены" << std::endl;
}
void uiLoadDatabase(Database& db) {
	std::cout << "ЗАГРУЗКА БАЗЫ ДАННЫХ\n" << std::endl;
	std::cout << "Введите имя файла: ";
	char filename[30];
	std::cin.getline(filename, 30);
	db.load(filename);
}
void uiSaveDatabase(Database& db) {
	std::cout << "СОХРАНЕНИЕ БАЗЫ ДАННЫХ\n" << std::endl;
	std::cout << "Введите имя файла: ";
	char filename[30];
	std::cin.getline(filename, 30);
	db.save(filename);
}
void uiSortElement(Database& db) {
	int field, direct;
	std::cout << "СОРТИРОВКА ЗАПИСЕЙ\n" << std::endl;
	std::cout << "Укажите поле для сортировки:\n" << std::endl;
	std::cout << " 1. ФИО студента\n"
		<< " 2. Группа\n"
		<< " 3. Дата поступления\n"
		<< " 4. Оценки за экзкмены\n"
		<< "?";
	std::cin >> field;
	std::cin.ignore(10, '\n');
	field--;
	std::cout << "Укажите направлениеы сортировки:\n" << std::endl;
	std::cout << " 1. По возрастанию\n"
		<< " 2. По убыванию\n"
		<< "?";
	std::cin >> direct;
	std::cin.ignore(10, '\n');
	direct--;
	if ((field >= 0 && field < db.size()) &&
		(direct >= 0 && direct <= 1))
		db.sort(field, direct);
}
void uiShowMenu() {
	std::cout << " МЕНЮ\n\n"
		<< " 1. Добавить элемент\n"
		<< " 2. Редактировать элемент\n"
		<< " 3. Удалить элемент\n"
		<< " 4. Просмотреть все записи\n"
		<< " 5. Поиск записей\n"
		<< " 6. Сортировать записи\n"
		<< " 7. Загрузить базу данных\n"
		<< " 8. Сохранить базу данных\n"
		<< " 9. Выход\n"
		<< "Выберите действие: ";
}