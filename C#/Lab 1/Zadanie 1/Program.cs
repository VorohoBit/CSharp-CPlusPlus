using System;

namespace C_sharp__laba1_zadanie_1_
{
    class Program
    {
        static void Main(string[] args)
        {
            OperatingSystem os = System.Environment.OSVersion;
            Console.WriteLine("Операционная система и её версия: {0}",os);
            System.Console.WriteLine("Текущая дата и время: " + System.DateTime.Now);
        }
    }
}
