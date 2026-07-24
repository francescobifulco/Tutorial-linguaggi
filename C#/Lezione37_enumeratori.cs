using System;

namespace Lezione37 {
    public class Lezione37_enumeratori {
        
        // Definizione di un enumeratore (enum) per i mesi dell'anno.
        // Assegnando "Gennaio = 1", i mesi successivi incrementano automaticamente (Febbraio = 2, Marzo = 3, ecc.)
        enum Mesi {
            Gennaio = 1, Febbraio, Marzo, Aprile, Maggio, Giugno,
            Luglio, Agosto, Settembre, Ottobre, Novembre, Dicembre
        }

        static void Main(string[] args) {
            
            // Stampa direttamente il nome testuale associato alla costante dell'enum
            Console.WriteLine(Mesi.Febbraio); // Output: Febbraio

            // Effettua il casting esplicito dell'enum al suo valore numerico intero corrispondente
            Console.WriteLine((int)Mesi.Maggio); // Output: 5

            // Dichiara una variabile di tipo Mesi e una variabile intera con il valore convertito
            Mesi meseNascita = Mesi.Gennaio;
            int mese = (int)Mesi.Gennaio;

            // Esegue un confronto booleano: verifica se il valore numerico di Gennaio (1) è uguale a 9
            Console.WriteLine((int)meseNascita == 9); // Output: False

            // Costrutto switch per gestire diversi casi basati sul valore dell'enum
            switch (meseNascita) {
                case Mesi.Maggio:
                     Console.WriteLine("Siamo in primavera");
                     break;
                case Mesi.Luglio:
                     Console.WriteLine("Siamo in estate");
                     break;
                // Nota: poiché Gennaio non rientra nei case sopra, lo switch viene saltato senza errori
            }
        }
    }
}