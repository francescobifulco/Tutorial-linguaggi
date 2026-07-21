using System;
using Lezione30Class;

namespace Lezione30 {
    public class Lezione30_static {
        static void Main(string[] args) {
            
            // Creiamo 3 istanze distinte
            PersonaLezione30 persona1 = new PersonaLezione30("Luca", "Rossi", 25);
            PersonaLezione30 persona2 = new PersonaLezione30("Marco", "Verdi", 25);
            PersonaLezione30 persona3 = new PersonaLezione30("Anna", "Neri", 25);

            // CORREZIONE: Usiamo la Property o il GetNome() per accedere al campo privato 'nome'
            Console.WriteLine(persona1.Nome);
            Console.WriteLine(persona2.GetNome());
            Console.WriteLine(persona3.Nome);

            Console.WriteLine("\n--- Uso di membri STATIC ---");
            
            // L'accesso al campo statico avviene tramite il NOME DELLA CLASSE, non dell'oggetto!
            Console.WriteLine($"Numero totale di persone create: {PersonaLezione30.numeroPersone}");

            // Chiamata a un metodo statico direttamente dalla classe
            PersonaLezione30.SalutaStatico("Marco");
        }
    }
}