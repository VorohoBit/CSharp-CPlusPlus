using System;

namespace C_sharp__laba5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите кол-во элементов массива:");
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите нижний диапазон:");
            int m = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите верхний диапазон:");
            int l = Convert.ToInt32(Console.ReadLine());
            double sum = 0.0;
            int[] D = new int[n];
            for (int i=0;i<n;i++)
            {
                Random rnd = new Random();
                D[i] = rnd.Next(m, l);
                Console.WriteLine($"D[i]={D[i]}");
                sum += Math.Abs(D[i]);
            }
            sum = sum / n;
            Console.WriteLine($"Среднее арифмитическое знач. всех элементов заданного массива D={sum}");
        }
    }
}
