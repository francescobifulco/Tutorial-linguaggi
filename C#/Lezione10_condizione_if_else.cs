using System;

namespace Lezione10 {
    public class Lezione10_condizione_if_else {
        static void Main(string[] args) {
            
            int numero = 6;
            
            // =================================================================
            // 1. COSTRUTTO IF - ELSE IF - ELSE (Cascata decisionale)
            // =================================================================
            Console.WriteLine("--- 1. Verifica Condizioni in Cascata ---");

            // Il programma valuta la prima condizione. Se è vera, 
            // esegue il blocco e salta alla fine.
            if (5 > 6) {
                Console.WriteLine("Condizione 1 verificata (5 > 6)");
            }
            // Se la prima è falsa, passa a valutare questa (Else If). 
            // Poiché 'numero' è uguale a 6, questa condizione è TRUE. 
            // Il programma eseguirà questo blocco.
            else if (numero == 6){
                Console.WriteLine("Il numero è 6");
            }
            // L'ultimo 'else' è il paracadute: viene eseguito solo 
            // se TUTTE le condizioni precedenti sono risultate FALSE.
            // In questo caso specifico, verrà saltato perché 
            // l'else if precedente era vero.
            else {
                Console.WriteLine("Nessuna condizione verificata");
            }

            // =================================================================
            // 2. COSTRUTTI CONDIZIONALI ANNIDATI (Nested If)
            // =================================================================
            Console.WriteLine("\n--- 2. Condizioni Annidate ---");

            // Controllo principale: verifichiamo se il resto della 
            // divisione per 2 è zero (algoritmo per i numeri PARI)
            if (numero % 2 == 0){
                Console.WriteLine("Il numero è pari");

                // --- SOTTO-CONDIZIONE (Annidata) ---
                // Questo blocco viene preso in considerazione 
                // SOLO SE il numero è pari.
                if (numero < 10){
                    Console.WriteLine("Il numero è pari e minore di 10");
                }else{
                    Console.WriteLine("Il numero è pari ma maggiore o uguale a 10");
                }
            }
            // Se il controllo principale fallisce (il resto non è 0), 
            // il numero è automaticamente dispari
            else{
                Console.WriteLine("Il numero e dispari");
            }
        
        }
    }
}