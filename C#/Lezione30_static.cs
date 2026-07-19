using System;
using PersonaStatic;

namespace Lezione30 {
    public class Lezione30_static {
        static void Main(string[] args) {
            
            PersonaLezione30 persona1 = new PersonaLezione30("Luca", "Rossi", 25);
            PersonaLezione30 persona2 = new PersonaLezione30("Marco", "Verdi", 25);
            PersonaLezione30 persona3 = new PersonaLezione30("Anna", "Neri", 25);

            Console.WriteLine(persona1.nome);
            Console.WriteLine(persona2.nome);
            Console.WriteLine(persona3.nome);

            Console.WriteLine(persona1.numeroPersone);
        }
    }
}