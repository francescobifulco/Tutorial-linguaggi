using System;
using PersonaPencipale;

namespace Lezione33 {
    public class Lezione33_interfacce {
        static void Main(string[] args) {
            Studente studente1 = new Studente("Luca", "Rossi", 17, "4A");
            Studente studente2 = new Studente("Luca", "Verdi", 18, "5B");
            Studente studente3 = new Studente("Marco", "Bianchi", 17, "4A");

            // Parametri corretti: Nome, Cognome, Età, Materia
            InsegnanteInterfacce insegnante1 = new InsegnanteInterfacce("Anna", "Neri", 45, "Storia");
            InsegnanteInterfacce insegnante2 = new InsegnanteInterfacce("Anna", "Neri", 50, "Matematica");

            Console.WriteLine("--- TEST EQUATABLE STUDENTE ---");
            // Confronta studente1 ("Luca") con studente2 ("Luca") -> restituisce True
            Console.WriteLine($"studente1 e studente2 sono uguali? {studente1.Equals(studente2)}"); 
            
            // Confronta studente1 ("Luca") con studente3 ("Marco") -> restituisce False
            Console.WriteLine($"studente1 e studente3 sono uguali? {studente1.Equals(studente3)}");

            Console.WriteLine("\n--- TEST EQUATABLE INSEGNANTE ---");
            // Confronta i due insegnanti con lo stesso nome e cognome -> restituisce True
            Console.WriteLine($"insegnante1 e insegnante2 sono uguali? {insegnante1.Equals(insegnante2)}");
        }
    }
}