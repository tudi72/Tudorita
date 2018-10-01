using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace pregatire_test
{
    class complex
    {
        public double im, re;
        public complex()
        { re = 0;
            im = 0;
        }
        public complex(double x, double y)
        {
            re = x;
            im = y;
        }
        public static complex operator +(complex a, complex b)
        {
            return new complex(a.re + b.re, a.im + b.im);
        }
        public static complex operator -(complex a, complex b)
        {
            return new complex(a.re - b.re, a.im - b.im);
        }
        public void afisare()
        {
            Console.WriteLine(re + "+" + im + "j");
        }
        public double modul()
        {
            double nr = re*re-im*im;
            return Math.Sqrt(nr);
        }
        public static bool operator <(complex x, complex y)
        {
            return (x.modul() < y.modul());
        }
        public static bool operator >(complex x, complex y)
        {
            return (x.modul() > y.modul());
        }
        public static bool operator!=(complex x, complex y)
            {
            return (x.modul()!= y.modul());
            }
    public static bool operator==(complex x,complex y)
        {
            return (x.modul() == y.modul());
        }
        public void afisare_complexa()
        {
            if (re != 0 && im != 0)
                Console.WriteLine(re + "+" + im + "j");
            else if (re == 0)
                Console.WriteLine(im + "j");
            else if (im == 0)
                Console.WriteLine(re);
        }
    }
   
    class Program
    {
        static void Main(string[] args)
        {
            complex a, b;
            a = new complex(2, 4);
            b = new complex(1, 5);
            a.afisare();
            b.afisare();
            (a + b).afisare();
            (a - b).afisare();

            Console.ReadKey();
        }
    }
}
