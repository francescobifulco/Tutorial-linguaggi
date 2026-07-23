using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonaPencipale{
    abstract public class PersonaAstratta{
        public string nome;
        public string cognome;
        abstract public int eta {get; set;}
        public PersonaAstratta(string nome, string cognome) {
            this.nome = nome;
            this.cognome = cognome;
        }
        public abstract void salutaAstratta();
        public virtual void respira(){
            Console.WriteLine();
        }

    }
}