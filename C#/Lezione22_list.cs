using System;
using System.Collections;
using System.Collections.Generic; // Fondamentale! Contiene le liste generiche come List<T>

namespace Lezione22 {
    public class Lezione22_list { 
        static void Main(string[] args) {
            
            int[] arrayInteri = {10, 20, 30};
            
            // Dichiarazione di una lista che accetterà 
            // RIGOROSAMENTE solo numeri interi (<int>)
            List<int> prova = new List<int>() { 1, 2, 3, 4 };
            
            // Aggiunta singola
            prova.Add(5);
            
            // Aggiunta di un'intera collezione 
            // (l'array di interi è perfettamente compatibile)
            prova.AddRange(arrayInteri);

            Console.WriteLine("--- Primo Scorrimento (Foreach) ---");
            foreach (int item in prova) {
                Console.WriteLine(item);
            }

            // Inserimento in una posizione specifica (Indice 0)
            prova.Insert(0, 55);
            Console.WriteLine($"\nElemento inserito in posizione 0: {prova[0]}");

            // =================================================================
            // OPERAZIONI DI RIMOZIONE E VERIFICA
            // =================================================================
            prova.Remove(5);         // Cerca il VALORE 5 e rimuove la sua prima occorrenza
            prova.RemoveAt(0);       // Rimuove l'elemento all'INDICE 0 (ovvero il 55 appena inserito)
            prova.RemoveRange(0, 4); // Rimuove 4 elementi consecutivi partendo dall'indice 0

            // Verifica la presenza di un elemento (Ritorna un booleano: True/False)
            Console.WriteLine($"\nLa lista contiene ancora il numero 10?: {prova.Contains(10)}");

            // =================================================================
            // SCORRIMENTO CON OPERAZIONE MATEMATICA SICURA
            // =================================================================
            Console.WriteLine("\n--- Secondo Scorrimento con Modifica al Volo (For) ---");
            
            // Nota come qui l'operazione 'prova[i] + 1' sia sicura al 100%: 
            // C# sa già in anticipo che dentro la lista ci sono solo interi!
            for (int i = 0; i < prova.Count; i++) {
                Console.WriteLine($"Valore originale + 1: {prova[i] + 1}");
                }
            }
        }
    }