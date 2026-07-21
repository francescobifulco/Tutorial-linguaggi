using System;


namespace Lezione29Class{
    public class Persona1{
        // Campi privati (Incapsulamento)
        private string nome;
        public string cognome;
        public int eta;
        // ==========================================
        // APPROCCIO 1: METODI GETTER E SETTER (Stile classico)
        // ==========================================
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
        // ==========================================
        // APPROCCIO 2: LE PROPRIETÀ DI C# (Modo corretto e nativo)
        // ==========================================
        public string Nome {
            get => this.nome;
            set => this.nome = value; // 'value' è la parola chiave che contiene il dato in ingresso
        }

        // ==========================================
        // COSTRUTTORI
        // ==========================================
        // Costruttore completo
        public Persona1(string nome, string cognome, int eta) {
            this.nome = nome;
            this.cognome = cognome;
            this.eta = eta;
        }
        public Persona1() { }
        public void saluta() {
            Console.WriteLine($"Ciao sono {nome}");
        }
    }
}