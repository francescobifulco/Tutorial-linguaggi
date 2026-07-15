using System;
using System.Collections;
using System.Collections.Generic; // Contiene lo Stack<T> generico

namespace Lezione25 {
    public class Lezione25_stack {
        static void Main(string[] args) {

            // Creiamo uno Stack generico di interi
            Stack<int> inventario = new Stack<int>();

            // Inseriamo gli elementi in cima alla pila (Push)
            inventario.Push(10); // Fondo della pila
            inventario.Push(20);
            inventario.Push(30);
            inventario.Push(40);
            inventario.Push(50);
            inventario.Push(60); // Cima della pila

            // .Peek() guarda l'elemento in cima SENZA rimuoverlo -> Stampa 60
            Console.WriteLine($"Elemento in cima con Peek(): {inventario.Peek()}");

            Console.WriteLine("\n--- Scorrimento dello Stack ---");
            // Lo stack viene scorso dalla cima verso il fondo (da 60 a 10)
            // Nota: il foreach NON rimuove gli elementi dallo stack!
            foreach (int item in inventario) {
                Console.WriteLine(item);
            }
            Console.WriteLine("-------------------------------\n");

            // CORREZIONE: Uso corretto di TryPeek e TryPop con il parametro 'out'
            // I metodi restituiscono un booleano, mentre il valore estratto va nella variabile 'valoreEstratto'
            if (inventario.TryPeek(out int valoreLetto)) {
                Console.WriteLine($"TryPeek riuscito! Valore letto: {valoreLetto}");
            }

            if (inventario.TryPop(out int valoreRimosso)) {
                Console.WriteLine($"TryPop riuscito! Valore rimosso: {valoreRimosso}"); // Rimuove e stampa 60
            }
            
            // Lo stack ora ha il 50 in cima. 
            // Questo .Pop() classico rimuove il 50.
            inventario.Pop(); 
            
            // Il prossimo .Peek() mostrerà il numero 40
            Console.WriteLine($"Nuova cima dopo Pop(): {inventario.Peek()}");

            // Svuotiamo interamente la collezione
            inventario.Clear();
            
            // Controllo di sicurezza impeccabile: evita il crash di un .Peek() su uno stack vuoto
            if (inventario.Count > 0) {
                Console.WriteLine(inventario.Peek());
            } else {
                Console.WriteLine("Inventario vuoto correttamente rilevato.");
            }
        }
    }
}