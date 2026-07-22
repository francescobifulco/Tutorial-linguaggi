using System;
using PersonaPencipale;

namespace PersonaPencipale{
    public class InsegnanteBallo: Insegnante{
        public string canzonePreferita;
        public InsegnanteBallo(string nome, string cognome, int eta, string materia, string canzonePreferita): base(nome, cognome, eta, materia){
            this.canzonePreferita = canzonePreferita;
        }
        public void balla() {
            Console.WriteLine($"{nome} sta ballando sulle note di '{canzonePreferita}'!");
        }
    }
}
