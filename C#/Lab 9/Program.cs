using System;

namespace C_sharp__laba9
{
    public class class_A
    {
        protected decimal a, b;
        public decimal Property_C
        {
            get { if (a > b) return a - b; else return b - a; }
            set { a = value;b = value; }
        }
        public class_A() 
        {
        }
        public class_A(decimal a,decimal b)
        {
            this.a = a;
            this.b = b;
        }
    }
    public class class_B : class_A
    {
        private decimal d;
        public decimal Property_C2
        {
            get { return a+b+d; }
            set { a = value; b = value; d = value; }
        }
        public class_B()  //собственный констуктор по умолчанию
        {
            a = 1;
            b = 1;
            d = 1;
        } 
        public class_B(decimal a,decimal b,decimal d) : base(a,b) //наследуемый конструктор
        {
            this.d = d;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            decimal dec1 = rnd.Next(-7,8);
            decimal dec2 = rnd.Next(-7,8);
            Console.WriteLine($"dec1={dec1}\t dec2={dec2}");
            class_A A = new class_A();
            class_A Double_A = new class_A(dec1, dec2);
            class_B B = new class_B();
            class_B Double_B = new class_B(10.1M,10.1M,10.1M);
            decimal g = A.Property_C;
            decimal Double_g = Double_A.Property_C;
            decimal Triple_g = B.Property_C2;
            decimal Quadruple_g = Double_B.Property_C2;
            Console.WriteLine(g);
            Console.WriteLine(Double_g);
            Console.WriteLine(Triple_g);
            Console.WriteLine(Quadruple_g);
            Console.WriteLine(g+Double_g+Triple_g+Quadruple_g);
        }
    }
}
