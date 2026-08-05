using System;
using System.Collections.Generic;

namespace Lezione49 {

    // REGOLE FONDAMENTALI PER GLI EXTENSION METHODS:
    // 1. La classe che li contiene DEVE essere 'static'
    // 2. Il metodo DEVE essere 'static'
    // 3. Il primo parametro DEVE usare la parola 
    // chiave 'this' seguita dal tipo da estendere
    public static class MieEstensioni {

        // --- 1. ESTENSIONE SUL TIPO STRING ---
        // Aggiunge il metodo .ContaParole() a qualsiasi oggetto stringa
        public static int ContaParole(this string testo) {
            if (string.IsNullOrWhiteSpace(testo)) {
                return 0;
            }

            string[] parole = testo.Split(new char[] { ' ', '\t', '\n' }, StringSplitOptions.RemoveEmptyEntries);
            return parole.Length;
        }

        // --- 2. ESTENSIONE SUL TIPO INT ---
        // Aggiunge il metodo .IsPari() a tutti i numeri interi
        public static bool IsPari(this int numero) {
            return numero % 2 == 0;
        }

        // --- 3. ESTENSIONE SU UN TIPO GENERICO/COLLEZIONE (IEnumerable<T>) ---
        // Stampa tutti gli elementi di una lista/array separati da virgola
        public static void StampaFormattata<T>(this IEnumerable<T> collezione, string titolo) {
            Console.WriteLine($"--- {titolo} ---");
            Console.WriteLine(string.Join(", ", collezione));
        }
    }
    public class Lezione49_extension_methods {
        static void Main(string[] args) {
            
            Console.WriteLine("--- 1. ESTENSIONE SULLA CLASSE STRING ---");

            string frase = "Imparare C# e .NET è un ottimo percorso";
            
            // Usiamo ContaParole() direttamente sulla variabile 
            // frase come se fosse un metodo nativo!
            int numeroParole = frase.ContaParole();
            
            Console.WriteLine($"Frase: \"{frase}\"");
            Console.WriteLine($"Numero di parole lette: {numeroParole}");


            Console.WriteLine("\n--- 2. ESTENSIONE SUL TIPO VALORE INT ---");

            int num1 = 42;
            int num2 = 15;

            Console.WriteLine($"Il numero {num1} è pari? {num1.IsPari()}");
            Console.WriteLine($"Il numero {num2} è pari? {num2.IsPari()}");

            // Si può invocare direttamente anche sui valori letterali!
            Console.WriteLine($"Il numero 100 è pari? {100.IsPari()}");


            Console.WriteLine("\n--- 3. ESTENSIONE SU COLLEZIONI GENERICHE ---");

            List<string> linguaggi = new List<string> { "C#", "Java", "Python", "C++" };
            int[] voti = new int[] { 28, 30, 24, 27, 30 };

            // Invochiamo il nostro metodo StampaFormattata sia su List<string> che su int[]
            linguaggi.StampaFormattata("Linguaggi Conosciuti");
            voti.StampaFormattata("Voti Esami");
        }
    }
}