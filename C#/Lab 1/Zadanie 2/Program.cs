using System;

namespace C_sharp__laba1_zadanie_2_
{
    class Program
    {
        static void Main(string[] args)
        {
            double pi = 3.14;
            Console.WriteLine("Введите X: ");
            double x = Convert.ToDouble(Console.ReadLine());
            double y = 1.3 * Math.Pow(Math.E, -x / 2)+Math.Abs(Math.Cos(((2*pi*x)/3)-1.4))-6/11;
            Console.WriteLine("При X= {0} ; Y= {1}", x, y);
        }
    }
}
