using Injector.Enums;
using System;
using System.Diagnostics;
using System.IO;
using System.Runtime.InteropServices;
using System.Text;

namespace Injector
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Input Hook Process Name:");
            string name = Console.ReadLine();
            DllInjector dllInjector = DllInjector.GetInstance;
            var res  = dllInjector.Inject(name, Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "Dotnet.dll"));
            Console.WriteLine(Enum.GetName(typeof(DllInjectionResult), res));
            Console.WriteLine("Any Key To Exit:");
            Console.ReadKey();
        }

    }
}
