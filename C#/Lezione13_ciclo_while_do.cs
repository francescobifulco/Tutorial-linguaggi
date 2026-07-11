using System;

namespace Lezione13 {
    public class Lezione13_ciclo_while_do { 
        static void Main(string[] args) {
            
            // La variabile 'i' viene definita come contatore 
            // (o indice) del ciclo
            int i = 0;

            // =================================================================
            // 1. IL CICLO WHILE (Controllo in testa)
            // =================================================================
            Console.WriteLine("--- 1. Inizio Ciclo While ---");
            
            // Verifica la condizione PRIMA di entrare. Se è vera, 
            // esegue il blocco.
            // Gira per i = 0, 1, 2, 3, 4. Quando i diventa 5, esce dal ciclo.

            while (i < 5){
                Console.WriteLine($"While: i vale {i}");

                // FONDAMENTALE: incrementare il contatore. 
                // Se dimenticassi 'i++', il ciclo rimarrebbe 
                // bloccato all'infinito su i = 0 (Loop Infinito)!
                i++;
            }

            // =================================================================
            // 2. IL CICLO DO-WHILE (Controllo in coda)
            // =================================================================
            Console.WriteLine("\n--- 2. Inizio Ciclo Do-While ---");
            
            // In questo punto 'i' vale 5 (ereditato dal ciclo precedente).
            // Il do-while esegue il codice ALMENO UNA VOLTA a prescindere, 
            // e solo dopo controlla la condizione nel 'while' in fondo.
            do{
              Console.WriteLine($"Do-While: i vale {i}");
              i++;  
            } while (i < 10);// Gira finché i è minore di 10. Alla fine 
            // di questo ciclo 'i' varrà 10.

            // =================================================================
            // 3. SECONDO CICLO WHILE CON LOGICA ANNIDATA
            // =================================================================
            Console.WriteLine("\n--- 3. Secondo Ciclo While (Resettato) ---");
            
            // RISOLUZIONE DEL BUG LOGICO: 
            // Poiché 'i' è arrivato a 10, dobbiamo r
            // esettarlo a 0 per far avviare il prossimo ciclo.
            i = 0;

            while (i < 5){
                // Logica condizionale all'interno del loop
                if (i == 3) {
                    Console.WriteLine("Siamo i 3 porcellini!");
                }
                
                Console.WriteLine($"While 2: i vale {i}");
                i++;
            }
        }
    }
}