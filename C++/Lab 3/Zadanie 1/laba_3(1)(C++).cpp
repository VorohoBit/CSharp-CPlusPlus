#include <iostream>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int x, y, r;
    cout << "Vvedite R(int): "; cin >> r;
    for (int i = 0; i < 10; i++)
    {
        cout << "Vvedite X(int) " << i + 1 << ":"; cin >> x;
        cout << "Vvedite Y(int) " << i + 1 << ":"; cin >> y;
        if (abs(y) > r || abs(x) > r)
        {
            cout << "Так не получится,согласно уравнению окружности с центром в какой-либо точке x^2+y^2=R^2" << endl;
            return 0;
        }
        if (r < 1)
        {
            cout << "Радиус не может быть отрицательным или раным нулю" << endl;
            return 0;
        }
        if (y > abs(x))
        {
            cout << "Вы не попали в серую зону" << endl;
        }
        else if (abs(x) >= abs(y) && abs(x) <= r) cout << "Вы попали в серую зону" << endl;
        else cout << "Ты не попал";
    }
    return 0;
}
