using System;

namespace C_sharp__laba4_zadanie2_
{
    class Program
    {
        static void Main(string[] args)
        {
            int k = 0, n = 3; //где k-номер итерации,n-переменная для вычисления знаменателя
            double chisl, znam;
            double sum = 0,d = 1,x = 0.5; //s-сумма ряда,d-переменная для вычисления числителя,x-контрольное значение
            double a; //первый член ряда
            a = x;
            while (Math.Abs(a)>=0.001)
            {
                sum += a; //сумма ряда на текущей позиции
                chisl = x*x*x*d;
                znam = n;
                a = chisl / znam;
                d = x*x;
                n += 2;
                k++; //счетчик итераций
                Console.WriteLine($" № Итерации:{k}");
                Console.WriteLine($"a={a}");
                Console.WriteLine($"sum={sum}\n");
            }
            sum = 2 * sum;
            double y = Math.Log((1 + x) / (1 - x));
            Console.WriteLine('\t' + " Результаты:" + '\n' +'\n' + " Вычисленная сумма ряда S =" + sum + '\n' + " Кол-во членов ряда - " + k + '\n' + " Функция ln(1+x/1-x) =" + y + '\n');
        }
    }
}
