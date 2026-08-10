/*Esercizio 1: Calcolatrice Avanzata
Crea una calcolatrice che supporti le seguenti operazioni:
Operazioni di base (+, -, *, /)
Potenza (x^y)
Radice quadrata
Logaritmo naturale*/

using System;
using System.Diagnostics;

namespace Esercizo1
{
    public class Esercizio1
    {
        static void Main(string[] args)
        {

            Console.WriteLine("--- CALCOLATRICE AVANZATA ---");
            Console.WriteLine("Inserisci [+]Somma, [-]Sottrazione, [*]Moltiplicazione, [/]Divisione, [^]Potenza, [R]Radice Quadrata, [L]Logaritmo Naturale, [E]esci");
            
            string scelta = Console.ReadLine() ?? "";
            double num1, num2;

            while (scelta.ToUpper() != "E")
            {
                switch (scelta.ToUpper())
                {
                    case "+":
                        Console.Write("Inserisci il primo numero: ");
                        num1 = double.Parse(Console.ReadLine() ?? "0");

                        Console.Write("Inserisci il secondo numero: ");
                        num2 = double.Parse(Console.ReadLine() ?? "0");

                        double somma = num1 + num2;

                        Console.WriteLine($"Hai inserito i numeri: {num1} e {num2}");
                        Console.WriteLine($"Il risultato della somma è: {somma}");
                        break;
                    case "-":
                        Console.Write("Inserisci il primo numero: ");
                        num1 = double.Parse(Console.ReadLine() ?? "0");

                        Console.Write("Inserisci il secondo numero: ");
                        num2 = double.Parse(Console.ReadLine() ?? "0");

                        double sotrazione = num1 - num2;

                        Console.WriteLine($"Hai inserito i numeri: {num1} e {num2}");
                        Console.WriteLine($"Il risultato della sotrazione è: {sotrazione}");
                        break;
                    case "*":
                        Console.Write("Inserisci il primo numero: ");
                        num1 = double.Parse(Console.ReadLine() ?? "0");

                        Console.Write("Inserisci il secondo numero: ");
                        num2 = double.Parse(Console.ReadLine() ?? "0");

                        double moltiplicazione = num1 * num2;

                        Console.WriteLine($"Hai inserito i numeri: {num1} e {num2}");
                        Console.WriteLine($"Il risultato della moltiplicazione è: {moltiplicazione}");
                        break;
                    case "/":
                        Console.Write("Inserisci il primo numero: ");
                        num1 = double.Parse(Console.ReadLine() ?? "0");

                        Console.Write("Inserisci il secondo numero: ");
                        num2 = double.Parse(Console.ReadLine() ?? "0");

                        if (num2 != 0)
                        {
                            double divisione = num1 / num2;

                            Console.WriteLine($"Hai inserito i numeri: {num1} e {num2}");
                            Console.WriteLine($"Il risultato della divisione è:{divisione}");
                        }
                        else
                        {
                            Console.WriteLine("Errore: Impossibile dividere per zero!");
                        }
                        break;
                    case "^":
                        Console.WriteLine("Inserisci un valore di base: ");
                        num1 = double.Parse(Console.ReadLine() ?? "0");

                        Console.WriteLine("Inserisci un valore per elevare come potenza: ");
                        num2 = double.Parse(Console.ReadLine() ?? "0");

                        Console.WriteLine($"Risultato della potenza: {Math.Pow(num1, num2)}");
                        break;
                    case "R":
                        Console.WriteLine("Inserisci un valore per fare la radice quadrata: ");
                        num1 = double.Parse(Console.ReadLine() ?? "0");

                        if (num1 >= 0)
                        {
                            Console.WriteLine($"Risultato della radice quadrata: {Math.Sqrt(num1)}");
                        }
                        else
                        {
                            Console.WriteLine("Errore: Non è possibile calcolare la radice quadrata di un numero negativo.");
                        }
                        break;
                    case "L":
                        Console.Write("Inserisci un numero per il logaritmo naturale (ln): ");
                        num1 = double.Parse(Console.ReadLine() ?? "0");

                        if (num1 > 0)
                        {
                            Console.WriteLine($"Il logaritmo naturale di {num1} è: {Math.Log(num1)}");
                        }
                        else
                        {
                            Console.WriteLine("Errore: Il logaritmo naturale è definito solo per numeri strettamente positivi (> 0).");
                        }
                        break;
                    default:
                        Console.WriteLine($"Hai inserito un valore non valido: '{scelta}'");
                        break;
                }

                Console.WriteLine("\n------------------------------------------------");
                Console.WriteLine("Scegli un'operazione (+, -, *, /, ^, R, L) oppure [E] per uscire:");
                scelta = Console.ReadLine() ?? "";
            }

            Console.WriteLine("Calcolatrice chiusa. Alla prossima!");
        }
    }
}