using System;
using System.Collections;
using System.Collections.Generic;

namespace Lezione24{
    public class Lezione24__dictinary_dict{
        static void Main(string[] args){

            // Creazione di un dizionario vuoto che accetta SOLO Chiavi stringa e Valori stringa
            Dictionary<string, string> prova = new Dictionary<string, string>();

            Dictionary<string, string> prova2 = new Dictionary<string, string>(){
                { "Lombardia", "Milano" },
                { "Linguria", "Genova" },
                { "Piemonte", "Torino" }
            };

            prova2.Add("Veneto", "Venezia");

            // Sovrascrittura del valore associato alla chiave "Veneto" -> Diventa "Palermo"
            prova2["Veneto"] = "Palermo";

            // Rimozione della coppia con chiave "Veneto"
            prova2.Remove("Veneto");

            // .Clear() svuota completamente il dizionario, eliminando OGNI elemento presente al suo interno.
            // NOTA LOGICA: Poiché svuoti qui il dizionario, i controlli e i cicli successivi 
            // lavoreranno su un dizionario totalmente vuoto!
            prova2.Clear();

            // Entrambi stamperanno 'False' perché il dizionario è stato appena svuotato con .Clear()
            Console.WriteLine($"Contiene chiave 'Veneto'?: {prova2.ContainsKey("Veneto")}");
            Console.WriteLine($"Contiene valore 'Milano'?: {prova2.ContainsValue("Milano")}");

            // =================================================================
            // SCORRIMENTO DEL DIZIONARIO
            // =================================================================
            Console.WriteLine("\n--- Primo ciclo (var) ---");
            // Usando 'var', C# capisce da solo che ogni elemento è un KeyValuePair<string, string>
            // NB: Non stamperà nulla a schermo perché il dizionario è vuoto a causa del .Clear() precedente
            foreach (var citta in prova2){
                // Questo stampa direttamente la coppia formattata come: [Chiave, Valore]
                Console.WriteLine(citta);
            }

            Console.WriteLine("\n--- Secondo ciclo (KeyValuePair) ---");
            // Questo è il modo esplicito e formale per scorrere un Dizionario.
            // Ti permette di isolare ed estrarre la chiave e il valore in modo pulito e sicuro.
            foreach (KeyValuePair<string, string> citta in prova2){
                Console.WriteLine($"Capoluogo: {citta.Value}");
                Console.WriteLine($"Regione: {citta.Key}");
            }
        }
    }
}