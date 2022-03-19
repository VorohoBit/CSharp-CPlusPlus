#include <iostream>
using namespace std;

int main()
{
    float x, y;
    cout << "Vvedite x:"; cin >> x;
    cout << "Vvedite y:"; cin >> y;
    if (x < 1 || x>4 || y < 2 || y>4)cout << "Ti He PoPal";
    else if (y < 2 || y>4)cout << "Ti He PoPal";
    else cout << "Ti PoPal";
    return 0;
}

