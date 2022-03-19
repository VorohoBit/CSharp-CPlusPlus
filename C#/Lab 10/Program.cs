using System;

namespace C_sharp__laba9
{
    public class class_A
    {
        protected double a, b;
        public double Property_C
        {
            get { return a / b; }
            set { a = value; b = value; }
        }
        public class_A()
        {
            this.a = 0;
            this.b = 0;
        }
        public class_A(double a, double b)
        {
            this.a = a;
            this.b = b;
        }
    }
    public class class_B : class_A
    {
        private double d;
        public double[] arr;
        public double Property_C2
        {
            get { if (b == 0) return d = -1; else return d = a / b; }
        }
        public class_B(double a, double b) : base(a, b)
        {
            this.a = a;
            this.b = b;
            this.d = 0;
            this.arr = new double[(int)this.a];
            for (int i = 0; i < this.arr.Length; i++)
            {
                this.arr[i] = i * this.Property_C2;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            
            class_B B = new class_B(100, 50);
            Console.WriteLine(B.Property_C2);
            foreach (var item in B.arr)
            {
                Console.Write(item + " ");
            }
        }
    }
    }
