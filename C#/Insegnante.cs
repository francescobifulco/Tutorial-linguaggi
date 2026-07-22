using System;

namespace PersonaPencipale {
    // La classe Insegnante eredita da Persona
    public class Insegnante : Persona {
        // Proprietà specifica dell'Insegnante
        public string materia;

        // Costruttore: passa i dati generali a Persona e salva la materia
        public Insegnante(string nome, string cognome, int eta, string materia) : base(nome, cognome, eta) {
            this.materia = materia;
        }
        // Metodo specifico della classe Insegnante
        public void insegna() {
            Console.WriteLine($"Il docente {cognome} sta spiegando una lezione di {materia}.");
        }
        // sealed override = "Personalizzo saluta(), ma blocco chiunque erediti da me"
        public sealed override void saluta(){
            base.saluta();
            Console.WriteLine("Buongiorno ragazzi");
        }
    }
}