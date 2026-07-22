using System;

namespace PersonaPencipale {
    public class InsegnanteInterfacce : IEquatable<InsegnanteInterfacce> {
        public string materia;
        public string nome;
        public string cognome;
        public int eta;

        public InsegnanteInterfacce(string nome, string cognome, int eta, string materia) {
            this.nome = nome;
            this.cognome = cognome;
            this.eta = eta;
            this.materia = materia;
        }

        public void insegna() {
            Console.WriteLine($"Il docente {cognome} sta spiegando una lezione di {materia}.");
        }

        public void saluta() {
            Console.WriteLine("Buongiorno ragazzi");
        }

        // Implementazione di IEquatable<InsegnanteInterfacce>
        public bool Equals(InsegnanteInterfacce insegnanteInterfacce) {
            if (insegnanteInterfacce == null) return false;

            return this.nome == insegnanteInterfacce.nome && this.cognome == insegnanteInterfacce.cognome;
        }
    }
}