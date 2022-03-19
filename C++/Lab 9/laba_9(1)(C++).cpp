#include <iostream>
#include <locale.h>
#include <cstdlib>
using namespace std;

void zapolnit(int* mas);
void pokaz(int* mas);
int calculator(int* mas);
int *poisk(int* mas1, int* mas2);
void sort(int* mas);

int main()
{
    setlocale(LC_ALL, "Russian");
    int m1[20], m2[20], m3[20];
    zapolnit(m1); cout << "Массив №1:"; pokaz(m1); 
    zapolnit(m2); cout << "Массив №2:"; pokaz(m2); 
    zapolnit(m3); cout << "Массив №3:"; pokaz(m3); 
    int *max = poisk(m1, m2); 
    max = poisk(max, m3);
    cout << "Массив с макс. кол-вом отрицательных элементов: "; pokaz(max); 
    sort(max); 
    cout << "Отсортированный в порядке убывания этот массив: "; pokaz(max); 
    return 0;

}

// функция заполнения массива случайными числами, принимает указатель на массив для заполнения
void zapolnit(int* mas)
{
    for (int i = 0; i < 20; i++)
        mas[i] = rand() % 21 - 10;
}

// функция выводит на экран содержимое массива
void pokaz(int* mas)
{
    cout << "{";
    for (int i = 0; i < 20; i++)
        cout << " " << mas[i];
    cout << "}" << endl;
}

int calculator(int* mas)
{
    int cnt=0;
    for (int i = 0; i < 20; i++)
        if (mas[i] < 0) cnt++;
    return cnt;
}

// функция возвращаем указатель на массив, в котором кол-во отрицательных элементов должно быть максимальным
int *poisk(int* mas1, int* mas2)
{
    int cnt1 = calculator(mas1), cnt2 = calculator(mas2); 
    if (cnt1 > cnt2) 
        return mas1; 
    else return mas2;
}


// функция сортировки массива методом пузырька
void sort(int* mas)
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            if (mas[i] > mas[j])
            {
                int temp = mas[j];
                mas[j] = mas[i];
                mas[i] = temp;
            }
        }
}