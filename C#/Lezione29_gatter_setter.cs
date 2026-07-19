using System;
using Lezione29Class;

namespace Lezione29 {
    public class Lezione29_gatter_setter {
        static void Main(string[] args) {
            
            Persona1 pers = new Persona1();
            
            // Usiamo i METODI classici (richiedono le parentesi tonde)
            pers.SetNome("Marco"); 
            Console.WriteLine($"Nome preso dal metodo: {pers.GetNome()}");

            // Usiamo la PROPRIETÀ nativa di C# (si usa come una normale variabile!)
            pers.Nome = "Anna"; // Chiama il 'set' di Nome
            Console.WriteLine($"Nome preso dalla Property: {pers.Nome}"); // Chiama il 'get' di Nome
            
            // Test del controllo sull'età che hai programmato
            Console.WriteLine("\n--- Test controllo età ---");
            pers.SetEta(-5); // Stamperà l'errore a schermo!
            
            Console.ReadLine();
        }
    }
}