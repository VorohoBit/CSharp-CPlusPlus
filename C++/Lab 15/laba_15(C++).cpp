#include <iostream>
#include <clocale>
#include <string>
#include <regex>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    while (true)
    {
        cout << "Make America Great Again | 1-zadanie_1 | 2-zadanie_2 | 3-zadanie_3 | 4_exit | 5_add_zadanie" << endl; cin >> n;
        if (n == 1) cout << "Вы выбрали задание номер 1!" << endl;
        else if (n == 2) cout << "Вы выбрали задание номер 2!" << endl;
        else if (n == 3) cout << "Вы выбрали задание номер 3!" << endl;
        else if (n == 4) cout << "Вы выбрали выход из программы!" << endl;
        switch (n)
        {
        case 1:
        {
            int x, k = 0;
            string str;
            cin.get();
            cout << "Введите строку:"; getline(cin, str);
            x = size(str);
            for (int i = 0; i < x; i++)
            {
                if ((str[i] > 96) && (str[i] < 123)) k++;
            }
            cout << "Кол-во строчных латинских букв:" << k << endl;
            break;
        }
        case 2:
        {
            string s;
            cin.get();
            cout << "Введите строку s:"; getline(cin, s);
            string s1;
            cout << "Введите строку s1:"; getline(cin, s1);
            string s2;
            cout << "Введите строку s2:"; getline(cin, s2);
            s = regex_replace(s, regex(s1), s2);
            cout << s << endl;
            break;
        }
        case 3:
        {
            string s;
            cin.get();
            cout << "Введите строку:"; getline(cin, s);
            string s1;
            cout << "Введите s1:"; getline(cin, s1);
            string s2;
            cout << "Введите s2:"; getline(cin, s2);
            s = regex_replace(s, regex(s1), s2);
            cout << "Полученная строка:" << s << endl;
            /*char str[50];
            cout << "Введите строку 1111:" << endl; gets_s(str);
            strcpy(str, s.c_str());
            char symbol[50];
            cout << "Введите строку 1111:" << endl; gets_s(symbol);
            strcpy(symbol, s.c_str());
            int x = 0;
            x = size(str);
            for (int i = 0; i < x; i++)
                if (str[i] > 47 && str[i] < 58) str[i] = *symbol;
            cout << "Полученная строка 1111:" << str << endl;*/
            /*string str;
            int x;
            cin.get();
                cout << "Введите строку:"; getline(cin, str);
                x = size(str);
                for (int i = 0; i < x; i++) 
                { 
                    if (i == 0 || str[i - 1] == ' ') str[i] = str[i] - 32;
                }
                cout << "Полученная строка:" << str << endl;*/
                break;
        }
        case 4:
        {
            return 0; break;
        }
        case 5:
        {
            int x = 0;
            int k = 0;
            string str;
            cin.get();
            cout << "Введите строку:"; getline(cin, str);
            x = size(str);
            cout << "Длина строки:" << x << endl;
            for (int i = 0; i < x; i++)
            {
                if ((str[i] > 47) && (str[i] < 58)) k++;
            }
            cout << "Кол-во цифр:" << k << endl;
        }
        default: cout << "Выберите другое значение!" << endl; break;
        }
    }
}
//в 3 заменить все цифры на тот символ который введет пользователь
// вывод длинны строки и количества цифр
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
