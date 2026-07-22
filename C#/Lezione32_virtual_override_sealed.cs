using System;
using PersonaPencipale;

namespace Lezione32 {
    public class Lezione32_virtual_override_sealed {
        static void Main(string[] args) {
            Studente studente1 = new Studente("Luca", "Rossi", 17, "4A");
            Insegnante insegnante1 = new Insegnante("Anna", "Neri", 44, "Matematica");
            InsegnanteBallo insegnanteBallo1 = new InsegnanteBallo("Marco", "Verdi", 45, "hip hop", "log in - gemini");
            
            insegnante1.saluta();
            studente1.saluta();
            insegnanteBallo1.saluta();
        }
    }
}