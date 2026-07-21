using System;


namespace Lezione30Class{
    public class PersonaLezione30{
        private string nome;
        public string cognome;
        public int eta;
        // Membro STATIC: appartiene alla CLASSE, condiviso da tutti gli oggetti
        static public int numeroPersone = 0;
        
        // Metodo STATIC: può essere chiamato direttamente sulla Classe senza fare 'new'
        public static void SalutaStatico(string nomeDaSalutare) {
            Console.WriteLine($"Ciao {nomeDaSalutare}, questo è un saluto da un metodo statico!");
        }

        // Getters e Setters
        public void SetNome(string nome) => this.nome = nome;
        public string GetNome() => this.nome;

        public void SetCognome(string cognome) => this.cognome = cognome;
        public string GetCognome() => this.cognome;

        public void SetEta(int eta) {
            if (eta >= 0) this.eta = eta;
            else Console.WriteLine("Hai messo un'età negativa, imperdonabile!!");
        }
        public int GetEta() => this.eta;

        public string Nome {
            get => this.nome;
            set => this.nome = value;
        }
        public PersonaLezione30(string nome, string cognome, int eta) {
            this.nome = nome;
            this.cognome = cognome;
            this.eta = eta;

            // Incrementiamo il contatore condiviso ogni volta che viene creata una Persona
            PersonaLezione30.numeroPersone++;
        }

        public PersonaLezione30() {
            PersonaLezione30.numeroPersone++;
        }

        public void Saluta() {
            Console.WriteLine($"Ciao sono {nome}");
        }
    }
}