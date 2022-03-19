using System;

namespace C_sharp__laba12
{
    class MyClass
    {
        private int x, y;
        public MyClass(int x, int y)
        {
            this.x = x; this.y = y;
        }
        public static bool operator true(MyClass v)
        {
            if ((v.x != 0) || (v.y != 0))  return true; 
            else return false;
        }
        public static bool operator false(MyClass v)
        {
            if ((v.x == 0) && (v.y == 0)) return true;
            else return false;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            MyClass my = new MyClass(0, 0);
            if (my) Console.WriteLine("True");
            else Console.WriteLine("False");
        }
    }
}
