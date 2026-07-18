using System;

namespace Lezione29{
    public class Lezione29_gatter_setter{
        static void Main(string[] args){
            
            // Ora il compilatore troverà Persona1 senza problemi!
            Persona1 pers = new Persona1();
            
            // Usiamo il SETTER (passa attraverso la proprietà 'Nome')
            pers.Nome = "Marco";
            
            // Usiamo il GETTER
            Console.WriteLine($"Il nome impostato è: {pers.Nome}");
        }
    }
}