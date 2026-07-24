using System;
using PersonaPencipale;

namespace PersonaPencipale {
    public class InsegnanteAstratto : PersonaAstratta {
        public string materia;
        
        // Override della proprietà astratta
        public override int eta { get; set; }

        // Costruttore che accetta anche l'età
        public InsegnanteAstratto(string nome, string cognome, int eta, string materia) : base(nome, cognome) {
            this.eta = eta;
            this.materia = materia;
        }

        public override void salutaAstratta() {
            Console.WriteLine($"Buongiorno ragazzi, sono {nome} {cognome} ({eta} anni) e insegno {materia}.");
        }
    }
}