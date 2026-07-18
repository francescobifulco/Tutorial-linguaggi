using System;


namespace Lezione29{
    public class Persona1{
        public string nome;
        public string cognome;
        public int eta;
        public Persona1(string nome, string cognome, int eta) {
            this.nome = nome;
            this.cognome = cognome;
            this.eta = eta;
        }
        public void saluta() {
            Console.WriteLine($"Ciao sono {nome}");
        }
    }
}