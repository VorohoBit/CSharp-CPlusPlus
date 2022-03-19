using System;

namespace C_sharp__laba8
{
    public class class_A
    {
        private decimal a=9.45M, b=3.29M;
        public (decimal,decimal,decimal,decimal) Property_C
        {
            get {return (a - b,b-a,++a,++b);}
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            class_A A = new class_A();
            Console.WriteLine(A.Property_C);
        }
    }
}
