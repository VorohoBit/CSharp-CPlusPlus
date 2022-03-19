#include <iostream>
#include <locale.h>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    while (true)
    {
        cout << "Введите строку:"; getline(cin, str);
        for (int i = 0; i < str.size(); i++) //size() – возвращающает для строк кол-во символов
            if ( str[i - 1] == ' ' || (str[i]>64 && str[i]<80)) str[i] = str[i] - 32;
        cout << "Полученная строка:" << str << endl;
        if (size(str) == 0) return 0;
    }
    return 0;
}