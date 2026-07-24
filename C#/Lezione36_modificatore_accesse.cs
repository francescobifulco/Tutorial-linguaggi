using System;
using PersonaPencipale;

namespace Lezione36 {
    public class Lezione36_modificatore_accesse {
        static void Main(string[] args){
            
            Persona persona1 = new Persona("Luca", "Rossi", 23);
            
            persona1.balla();
            persona1.saluta();
            
        }
    }
}