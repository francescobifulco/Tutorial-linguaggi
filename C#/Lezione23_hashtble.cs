using System;
using System.Collections;


namespace Lezione23 {
    public class Lezione23_hashtble { 
        static void Main(string[] args) {
            
            Hashtable prova = new Hashtable();
            
            // Inizializzazione diretta di una Hashtable con 
            // coppie { Chiave, Valore }
            Hashtable prova2 = new Hashtable(){
                { "Lombardia", "Milano" },
                { "Linguria", "Genova" }, 
                { "Piemonte", "Torino" }
            };

            // Aggiunta successiva tramite metodo .Add()
            // Nota: Se provi ad aggiungere una chiave 
            // già esistente, il programma va in crash!
            prova2.Add("Veneto", "Venezia");

            // Lettura del valore associato alla chiave 
            // "Lombardia" -> Stampa "Milano"
            Console.WriteLine($"Capoluogo originale Lombardia: {prova2["Lombardia"]}");
            
            // Sovrascrittura o modifica del valore associato a una chiave esistente
            prova2["Lombardia"] = "Mantova";

            // Rimozione di una coppia partendo dalla sua CHIAVE
            prova2.Remove("Lombardia");

            // =================================================================
            // SCORRIMENTO DELLA HASHTABLE
            // =================================================================
            Console.WriteLine("\n--- Contenuto della Hashtable ---");
            
            // Per scorrere una Hashtable si usa il tipo 'DictionaryEntry'
            foreach (DictionaryEntry citta in prova2) {
                Console.WriteLine($"Chiave (Regione): {citta.Key} | Valore (Capoluogo): {citta.Value}");
            }

            // =================================================================
            // METODI DI VERIFICA (Fai attenzione a cosa cerchi!)
            // =================================================================
            Console.WriteLine("\n--- Verifiche di presenza ---");

            // Ritornerà 'False' perché "Lombardia" 
            // è stata rimossa poche righe sopra con .Remove()
            Console.WriteLine($"La chiave 'Lombardia' esiste ancora?: {prova2.ContainsKey("Lombardia")}");
            
            // Ritornerà 'False' perché "Lombardia" nel tuo 
            // dizionario era una CHIAVE, non un VALORE.
            // I valori dentro la tua Hashtable sono i 
            // capoluoghi ("Genova", "Torino", "Venezia").
            Console.WriteLine($"Il valore 'Lombardia' esiste tra i capoluoghi?: {prova2.ContainsValue("Lombardia")}");
        }
    }
}