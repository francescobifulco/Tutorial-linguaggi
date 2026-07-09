using System;

namespace Lezione7 {
    public class Lezione7_input_utenti {
        static void Main(string[] args){

            // --- INPUT DEL PRIMO NUMERO ---
            Console.Write("Inserisci il primo numero: ");
            // Usiamo Console.Write (invece di WriteLine) così 
            // l'utente digita il numero 
            // sulla stessa riga, rendendo l'interfaccia nel 
            // terminale più pulita.

            // Console.ReadLine() ferma il programma e aspetta 
            // che l'utente scriva qualcosa e prema INVIO.
            // Restituisce SEMPRE un tipo di dato 'string'.
            string numero1 = Console.ReadLine();

            // --- INPUT DEL SECONDO NUMERO ---
            Console.Write("Inserisci il secondo numero: ");
            string numero2 = Console.ReadLine();

            Console.WriteLine("\n--- Elaborazione Dati ---");

            // --- CONVERSIONE (PARSING) ---
            // Convertiamo le stringhe digitate 
            // dall'utente in veri numeri interi.
            // ATTENZIONE: Se l'utente scrive delle 
            // lettere (es. "ciao") invece di un numero, 
            // il programma andrà in crash su queste righe 
            // (genera un'eccezione FormatException).
            int num1 = int.Parse(numero1);
            int num2 = int.Parse(numero2);

            // --- CALCOLO E OUTPUT ---
            int risultato = num1 + num2;
            
            // Stampiamo un riepilogo chiaro usando la String Interpolation
            Console.WriteLine($"Hai inserito i numeri: {num1} e {num2}");
            Console.WriteLine($"Il risultato della somma è: {risultato}");

            Console.Read();
        }
    }
}