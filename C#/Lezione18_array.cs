using System;

namespace Lezione18 {
    public class Lezione18_array { 
        static void Main(string[] args) {
            
            // =================================================================
            // 1. DICHIARAZIONE E INIZIALIZZAZIONE DI UN ARRAY
            // =================================================================
            
            // Metodo diretto: C# capisce da solo che 
            // la dimensione dell'array è 3 
            // perché all'interno delle graffe ci sono esattamente 3 elementi.
            string[] nomi = { "Antonio", "Marco", "Luca" };

            // Metodo con allocazione: Creiamo un array 
            // "vuoto" che conterrà stringhe.
            // La sintassi 'new string[3]' dice a C# di riservare 
            // in memoria spazio per ESATTAMENTE 3 elementi.
            string[] cognomi = new string[3];

            // Assegnazione manuale tramite INDICE 
            // (Il conteggio parte sempre da 0!)
            cognomi[0] = "Rossi"; // Primo elemento (Indice 0)
            cognomi[1] = "Verdi"; // Secondo elemento (Indice 1)
            cognomi[2] = "Neri";  // Terzo elemento (Indice 2)


            // =================================================================
            // 2. PROPRIETÀ E ACCESSO AI DATI
            // =================================================================
            Console.WriteLine("--- Proprietà e Accesso ---");

            // La proprietà .Length restituisce il numero 
            // totale di elementi dentro l'array (3)
            Console.WriteLine($"Lunghezza array nomi: {nomi.Length}");
            
            // Lettura: Estraiamo l'elemento all'indice 2 
            // (ovvero il terzo elemento -> "Luca")
            Console.WriteLine($"Elemento in posizione 2: {nomi[2]}");


            // =================================================================
            // 3. MODIFICA DI UN ELEMENTO
            // =================================================================
            Console.WriteLine("\n--- Modifica Elemento ---");

            // Gli array sono modificabili: possiamo 
            // sovrascrivere un valore esistente.
            // Cambiamo l'elemento all'indice 1 ("Marco") con "Edoardo".
            nomi[1] = "Edoardo";
            Console.WriteLine($"Nuovo elemento in posizione 1: {nomi[1]}");


            // =================================================================
            // 4. SCORRIMENTO COMPLETO (Iterazione)
            // =================================================================
            Console.WriteLine("\n--- Elenco Nomi Aggiornato ---");

            // Il foreach è perfetto per 
            // visualizzare a cascata tutto il contenuto
            foreach (string nome in nomi) {
                Console.WriteLine(nome);
            }
        }
    }
}