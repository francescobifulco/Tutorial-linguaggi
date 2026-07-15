using System;
using System.Collections;
using System.Collections.Generic;

namespace Lezione27 {
    public class Lezione27_programmazione_oggetti_oop {
        static void Main(string[] args) {
            
            // Istanziazione: stai creando un OGGETTO concreto (pers1) partendo dal MODELLO (Classe Persona)
            Persona pers1 = new Persona();
            
            // Assegnazione del valore al campo pubblico dell'oggetto
            pers1.nome = "Marco";
            
            // Chiamata ai metodi dell'oggetto
            pers1.saluta();  // Stampa: Ciao sono Marco
            pers1.saluta1(); // Stampa: Ciao sono Marco
        }
    }

  // Il Progetto / Stampo base
    class Persona {
        // Campo (Field): la caratteristica che ogni Persona creata avrà
        public string nome;
        
        // Metodo 1: Accesso implicito al campo della classe
        public void saluta() {
            // C# capisce da solo che "nome" si riferisce alla variabile dichiarata sopra nella classe
            Console.WriteLine($"Ciao sono {nome}");
        }
        
        // Metodo 2: Accesso esplicito tramite la keyword 'this'
        public void saluta1() {
            // 'this' significa letteralmente "questa specifica istanza di Persona che sta eseguendo il metodo in questo momento"
            Console.WriteLine($"Ciao sono {this.nome}");
        }
    }
}
