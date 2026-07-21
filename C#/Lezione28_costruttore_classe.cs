using System;
using PersonaPencipale;

namespace Lezione28{
    public class Lezione28_costruttore_classe{
        static void Main(string[] args){

            // Sfrutta il costruttore a 3 parametri (Nome, Cognome, Età)
            Persona pers1 = new Persona("Marco", "Neri", 25);
            
            // Sfrutta lo STESSO costruttore a 3 parametri
            Persona pers2 = new Persona("Luca", "Rossi", 7);
            
            // Esperimento 1: Usiamo il costruttore che accetta solo Cognome ed Età
            Persona pers3 = new Persona("Verdi", 40);
            
            // Esperimento 2: Usiamo il costruttore vuoto (di default)
            Persona pers4 = new Persona();
            pers4.nome = "Anna"; // Devo assegnarlo dopo perché il costruttore vuoto non fa nulla

            // Chiamata ai metodi
            pers1.saluta();  // Stampa: Ciao sono Marco
            pers2.saluta1(); // Stampa: Ciao sono Luca
            
            Console.WriteLine("\n--- Cosa succede a chi non ha un nome? ---");
            pers3.saluta();  // Stampa: Ciao sono  (perché il nome è null!)

            Console.WriteLine("\n--- Dati degli oggetti ---");
            Console.WriteLine($"pers1 -> Nome: {pers1.nome}, Cognome: {pers1.cognome}, Età: {pers1.eta}");
            Console.WriteLine($"pers2 -> Nome: {pers2.nome}, Cognome: {pers2.cognome}, Età: {pers2.eta}");
            Console.WriteLine($"pers3 -> Nome: {pers3.nome}, Cognome: {pers3.cognome}, Età: {pers3.eta}");
            Console.WriteLine($"pers4 -> Nome: {pers4.nome}, Cognome: {pers4.cognome}, Età: {pers4.eta}");
        }
    }
}