/*Esercizio 1: Calcolatrice Avanzata
Crea una calcolatrice che supporti le seguenti operazioni:
Operazioni di base (+, -, *, /)
Potenza (x^y)
Radice quadrata
Logaritmo naturale
Memoria per salvare/recuperare valori
Suggerimento: Implementa un’interfaccia IOperazione che 
rappresenta un’operazione matematica con un metodo 
Esegui(double a, double b).*/

using System;
using System.Diagnostics;

namespace Esercizo1
{
    public class Esercizio1
    {
        static void Main(string[] args)
        {

            Console.WriteLine("Inserisci [+]Somma, [-]Sottrazione, [*]Moltiplicazione, [/]Divisione, [E]esci");
            string scelta = Console.ReadLine() ?? "";

            while (scelta != "e" && scelta != "E")
            {
                switch (scelta)
                {
                    case "+":
                        Console.Write("Inserisci il primo numero: ");
                        int num1 = int.Parse(Console.ReadLine() ?? "0");

                        Console.Write("Inserisci il secondo numero: ");
                        int num2 = int.Parse(Console.ReadLine() ?? "0");

                        int somma = num1 + num2;

                        Console.WriteLine($"Hai inserito i numeri: {num1} e {num2}");
                        Console.WriteLine($"Il risultato della somma è: {somma}");
                        break;
                    default: Console.WriteLine($"Hai inserito un valore non valido: '{scelta}'"); 
                    break;
                }
            }
        }
    }
}