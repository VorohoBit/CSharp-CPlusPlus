#include "database.h"
#include "ui.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Database db; // экземпляр базы данных
	bool done = false; // флаг окончания работы с программой
	while (!done) { // пока не окончена работа
		uiShowMenu(); // выводим меню
		char ch;
		std::cin >> ch; // считываем символ с клавиатуры
		std::cin.ignore(10, '\n'); // очищаем ввод
		switch (ch) {
		case '1': // если нажали 1
			uiAddNewElement(db); // добавим новый элемент
			break;
		case '2': // если нажали 2
			uiEditElement(db); // отредактируем элемент
			break;
		case '3': // если нажали 3
			uiDeleteElement(db); // удалим элемент
			break;
		case '4': // если нажали 4
			uiPrintTable(db); // отобразим таблицу
			break;
		case '5': // если нажали 5
			uiSearchElement(db); // поиск элемента
			break;
		case '6': // если нажали 6
			uiSortElement(db); // сортировка таблицы
			break;
		case '7': // если нажали 7
			uiLoadDatabase(db); // загрузка файла
			break;
		case '8': // если нажали 8
			uiSaveDatabase(db); // сохранение
			break;
		case '9': // если нажали 9
			done = true; // установим флаг
			break;
		}
	}
	return 0;
}