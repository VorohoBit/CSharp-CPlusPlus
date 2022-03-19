#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    double x, y;
    cout << "Введите значение X: "; cin >> x;
    if (x > -6 && x <= -3) y = x + 3;
    else if (x <= 0 && x > -3) y = -(pow(x, 2) / 3) + 3;
    else if (x > 0 && x < 7) y = (-x / 2) + 3;
    else if (x > 6 && x <= 9) y = x - 6;
    cout << "Значение Y=" << y;
    return 0;
}