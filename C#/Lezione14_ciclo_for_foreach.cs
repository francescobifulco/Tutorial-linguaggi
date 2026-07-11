using System;

namespace Lezione14 {
    public class Lezione14_ciclo_for_foreach { 
        static void Main(string[] args) {
            
            // =================================================================
            // 1. IL CICLO FOR (Iterazione definita)
            // =================================================================
            Console.WriteLine("--- 1. Inizio Ciclo For ---");
            
            // Il ciclo for raggruppa 3 istruzioni fondamentali tra le sue 
            // parentesi:
            // 1. Inizializzazione: si dichiara una variabile contatore 
            // (int i = 0) valida solo dentro il for.
            // 2. Condizione: il ciclo continua finché questa 
            // espressione è vera (i < 5).
            // 3. Incremento: ad ogni fine giro, la variabile 
            // viene aumentata (i++).
            // Questo evita il rischio di dimenticarsi 
            // l'incremento (errore tipico del while).
            for(int i = 0; i < 5; i++){
                Console.WriteLine($"Giro del For: i vale {i}");
            }

            // =================================================================
            // 2. IL CICLO FOREACH (Iterazione su Collezioni/Array)
            // =================================================================
            Console.WriteLine("\n--- 2. Inizio Ciclo Foreach ---");

            // Dichiarazione e inizializzazione di un Array di 
            // stringhe (una lista fissa di elementi).
            // Le parentesi quadre [] indicano che si tratta 
            // di una collezione di dati dello stesso tipo.
            string[] nomi = { "Luca", "Edo", "Marco", "Anna" };
            
            // Il foreach è una struttura specializzata per 
            // scorrere le collezioni dall'inizio alla fine.
            // Traduzione mentale: "Per ogni stringa 'nome' 
            // che si trova dentro l'array 'nomi'..."
            // Non serve gestire indici (come la i del for) 
            // o incrementi; C# fa tutto da solo, elemento per elemento.
            foreach (string nome in nomi) {
                Console.WriteLine($"Nome estratto dall'array: {nome}");
            }
        }
    }
}