#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int x1,x2,dx,y;
    cout << "Vvedite X1(int):"; cin >> x1;
    cout << "Vvedite X2(int):"; cin >> x2;
    cout << "Vvedite SHAG(int):"; cin >> dx;
    if (x2 < x1 || dx<0) cout << "Конечная точка всегда больше начальной и шаг не может быть отрицательынм" << endl;
    cout << "|-+-+-+-+-|"<<endl;
    for (int i = x1; i < x2; i += dx)
    {
        y = 2 - ((1-i-pow(i,2) / (pow(2*i+pow(i,2),1/2))));
        cout << "    Y=" << y << endl;
    }
    cout << "|+-+-+-+-+|"<<endl;
    return 0;
}
