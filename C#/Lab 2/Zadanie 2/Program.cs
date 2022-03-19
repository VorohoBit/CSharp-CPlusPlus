using System;
using System.IO;

namespace C_sharp__laba2_zadanie2_
{
    class Program
    {
        static void Main(string[] args)
        {
            string str;
            double x, y;
            double pi = 3.14;
            StreamWriter fileVIVoDA = new StreamWriter("lab2RES.txt");
            StreamReader fileVVODA = new StreamReader("lab2.txt");
            fileVIVoDA.WriteLine("Таблица значений\n");
            fileVIVoDA.WriteLine("+---------------------------------------+");
            fileVIVoDA.WriteLine("+  Аргумент    + Функция                +");
            fileVIVoDA.WriteLine("+---------------------------------------+\n");
        metka: str = fileVVODA.ReadLine();
            if (str == null) goto metka1;
            x = Convert.ToDouble(str);
            y = Math.Log(pi) * Math.Sqrt(Math.Pow(x, 3) + Math.Pow(x, 2));
            fileVIVoDA.WriteLine($"+  X={x}        + Y={y}+\n");
            fileVIVoDA.WriteLine("+---------------------------------------+\n");
            goto metka;
        metka1: fileVIVoDA.WriteLine("Составил:<Лукшенас Максим Витальевич>\n", str);
            fileVIVoDA.Close();
            fileVVODA.Close();
        }
    }
}
