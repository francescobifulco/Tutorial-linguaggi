using System;

namespace Lezione15 {
    public class Lezione15_break_continue_cicli { 
        static void Main(string[] args) {

            // =================================================================
            // 1. L'ISTRUZIONE BREAK (Interruzione totale)
            // =================================================================
            Console.WriteLine("--- 1. Test con BREAK ---");
            for (int i = 0; i < 5; i++){
                if (i == 3){
                    // Quando la variabile 'i' arriva a 3, 
                    // l'istruzione 'break' si attiva.
                    // Il break interrompe BRUTALMENTE e 
                    // IMMEDIATAMENTE l'intero ciclo.
                    // Il programma esce dalle parentesi 
                    // graffe del for e prosegue oltre.
                    break;
                } 

                // Questo verrà eseguito solo per 
                // i = 0, 1, 2. I numeri 3 e 4 non verranno mai stampati.
                Console.WriteLine($"Giro del For (Break): i vale {i}");
            }
            Console.WriteLine("--> Siamo usciti dal primo ciclo for.");

            // =================================================================
            // 2. L'ISTRUZIONE CONTINUE (Salto del giro)
            // =================================================================
            Console.WriteLine("\n--- 2. Test con CONTINUE ---");

            for (int i = 0; i < 5; i++) {
                // Quando la variabile 'i' arriva a 3, l'istruzione 
                // 'continue' si attiva.
                // A differenza del break, il continue NON distrugge il ciclo; 
                // salta solo ed esclusivamente il codice rimanente 
                // del giro ATTUALE (riga 45)
                // e rimanda subito il controllo 
                // all'incremento (i++) per iniziare il giro successivo.
                if (i == 3) {
                    continue; 
                }

                // Questo verrà eseguito per i = 0, 1, 2... 
                // poi salterà il 3... e riprenderà per il 4!
                Console.WriteLine($"Giro del For (Continue): i vale {i}");
            }
            Console.WriteLine("--> Siamo usciti dal secondo ciclo for.");
        }
    }
}