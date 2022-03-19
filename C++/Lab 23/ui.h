#pragma once
#include "database.h"
void uiPrintTableHead(); //ф-ция выводит шапку таблицы
void uiPrintTableRow(int n, Database& db); //ф-ция выводит строку таблицы
void uiPrintTable(Database& db); // ф-ция выводит всю таблицу
void uiAddNewElement(Database& db); //ф-ция добавления новой записи
void uiDeleteElement(Database& db); //ф-ция удаления элемента
void uiEditElement(Database& db); //ф-ция редактирования записи
void uiSearchElement(Database& db); //ф-ция поиска записей
void uiLoadDatabase(Database& db); //ф-ция загрузки базы данных
void uiSaveDatabase(Database& db);//ф-ция сохранения базы данных
void uiSortElement(Database& db); //ф-ция сортировки
void uiShowMenu(); //ф-ция вывода меню