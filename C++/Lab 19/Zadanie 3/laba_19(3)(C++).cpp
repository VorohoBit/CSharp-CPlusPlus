#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	Matrix<float> mat(3, 3);
	Vector<float> vec(3);
	cout << "Наша матрица:" << endl << mat << endl << "Наш вектор:" << endl << vec << endl;
	Matrix<float> mat1(3, 1);
	Vector<float> vec1(3);
	cout << "Перемножение матрицы на вектор!" << endl;
	vec1 = vec * mat;
	cout << endl;
	cout << vec1;
	return 0;
}