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
	cout << mat << endl << vec << endl;
	Matrix<float> mat1(3, 1);
	Vector<float> vec1(3);
	cout << "Умножение матрицы на вектор";
	vec1 = vec * mat;
	cout << endl << vec1;
	Matrix<float> mat2(3, 3);
	cout << "Умножение матрицы на число" << endl;
    mat2 = mat * 3;
	cout << endl << mat2;
	return 0;
}