using System;
using System.Collections.Generic;
using PersonaPencipale;

namespace Lezione35 {
    public class Lezione35_classe_astratte {
        static void Main(string[] args) {
            
            // Creazione delle istanze di InsegnanteAstratto
            InsegnanteAstratto insegnante1 = new InsegnanteAstratto("Maria", "Esposito", "Storia");
            insegnante1.eta = 40; // Assegnazione della proprietà 'eta' (override della proprietà astratta)

            InsegnanteAstratto insegnante2 = new InsegnanteAstratto("Elisa", "Verdi", "Matematica");
            insegnante2.eta = 34;

            // Chiamata al metodo astratto implementato
            insegnante1.salutaAstratta();
            insegnante2.salutaAstratta();

            // Dimostrazione del polimorfismo con una lista di tipi astratti
            Console.WriteLine("\n--- Uso del Polimorfismo con Liste ---");
            List<PersonaAstratta> personeAstratte = new List<PersonaAstratta> {
                insegnante1,
                insegnante2
            };

            foreach (PersonaAstratta p in personeAstratte) {
                p.salutaAstratta(); // C# sa esattamente quale versione eseguire!
            }
        }
    }
}