using System;

namespace C_sharp__laba11
{
    public class class_B
    {
        private int[] arr1 = { 1, 2, 3, 4 };
        private int[] arr2 = { 5, 6, 7, 8 };
        public int this[int index1, int index2] //индекс
        {
            get
            {
                if (index1 == -1) { return arr2[index2]; }
                else if (index2 == -1) { return arr1[index1]; }
                else { return arr1[index1] + arr2[index2]; }

            }
            set
            {
                if (index1 == -1) { arr2[index2] = value; }
                else if (index2 == -1) { arr1[index1] = value; }
            }
        }
    }

    public class class_C
    {
        public static string str = "No No";
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Демонстрация работы со статическим полем и параметризированным классом");
            Console.WriteLine("1)Выведем изначальное значение str:");
            Console.WriteLine(class_C.str);
            Console.WriteLine("2)Добавим ещё одну фразу к изначальному значению str:");
            class_C.str += " Dont tuch me there";
            Console.WriteLine(class_C.str);
            Console.WriteLine("3)И ещё одну)");
            class_C.str += " this is my no no square";
            Console.WriteLine(class_C.str);
            Console.WriteLine("Демонстрация работы с индексатором");
            class_B B = new class_B();
            for (int i = 0; i < 4; i++)
            {
                Console.Write(B[i, -1] + " ");
                B[-1, i] += B[i, -1];
            }
            Console.WriteLine("");
            for (int i = 0; i < 4; i++)
            {
                Console.Write(B[-1, i] + " ");
            }
            Console.WriteLine("");
            for (int i = 0; i < 4; i++)
            {
                Console.Write(B[i, i] + " ");
            }
        }
    }
}
