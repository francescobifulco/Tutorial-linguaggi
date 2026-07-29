using System;
using System.Collections.Generic;
using System.Linq; // Necessario per usare metodi avanzati sulle collezioni

namespace Lezione40 {
    public class Lezione40_lambda {
        static void Main(string[] args) {
            
            Console.WriteLine("--- 1. SINTASSI BASE (INPUT => ESPRESSIONE) ---");

            // Una Lambda expression è una funzione anonima (senza nome) veloce e sintetica.
            // Si legge: "x va in x * x" (prende x e restituisce il suo quadrato)
            Func<int, int> quadrato = x => x * x;
            Console.WriteLine($"Il quadrato di 5 è: {quadrato(5)}");

            // Lambda con più parametri (richiede le parentesi tonde)
            Func<int, int, int> somma = (a, b) => a + b;
            Console.WriteLine($"La somma di 4 + 7 è: {somma(4, 7)}");


            Console.WriteLine("\n--- 2. LAMBDA CON AZIONI SENZA RITORNO (Action) ---");

            // Se la funzione non restituisce nulla (void), si usa 'Action'
            Action<string> saluta = nome => Console.WriteLine($"Ciao {nome}, benvenuto nelle Lambda!");
            saluta("Developer");


            Console.WriteLine("\n--- 3. USO PRATICO SULLE COLLEZIONI (List & LINQ) ---");

            List<int> numeri = new List<int> { 1, 5, 8, 12, 15, 20, 23 };

            // Esempio A: FindAll (Filtrare elementi con un Predicato)
            // "Prendi solo i numeri 'n' tali che n % 2 == 0" (numeri pari)
            List<int> numeriPari = numeri.FindAll(n => n % 2 == 0);
            
            Console.Write("Numeri pari trovati: ");
            numeriPari.ForEach(n => Console.Write($"{n} ")); // ForEach accetta una Lambda!
            Console.WriteLine();


            // Esempio B: Any e Count
            bool haNumeriGrandi = numeri.Any(n => n > 20); // Verifica se almeno uno è > 20
            int quantiGrandi = numeri.Count(n => n > 10);  // Conta quanti sono > 10

            Console.WriteLine($"Ci sono numeri > 20? {haNumeriGrandi}");
            Console.WriteLine($"Quanti numeri sono > 10? {quantiGrandi}");


            Console.WriteLine("\n--- 4. LAMBDA BLOCCO MULTI-RIGA ---");

            // Se la logica richiede più istruzioni, si usano le graffe { } e la keyword 'return'
            Func<int, string> valutaVoto = voto => {
                if (voto >= 18) {
                    return "Promosso";
                } else {
                    return "Bocciato";
                }
            };

            Console.WriteLine($"Esito esame (voto 24): {valutaVoto(24)}");
        }
    }
}