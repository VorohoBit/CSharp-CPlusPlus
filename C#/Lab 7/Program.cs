using System;

namespace C_sharp__laba7
{
   public class Coords
    {
        private double x1,x2,x3,x4;
        private double y1,y2,y3,y4;
        public Coords(double x1,double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            this.x3 = x3;
            this.y3 = y3;
            this.x4 = x4;
            this.y4 = y4;
        }
        public void PrintCoords()
        {
            Console.WriteLine($"A=({x1},{y1})");
            Console.WriteLine($"B=({x2},{y2})");
            Console.WriteLine($"C=({x3},{y3})");
            Console.WriteLine($"D=({x4},{y4})");
        }
        public void FindStoroni_Perimetr()
        {
            double d12 = Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
            Console.WriteLine("Сторона AB={0:0.00}", d12);
            double d13 = Math.Sqrt(Math.Pow(x3 - x1, 2) + Math.Pow(y3 - y1, 2));
            Console.WriteLine("Сторона AC={0:0.00}", d13);
            double d14 = Math.Sqrt(Math.Pow(x4 - x1, 2) + Math.Pow(y4 - y1, 2));
            Console.WriteLine("Сторона AD={0:0.00}", d14);
            double d23 = Math.Sqrt(Math.Pow(x3 - x2, 2) + Math.Pow(y3 - y2, 2));
            Console.WriteLine("Сторона BC={0:0.00}", d23);
            double d24 = Math.Sqrt(Math.Pow(x4 - x2, 2) + Math.Pow(y4 - y2, 2));
            Console.WriteLine("Сторона BD={0:0.00}", d24);
            double d34 = Math.Sqrt(Math.Pow(x4 - x3, 2) + Math.Pow(y4 - y3, 2));
            Console.WriteLine("Сторона CD={0:0.00}", d13);
            double Pabc = d12 + d13 + d23;
            Console.WriteLine("Периметр треугольника ABC={0:0.0000}", Pabc);
            double Pabd = d12 + d14 + d24;
            Console.WriteLine("Периметр треугольника ABD={0:0.0000}", Pabd);
            double Pacd = d13 + d14 + d34;
            Console.WriteLine("Периметр треугольника ACD={0:0.0000}", Pacd);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Random rnd = new Random();
            Coords myCoords = new Coords(rnd.Next(-100,100), rnd.Next(-100, 100), rnd.Next(-100, 100), rnd.Next(-100, 100), 
                rnd.Next(-100, 100), rnd.Next(-100, 100), rnd.Next(-100, 100), rnd.Next(-100, 100));
            myCoords.PrintCoords();
            myCoords.FindStoroni_Perimetr();
        }
    }
}
