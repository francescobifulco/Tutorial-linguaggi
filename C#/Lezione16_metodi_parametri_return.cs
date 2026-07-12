using System;

namespace Lezione16 {
    public class Lezione16_metodi_parametri_return { 
        static void Main(string[] args) {
            
            // 1. Chiamata a metodo classico con un parametro obbligatorio
            saluta("Marco");

            // 2. Chiamata a metodo senza parametri
            saluta1();

            // 3. Chiamata classica passando i parametri nello stesso 
            // ordine in cui sono definiti
            saluta2("Luca", 0);

            // 4. ARGOMENTI NOMINATI (Named Arguments):
            // Specificando il nome del parametro col simbolo ':', 
            // puoi invertire l'ordine dei fattori!
            // C# capisce al volo dove inserire i valori a 
            // prescindere dalla posizione.
            saluta2(orario: 2, nome: "Valerio");

            // 5. PARAMETRI OPZIONALI (Optional Parameters):
            // Non passiamo il secondo argomento ('orario'). 
            // C# userà automaticamente il valore di default (0).
            saluta3("Mirco");

            // 6. METODO CON VALORE DI RITORNO:
            // Il metodo calcola la somma e ci "restituisce" 
            // un intero, che salviamo nella variabile 'risultato'.
            int risultato = faiSomma(10, 20);
            Console.WriteLine($"Il risultato della somma è: {risultato}");

        }

        // =============================================================================
        // DEFINIZIONE DEI METODI (Struttura: modificatore_accesso static tipo_ritorno Nome)
        // =============================================================================

        // Metodo VOID: non restituisce dati, esegue solo le istruzioni interne.
        static void saluta(string nome){
            Console.WriteLine($"Ciao {nome}");
        }

        // Metodo senza parametri di input
        static void saluta1(){
            Console.WriteLine("Caio");
        }

        // Metodo con parametri multipli obbligatori
        static void saluta2(string nome, int orario){
            switch (orario){
                case 0:
                    Console.WriteLine($"Ciao {nome}, buongiorno");
                    break;
                case 1:
                    Console.WriteLine($"Ciao {nome}, buon pomeriggio");
                    break;
                case 2:
                    Console.WriteLine($"Ciao {nome}, buona sera");
                    break;
            }
        }

        // Metodo con parametro opzionale ('int orario = 0').
        // I parametri opzionali devono sempre essere 
        // posizionati in fondo, DOPO quelli obbligatori.
        static void saluta3(string nome, int orario = 0){
            switch (orario){
                case 0:
                    Console.WriteLine($"Ciao {nome}, buongiorno");
                    break;
                case 1:
                    Console.WriteLine($"Ciao {nome}, buon pomeriggio");
                    break;
                case 2:
                    Console.WriteLine($"Ciao {nome}, buona sera");
                    break;
            }
        }
        
        // Metodo con RITORNO (int): promette di restituire un numero intero a chiunque lo chiami.
        static int faiSomma(int num1, int num2) {
            int somma = num1 + num2;
            
            // La parola chiave 'return' interrompe il metodo e spedisce il valore al mittente.
            return somma; 
        }
    }
}