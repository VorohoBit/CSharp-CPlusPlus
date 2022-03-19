using System;

namespace C_sharp__laba6
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите нижний диапазон:");
            int m = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите верхний диапазон:");
            int l = Convert.ToInt32(Console.ReadLine());
            int[,] Matrix = new int[5, 6];
            Random rnd = new Random();
            int z = 0;
            int[] Massive = new int[30];
            for (int i=0;i<5;i++)
            {
                Console.WriteLine("\n");
                for (int j=0;j<6;j++)
                {
                    Matrix[i,j] = rnd.Next(m,l);
                    Console.Write("{0, 5}",Matrix[i,j]);
                    Massive[z] = Matrix[i, j];
                    z++;
                }
            }
            Console.WriteLine("\n\nОдномерный массив того же размера,по строкам с сохранением порядка следования элементов:");
            for (int i=0;i<30;i++)
            {
                Console.WriteLine();
                Console.Write("{0, 5}", Massive[i]);
            }
        }
    }
}
