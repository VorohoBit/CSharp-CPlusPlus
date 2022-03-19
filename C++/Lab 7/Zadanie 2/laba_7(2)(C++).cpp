#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

void resh1(string str);
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    bool l = true;
    while (l)
    {
        cout << "Введите строку:"; 
        getline(cin, str);
        resh1(str);
        if (str.empty() == true)
        {
            l = false;
        }
    }
    return 0;
}
void resh1(string str)
{
    for (int i = 0; i < str.size(); i++) //size() – возвращающает для строк кол-во символов
        if ((i == 0 || str[i - 1] == ' ')) str[i] = str[i] - 32;
        cout << "Полученная строка:" << str << endl;
}


