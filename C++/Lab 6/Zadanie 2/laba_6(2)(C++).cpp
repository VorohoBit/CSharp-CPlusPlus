#include <iostream>
#include <locale.h>
#include <string>
#include <regex> //для использования regex_replace
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s; //строковый тип данных
    cout << "Введите строку s:"; getline(cin, s); //aaaaaa для ввода данных из потока  cat rat cat
    string s1;
    cout << "Введите строку s1:"; getline(cin, s1); //aa   cat
    string s2;
    cout << "Введите строку s2:"; getline(cin, s2); //aaaa  bat
    s = regex_replace(s, regex(s1), s2);
    /*Заменяет фрагмент строки на несколько равных символов, другую строку или фрагмент другой строки.
    Из данной строки удаляется count символов, начиная с символа pos, и на их место вставляются новые символы.
    S.replace(pos, count, T) - вставить содержимое строки T. T может быть объектом класса string или C-строкой.
    */
    cout << s << endl; //aaaaaaaaaaaa
    return 0;
}
