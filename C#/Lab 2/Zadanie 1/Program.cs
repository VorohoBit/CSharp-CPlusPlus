using System;

namespace C_sharp__laba2_zadanie1_
{
    class Program
    {
        static void Main(string[] args)
        {
            double A = 3.125;
            int I = 6006006;
            float C = -13.24f;
            bool L = false;
            string name = "Maxim";
            System.Console.WriteLine($"double A ={ A }, float C = { C }, int I = { I }, Имя:{ name }, bool L={ L }");
            Console.WriteLine("Начинаем форматирование");
            Console.WriteLine("Введите имя:");
            name = Console.ReadLine();
            Console.WriteLine("Введите значение double A:");
            double A1 = Convert.ToDouble(Console.ReadLine());
            Console.WriteLine("Введите значение  float C:");
            float C1 = float.Parse(Console.ReadLine());
            Console.WriteLine("Введите значение int I:");
            I = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите значение bool L:");
            L = Convert.ToBoolean(Console.ReadLine());
            System.Console.WriteLine($"name = { name }, L = { L }");
            System.Console.WriteLine($"A ={ A1 }, C = { C1 }, I = { I }");
        }
    }
}
