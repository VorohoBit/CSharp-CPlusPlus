using System;

namespace С_sharp__laba3_zadanie2_
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = 0;
            Console.WriteLine("Введите знач. X для Т.M:");
            double X = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите знач. Y для Т.M:");
            double Y = Convert.ToDouble(Console.ReadLine());
            if ((X < 0 && Y < 0) || (X >= 0 && Y >= 0)) 
            {
                N = 3;
            }
            if ((X < 0 && Y > 0) || (X >= 0 && Y <= 0))
            {
                N = 4;
            }
            if (X >=0 && Y < 1 - X*X)
            {
                N = 2;
            }
            if (X < 0 && Y < 1 - X * X)
            {
                N = 1;
            }
            Console.WriteLine($"Т.M c координатами {(X,Y)} лежит в области N={N}");
        }
    }
}
