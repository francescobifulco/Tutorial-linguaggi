using System;
using PersonaPencipale; // Importa il namespace dove sono definite le nostre classi

namespace Lezione31 {
    public class Lezione31_ereditarieta {
        static void Main(string[] args) {
            // Creazione di un oggetto Studente
            Studente studente1 = new Studente("Luca", "Rossi", 17, "4A");
            
            // Creazione di un oggetto Insegnante
            Insegnante insegnante1 = new Insegnante("Anna", "Neri", 44, "Matematica");

            // Chiamata ai metodi di saluta (eseguiranno la versione 'override' di ciascun oggetto)
            studente1.saluta();
            insegnante1.saluta();

            Console.WriteLine(); // Riga vuota per spaziare l'output

            // Chiamata ai metodi specifici
            studente1.studia();
            insegnante1.insegna();
        }
    }
}