#include <iostream>
#include <cmath>
#include <clocale>
#include <string>
using namespace std;

double func1(float& x)
{
    if (x + sqrt(pow(x, 2) - 4) + 2 == 0) throw (string)"WARNING!Ошибка деления на ноль!";
    else return (sqrt(2 * sqrt(pow(x, 2) - 4) + 2 * x)) / (x + sqrt(pow(x, 2) - 4) + 2);
}
double func2(float& x)
{
    if (sqrt(x + 2) == 0) throw(char*)"WARNING!Ошибка деления на ноль!";
    else return 1 / (sqrt(x + 2));
}
int main()
{
    setlocale(LC_ALL, "Russian");
    float x;
    cout << "Введите x:"; cin >> x;
    try
    {
        cout << "Результат ф-ции #1:" << func1(x) << endl;
        cout << "Результат ф-ции #2:" << func2(x) << endl;
    }
    catch (string y)
    {
        cout << y << endl;
    }
    return 0;
}