using System;
using PersonaPencipale;

namespace PersonaPencipale{
    class InsegnanteBallo: Insegnante{
        public string canzonePreferita;
        public InsegnanteBallo(string nome, string cognome, int eta, string materia, string canzonePreferita): base(nome, cognome, eta, materia){
            this.canzonePreferita = canzonePreferita;
        }
        public override void saluta(){
            base.saluta();
            Console.WriteLine("Buongiorno ballerini!");
        }
    }
}
