using System;

namespace Lezione6 {
    public class Lezione6_interi {
        static void Main(string[] args){
            
            // ==========================================
            // 1. OPERATORI ARITMETICI FONDAMENTALI
            // ==========================================

            int a = 5;
            double b = 5.0;
            int c = 10;
            
            int d = a + c;  // Addizione (15)
            int e = a - c;  // Sottrazione (-5)
            int f = a * c;  // Moltiplicazione (50)

            // ATTENZIONE: divisione tra interi.
            int g = a / c;

            // Operatore Modulo (%): restituisce il RESTO della 
            // divisione intera. 5 diviso 10 fa 0 con il resto di 5.
            int h = a % c;

           Console.WriteLine("--- 1. Operazioni Base ---");
            Console.WriteLine($"a = {a}, b = {b}, c = {c}");
            Console.WriteLine($"Somma (a + c): {d}");
            Console.WriteLine($"Sottrazione (a - c): {e}");
            Console.WriteLine($"Moltiplicazione (a * c): {f}");
            Console.WriteLine($"Divisione Intera (a / c): {g} <-- Nota che perde lo 0.5!");
            Console.WriteLine($"Resto della divisione (a % c): {h}");

            // ==========================================
            // 2. ESPRESSIONI COMPLESSE E PRECEDENZE
            // ==========================================
            // Rispetta l'ordine delle parentesi algebriche

            int espressione = ((5 + 6) * 12) / (2 - 55); 
            Console.WriteLine($"\n--- 2. Espressione complessa: {espressione}");

            // ==========================================
            // 3. INCREMENTO / DECREMENTO (Post-fisso)
            // ==========================================
            Console.WriteLine("\n--- 3. Incremento e Decremento ---");
            
            // Il post-incremento (a++) prima assegna il valore attuale ad 'c' e POI aumenta 'a' di 1.
            c = a++; 
            Console.WriteLine($"Post-Incremento -> c riceve il vecchio valore di a ({c}), poi a diventa {a}");

            // Il post-decremento (a--) prima assegna il valore attuale ad 'c' e POI diminuisce 'a' di 1.
            c = a--; 
            Console.WriteLine($"Post-Decremento -> c riceve il vecchio valore di a ({c}), poi a torna {a}");

            // ==========================================
            // 4. SCORCIATOIE DI ASSEGNAZIONE
            // ==========================================
            Console.WriteLine("\n--- 4. Operatori di Assegnazione ---");
            
            a = a + 5; // Modo classico per aumentare una variabile di 5
            Console.WriteLine($"Assegnazione classica (a = a + 5): {a}");

            a += 5;    // Modo compresso (Scorciatoia). Fa esattamente 
            // la stessa identica cosa!
            Console.WriteLine($"Scorciatoia (a += 5): {a}");

          // ==========================================
            // 5. CONCATENAZIONE vs PARSING
            // ==========================================
            Console.WriteLine("\n--- 5. Stringhe e Parsing ---");
            
            string ab = "5";
            string ba = "5";
            // Essendo stringhe, il "+" le unisce (le concatena), non le somma!
            Console.WriteLine($"Concatenazione di stringhe (\"5\" + \"5\"): {ab + ba}"); 

            // Int32.Parse prende una STRINGA e la trasforma in un vero numero INT.
            int numeroDaStringa = Int32.Parse("5"); 
            
            // CORREZIONE: Qui convertiamo le stringhe 'ab' e 'ba' in 
            // interi per poterle sommare matematicamente.
            int sommaDaParsing = Int32.Parse(ab) + Int32.Parse(ba);
            Console.WriteLine($"Somma dopo il Parse di \"5\" + \"5\": {sommaDaParsing}");


            // ==========================================
            // 6. CLASSE MATH (Funzioni Matematiche)
            // ==========================================
            Console.WriteLine("\n--- 6. Metodi della classe Math ---");
            
            Console.WriteLine($"Valore Assoluto di -40: {Math.Abs(-40)}");
            Console.WriteLine($"Il Minimo tra 3 e 6: {Math.Min(3, 6)}");
            Console.WriteLine($"Il Massimo tra 3 e 6: {Math.Max(3, 6)}");
            Console.WriteLine($"Potenza (2 elevato alla 3): {Math.Pow(2, 3)}");
            Console.WriteLine($"Radice Quadrata di 16: {Math.Sqrt(16)}");

            // Evita la chiusura immediata della console
            Console.ReadLine();

        }
    }
}