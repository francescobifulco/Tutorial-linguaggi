using System;

namespace Lezione20 {
    public class Lezione20_array_irregolari_jagged { 
        static void Main(string[] args) {
            
            // =================================================================
            // 1. ALLOCAZIONE E INIZIALIZZAZIONE MANUALE
            // =================================================================
            
            // Dichiariamo un array che conterrà 4 sotto-array di interi.
            // La seconda parentesi resta vuota ([][]) perché le 
            // lunghezze dei sotto-array cambieranno.
            int[][] array_irregolare = new int[4][];
            
            // Inizializziamo ogni singola riga con un array 
            // di dimensioni differenti
            array_irregolare[0] = new int[] { 11, 21 };             // Lunghezza 2
            array_irregolare[1] = new int[] { 11, 21, 31 };         // Lunghezza 3
            array_irregolare[2] = new int[] { 11, 21, 31, 41 };     // Lunghezza 4
            array_irregolare[3] = new int[] { 11, 21, 31, 41, 51 }; // Lunghezza 5


            // =================================================================
            // 2. INIZIALIZZAZIONE DIRETTA (Sintassi compatta)
            // =================================================================
            
            // Modo più rapido per scrivere un Jagged Array senza dichiarare 
            // la dimensione iniziale.
            int[][] array_irregolare1 = {
                new int[] { 1, 2, 3, 4 },
                new int[] { 1, 2, 3, 4, 5, 6, 7 },
                new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }
            };


            // =================================================================
            // 3. LETTURA, MODIFICA E ACCESSO AI DATI
            // =================================================================
            Console.WriteLine("--- Accesso e Modifica ---");

            // Lettura: Riga indice 2, Colonna indice 2 
            // (Terza riga, terzo elemento -> 3)
            Console.WriteLine($"Valore originale in [2][2]: {array_irregolare1[2][2]}");

            // Modifica: Sovrascriviamo il valore in quella precisa coordinata
            array_irregolare1[2][2] = 1;
            Console.WriteLine($"Nuovo valore in [2][2]: {array_irregolare1[2][2]}\n");


            // =================================================================
            // 4. SCORRIMENTO CON CICLI FOR ANNIDATI
            // =================================================================
            Console.WriteLine("--- Scorrimento Completo ---");

            // array_irregolare1.Length ci restituisce il numero totale di RIGHE (3)
            for (int riga = 0; riga < array_irregolare1.Length; riga++) {
                
                // array_irregolare1[riga].Length ci dà la lunghezza 
                // specifica di QUELLA riga.
                // Questa è la chiave per non andare fuori dai limiti 
                // (IndexOutOfRangeException)!
                for (int colonna = 0; colonna < array_irregolare1[riga].Length; colonna++) {
                    Console.WriteLine($"Riga {riga}, Colonna {colonna}: valore {array_irregolare1[riga][colonna]}");
                }
            }

        }
    }
}