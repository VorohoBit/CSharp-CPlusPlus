using System;

namespace C_sharp__laba4_zadanie1_
{
    class Program
    {
        static void Main(string[] args)
        {
            double a = 0.5;
            while (a <= 1.25)
            {
                Console.WriteLine($"Знач. a= {a}");
                for (double x = 1; x <= 7; x += 0.25)
                {
                    double y = (Math.Pow((a + 1) * x, 1 / 4) + Math.Exp(-Math.Pow(x, 3))) / Math.Sqrt(2 * a * x);
                    Console.WriteLine("При X={0:0.00} Y= {0:0.0000}",x, y);
                }
                Console.WriteLine("\n");
                a += 0.25;
            }
        }
    }
}
