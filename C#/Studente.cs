using System;

namespace PersonaPencipale {
    // La classe Studente erredita da Persona (Studente IS-A Persona)
    public class Studente : Persona {
        // Proprietà specifica dello Studente
        public string classe;

        // Il costruttore riceve tutti i parametri e passa nome, cognome ed età alla classe padre con 'base(...)'
        public Studente(string nome, string cognome, int eta, string classe) : base(nome, cognome, eta) {
            this.classe = classe; // Assegna la proprietà specifica
        }
        // Metodo specifico della classe Studente
        public void studia() {
            Console.WriteLine($"{nome} sta studiando per i compiti della classe {classe}...");
        }
        public override void saluta(){
            base.saluta();
            Console.WriteLine("Buongiorno prof");
        }
    }
}