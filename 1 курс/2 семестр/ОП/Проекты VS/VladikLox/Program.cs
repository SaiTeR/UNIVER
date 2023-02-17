using System;

public class HelloWorld
{
    public struct TIME
    {
        public int hour;
        public int min;
        public int sec;
    }

    public static void Main(string[] args)
    {
        Random rnd = new Random();
        TIME[] t = new TIME[10];
        int min_dif = 100000000;

        for (int i = 0; i < t.Length; i++)
        {
            t[i].hour = rnd.Next(0, 23);
            t[i].min = rnd.Next(0, 59);
            t[i].sec = rnd.Next(0, 59);

            Console.WriteLine((i + 1) + ". " + t[i].hour + " " + t[i].min + " " + t[i].sec);
        }

        for (int i = 0; i < (t.Length - 1); i++)
        {
            for(int j = (i + 1); j < t.Length;j++)
            {
                int time1 = (t[i].hour * 3600 + t[i].min * 60 + t[i].sec);
                int time2 = (t[j].hour * 3600 + t[j].min * 60 + t[j].sec);

                if (Math.Abs(time1 - time2) < min_dif)
                {
                    min_dif = Math.Abs(time1 - time2);
                }
            }
        }


        Console.WriteLine("Минимальная разница = " + min_dif);

    }

}