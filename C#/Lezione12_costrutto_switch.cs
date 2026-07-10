using System;

namespace Lezione12 {
    public class Lezione12_costrutto_switch {
        static void Main(string[] args){
            
            int eta = 35;
            string nome = "Luca";

            // =================================================================
            // 1. IL PARAGONE CON IF-ELSE IF
            // =================================================================
            // Quando si fanno molti controlli di uguaglianza 
            // sulla stessa variabile,
            // la struttura if-else può diventare ridondante e meno leggibile.
            if (eta == 18){
                Console.WriteLine("sei maggiorenne!");
            }else if (eta == 20){
                Console.WriteLine("sei un ventenne");
            }

            // =================================================================
            // 2. IL COSTRUTTO SWITCH
            // =================================================================
            Console.WriteLine("--- Risultato dello Switch ---");

            // Lo switch prende la variabile tra parentesi e salta 
            // direttamente al 'case' corrispondente
            switch (eta){
                // Se eta == 18
                case 18: 
                    // Logica annidata: puoi inserire qualsiasi blocco di codice dentro un case
                    if (nome == "Luca") {
                        Console.WriteLine("Luca è maggiorenne!"); 
                    }
                    // Ogni blocco 'case' DEVE terminare tassativamente con un'istruzione di interruzione, 
                    // solitamente il 'break', per uscire dallo switch.
                    break;
                
                // Se eta == 20
                case 20: 
                    Console.WriteLine("sei un ventenne"); 
                    break;
                
                // Se eta == 30
                case 30: 
                    Console.WriteLine("La vecchiaia avanza"); 
                    break;
                
                // Il 'default' è l'equivalente dell'ultimo 'else'. 
                // Viene eseguito se NESSUNO dei case precedenti è stato attivato (es. in questo caso eta è 35).
                default: 
                    Console.WriteLine($"Hai {eta} anni. Non so che età tu abbia per i miei calcoli."); 
                    break;
            }
        }
    }
}