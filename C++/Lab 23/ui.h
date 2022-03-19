#pragma once
#include "database.h"
void uiPrintTableHead(); //�-��� ������� ����� �������
void uiPrintTableRow(int n, Database& db); //�-��� ������� ������ �������
void uiPrintTable(Database& db); // �-��� ������� ��� �������
void uiAddNewElement(Database& db); //�-��� ���������� ����� ������
void uiDeleteElement(Database& db); //�-��� �������� ��������
void uiEditElement(Database& db); //�-��� �������������� ������
void uiSearchElement(Database& db); //�-��� ������ �������
void uiLoadDatabase(Database& db); //�-��� �������� ���� ������
void uiSaveDatabase(Database& db);//�-��� ���������� ���� ������
void uiSortElement(Database& db); //�-��� ����������
void uiShowMenu(); //�-��� ������ ����