using System;
class HelloWorld
{
    struct Dot
    {
        public int x;
        public int y;
    }

    struct Trinagle
    {
        public Dot a;
        public Dot b;
        public Dot c;
    }

    static void Main()
    {
        Trinagle trinagle = new Trinagle();

        Console.WriteLine("Введите x1, y1:");
        trinagle.a.x = Convert.ToInt32(Console.ReadLine());
        trinagle.a.y = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine();

        Console.WriteLine("Введите x2, y2:");
        trinagle.b.x = Convert.ToInt32(Console.ReadLine());
        trinagle.b.y = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine();

        Console.WriteLine("Введите x3, y3:");
        trinagle.c.x = Convert.ToInt32(Console.ReadLine());
        trinagle.c.y = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine();

        double A = Math.Sqrt(Math.Pow((trinagle.b.x - trinagle.a.x), 2) + Math.Pow((trinagle.b.y - trinagle.a.y), 2));
        double B = Math.Sqrt(Math.Pow((trinagle.c.x - trinagle.b.x), 2) + Math.Pow((trinagle.c.y - trinagle.b.y), 2));
        double C = Math.Sqrt(Math.Pow((trinagle.a.x - trinagle.c.x), 2) + Math.Pow((trinagle.a.y - trinagle.c.y), 2));

        double P = (A + B + C) / 2;
        double S = Math.Sqrt(P * (P - A) * (P - B) * (P - C));

        Console.WriteLine("Периметр треугольника = " + P);
        Console.WriteLine("Площадь треугольника = " + S);

    }
}