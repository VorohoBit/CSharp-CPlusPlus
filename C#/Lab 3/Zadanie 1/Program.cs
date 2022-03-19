using System;

namespace C_sharp__laba3_zadanie1_
{
    class Program
    {
        static void Main(string[] args)
        {
            double F;
            double min, max;
            Console.WriteLine("Введите знач. X:");
            double X = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите знач. Y:");
            double Y = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите знач. Z:");
            double Z = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Находим min(x,y+z)");
            if (X + Z < Y + Z) min = X + Z; else min = Y + Z;
            Console.WriteLine($"Min(x,y+z)={min}");
            Console.WriteLine("Находим max(x,y)");
            if (X > Y) max = X; else max = Y;
            Console.WriteLine($"Max(x,y)={max}");
            if(max+Math.Sin(Z)==0) Console.WriteLine("Знаменатель равен 0,а на ноль делить нельзя");
            else 
            {
                Console.WriteLine("Находим знач. выражение F");
                F = min / (max + Math.Sin(Z));
                Console.WriteLine($"F={F}");
            }
        }
    }
}
