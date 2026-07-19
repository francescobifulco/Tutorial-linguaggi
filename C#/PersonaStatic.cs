using System;


namespace Lezione30Class{
    public class PersonaLezione30{
        private string nome;
        public string cognome;
        public int eta;
        static public int numeroPersone = 0;
        
        public void SetNome(string nome){
            this.nome = nome;
        }
        public void SetCognome(string cognome){
            this.cognome = cognome;
        }
        public void SetEta(int eta){
            if(eta >= 0) this.eta = eta;
            else Console.WriteLine("Hai messo un eta negativa, imperdonabile!!");
        }
        public string GetNome(){
            return this.nome;
        }

        public string GetCognome(){
            return this.cognome;
        }
        public int GetEta(){
            return this.eta;
        }
        public string Nome {
            get => this.nome;
            set => this.nome = value;
        }
        public Persona1(string nome, string cognome, int eta) {
            this.nome = nome;
            this.cognome = cognome;
            this.eta = eta;
            PersonaLezione30.numeroPersone++;
            Console.WriteLine(PersonaLezione30.numeroPersone);
        }
        public Persona1() { }
        public void saluta() {
            Console.WriteLine($"Ciao sono {nome}");
        }
    }
}