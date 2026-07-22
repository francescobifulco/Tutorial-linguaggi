using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonaPencipale{
    public class Persona{
        public string nome;
        public string cognome;
        public int eta;
        
        // Costruttore 1: Completo
        public Persona(string nome, string cognome, int eta) {
            this.nome = nome;
            this.cognome = cognome;
            this.eta = eta;
        }
        
        // Costruttore 2: Solo cognome e età (il nome resterà null di default)
        public Persona(string cognome, int eta) {
            this.cognome = cognome;
            this.eta = eta;
            this.nome = "";
        }
        
        // Costruttore 3: Solo età
        public Persona(int eta) {
            this.eta = eta;
            this.nome = "";
            this.cognome = "";
        }
       
        // Costruttore 4: Vuoto. 
        // IMPORTANTE: Se non scrivi nessun costruttore, C# lo crea da solo in background.
        // Ma se ne crei anche solo uno personalizzato (come quello sopra), il costruttore vuoto 
        // "scompare". Se vuoi continuare a usarlo, devi scriverlo esplicitamente come hai fatto tu!
        public Persona(){
            this.nome = "";
            this.cognome = "";
            this.eta = 0;
        }

        public virtual void saluta() {
            Console.WriteLine($"Ciao sono {nome}");
        }

        public void saluta1() {
            Console.WriteLine($"Ciao sono {this.nome}");
        }
    }
}