
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	float a;
	cout << "Vvedite chislo a:"; cin >> a;
	float z = ((cos(a) + sin(a)) / (cos(a) - sin(a)));
	cout << z;
	return 0;
}