using System;
using System.Collections;
using System.Collections.Generic;

namespace Lezione26 {
    public class Lezione26_queue {
        static void Main(string[] args) {
            
           // Creiamo una Coda generica di stringhe
            Queue<string> persone = new Queue<string>();

            // Inserimento in coda (in fondo alla fila)
            persone.Enqueue("Edo");       // <-- Davanti alla fila (Primo)
            persone.Enqueue("Anna");
            persone.Enqueue("Francesco");
            persone.Enqueue("Luca");
            persone.Enqueue("Marco");
            persone.Enqueue("Mirco");     // <-- Fondo della fila (Ultimo)

            // .Peek() guarda chi è in testa alla fila SENZA rimuoverlo -> Stampa "Edo"
            Console.WriteLine($"In testa alla fila: {persone.Peek()}");

            // .Dequeue() serve (e rimuove) il primo della fila -> "Edo" esce dalla coda
            persone.Dequeue(); 
            
            // Ora in testa c'è "Anna" -> Stampa "Anna"
            Console.WriteLine($"Nuova testa dopo Dequeue: {persone.Peek()}");

            Console.WriteLine("\n--- Scorrimento con Foreach ---");
            // Il foreach mostra le persone nell'ordine in cui verranno servite (da Anna a Mirco)
            // Nota: il foreach NON rimuove nessuno dalla coda!
            foreach (string persona in persone) {
                Console.WriteLine(persona);
            }

            Console.WriteLine("\n--- Svuotamento dinamico con While ---");
            // Questo ciclo è perfetto: finché c'è qualcuno, lo estrae e lo stampa.
            // Al termine di questo ciclo, la coda sarà completamente VUOTA (Count = 0).
            while (persone.Count > 0) {
                Console.WriteLine($"Servito e rimosso: {persone.Dequeue()}");
            }

            // Inutile ma sicuro, ora la coda ha già 0 elementi
            persone.Clear();
            
            // Per evitare il crash su una coda vuota, usiamo un controllo prima del Peek
            // oppure usiamo il metodo sicuro TryPeek!
            if (persone.TryPeek(out string prossimaPersona)) {
                Console.WriteLine($"Prossima persona: {prossimaPersona}");
            } else {
                Console.WriteLine("Coda vuota! Nessuno da guardare con TryPeek().");
            }
        }
    }
}