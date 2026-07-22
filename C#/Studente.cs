using System;

namespace PersonaPencipale{
    // La classe Studente erredita da Persona (Studente IS-A Persona)
    // Implementa l'interfaccia generica IEquatable<Studente>
    public class Studente : Persona, IEquatable<Studente>{
        // Proprietà specifica dello Studente
        public string classe;

        // Il costruttore riceve tutti i parametri e passa nome, cognome ed età alla classe padre con 'base(...)'
        public Studente(string nome, string cognome, int eta, string classe) : base(nome, cognome, eta){
            this.classe = classe; // Assegna la proprietà specifica
        }
        // Metodo specifico della classe Studente
        public void studia(){
            Console.WriteLine($"{nome} sta studiando per i compiti della classe {classe}...");
        }
        // 'override' del metodo saluta() per studente
        public override void saluta(){
            base.saluta();
            Console.WriteLine("Buongiorno prof");
        }
        // Implementazione obbligatoria dell'interfaccia IEquatable<Studente>
        public bool Equals(Studente studente) {
            // Se l'altro oggetto è null, non possono essere uguali
            if (studente == null) return false;

            // Definiamo che due studenti sono "uguali" se hanno lo stesso nome (o stesso nome e cognome)
            return this.nome == studente.nome && this.cognome == studente.cognome;
        }
    }
}