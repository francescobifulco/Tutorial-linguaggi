using System;

namespace Lezione2_variabili_costanti{
    class Program{
        static void Main(string[] args){

            // --- DICHIARAZIONE E INIZIALIZZAZIONE ---
            
            // Dichiarazione e inizializzazione simultanea di una variabile di tipo stringa (testo).
            // Le variabili possono cambiare il loro valore durante l'esecuzione del programma.
            string nome = "Luca";
            
            // Dichiarazione di una COSTANTE di tipo intero (numero).
            // Il valore di una "const" deve essere assegnato subito e NON può più essere modificato.
            const int eta = 25;
            
            // Dichiarazione di una variabile di tipo stringa senza assegnarle un valore immediato.
            string cognome;
            
            // Assegnazione del valore alla variabile "cognome" in un secondo momento.
            cognome = "Rossi";


            // --- STAMPE SULLA CONSOLE (OTTIMIZZATE) ---
            
            // 1. Concatenazione classica usando l'operatore +
            Console.WriteLine("Ciao, io sono " + nome + " " + cognome + ".");
            
            // 2. Uso della variabile costante 'eta' nella stampa
            Console.WriteLine("Ho " + eta + " anni.");
            
            // 3. Altro esempio di testo combinato con la variabile 'nome'
            Console.WriteLine(nome + " è il mio nome.");
            
            // 4. Utilizzo della String Interpolation (il simbolo $ prima delle virgolette).
            // Permette di inserire le variabili direttamente dentro il testo tra parentesi graffe { }, 
            // rendendo la scrittura molto più pulita ed evitando continui segni "+".
            Console.WriteLine($"Ho veramente {eta} anni.");
            Console.Read();
        }
    }
}