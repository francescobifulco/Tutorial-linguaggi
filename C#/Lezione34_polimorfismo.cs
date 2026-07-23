using System;
using PersonaPencipale;
using System.Collections.Generic;

namespace Lezione34 {
    public class Lezione34_polimorfismo {
        static void Main(string[] args) {
            var persone = new List<Persona>{
              new Studente("Luca", "Rossi", 24, "4A"),
              new Insegnante("Anna", "neri", 45, "Storia")  
            };

            // Grazie al POLIMORFISMO, C# capisce a runtime il vero tipo dell'oggetto!
            foreach(Persona persona in persone){
                persona.saluta1();
            }

            Insegnante insegnante1 = new Insegnante("Maria", "Esposito", 40, "Storia");
            Insegnante insegnante2 = new Insegnante("Elisa", "Verdi", 34, "Matematica");

            insegnante1.saluta1();
            insegnante2.saluta1();

        }
    }
}