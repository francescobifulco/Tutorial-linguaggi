using System.Collections; // Fondamentale! Contiene l'ArrayList
using System;

namespace Lezione21 {
    public class Lezione21_arrayLista { 
        static void Main(string[] args) {

            int[] arrayInteri = {1, 2, 3 ,4, 5, 6, 7};

            // Un ArrayList può contenere qualsiasi tipo di 
            // dato CONTEMPORANEAMENTE
            ArrayList arrayList = new ArrayList(){
                4, true, 5.6, null, 3
            };

            ArrayList prova = new ArrayList();
            prova.Add(2);        // Indice 0
            prova.Add("prova");  // Indice 1

            ArrayList prova2 = new ArrayList(){
                3, "prova3", true, 4.3, null
            };

            // Stampa l'elemento all'indice 3 di prova2 -> 4.3
            Console.WriteLine($"Elemento prova2[3]: {prova2[3]}");

            // .AddRange inserisce un'intera collezione alla fine dell'ArrayList
            prova.AddRange(arrayInteri); 
            // Ora 'prova' contiene: [2, "prova", 1, 2, 3, 4, 5, 6, 7]
            Console.WriteLine($"Elemento prova[5]: {prova[5]}"); // Stampa 4

            prova.AddRange(arrayList);
            // Ora 'prova' contiene anche gli elementi di arrayList
            Console.WriteLine($"Elemento prova[2]: {prova[2]}"); // Stampa 1

            // .Insert inserisce un elemento in una posizione specifica, "slittando" gli altri a destra
            prova.Insert(0, "ciao"); // "ciao" diventa l'indice 0
            Console.WriteLine($"Dopo Insert(0): {prova[0]}"); // Stampa "ciao"

            // Sovrascrittura classica tramite indice
            prova[0] = "Buona sera";
            Console.WriteLine($"Dopo modifica [0]: {prova[0]}"); // Stampa "Buona sera"

            // =================================================================
            // RIMOZIONI (Fai attenzione a come cambia la lista!)
            // prima di queste righe 'prova' è: ["Buona sera", 2, "prova", 1, 2, 3, 4, 5, 6, 7, 4, true, 5.6, null, 3]
            // =================================================================
            
            prova.Remove(3);     // Rimuove il primo VALORE uguale a 3 trovato nella lista
            prova.RemoveAt(5);   // Rimuove l'elemento che si trova FISICAMENTE all'indice 5
            prova.RemoveRange(0, 2); // Rimuove 2 elementi partendo dall'indice 0

            // .Contains verifica se un elemento è presente (Ritorna True o False)
            Console.WriteLine($"La lista contiene il numero 5?: {prova.Contains(5)}");

            // =================================================================
            // SCORRIMENTO DELLA LISTA
            // =================================================================
            Console.WriteLine("\n--- Scorrimento con Foreach ---");
            
            // CORREZIONE: Cambiati i nomi delle variabili per evitare conflitti e refusi
            foreach (var elemento in prova) {
                Console.WriteLine(elemento);
            }

            Console.WriteLine("\n--- Scorrimento con For Classico ---");
            // Nota: Negli ArrayList non si usa .Length ma .Count per sapere la dimensione attuale!
            for (int i = 0; i < prova.Count; i++) {
                 Console.WriteLine($"Indice {i}: {prova[i]}");
            }
            
        }
    }
}