using System;

namespace Lezione11 {
    public class Lezione11_operatore_ternario {
        static void Main(string[] args) {
            
            string nome;

            // =================================================================
            // 1. APPROCCIO CLASSICO CON IF-ELSE
            // =================================================================
            Console.WriteLine("--- 1. Approccio Classico ---");

            if (5 < 6){
                nome = "Luca";
                Console.WriteLine(nome);
            }else{
                nome = "matteo";
                Console.WriteLine(nome);
            }

            // =================================================================
            // 2. OPERATORE TERNARIO BASE (Struttura: condizione ? se_vero 
            // : se_falso)
            // =================================================================
            Console.WriteLine("\n--- 2. Operatore Ternario Base ---");

            // Questa singola riga sostituisce l'intero blocco 
            // if-else scritto sopra!
            // Se la condizione (5 < 6) è vera, assegna "Luca". 
            // Se è falsa, assegna "Marco".
            nome = 5 < 6 ? "Luca" : "Marco";
            Console.WriteLine(nome);

            // =================================================================
            // 3. OPERATORE TERNARIO ANNIDATO (Nested Ternary)
            // =================================================================
            Console.WriteLine("\n--- 3. Operatore Ternario Annidato ---");

            int numero = 55;

            // CORREZIONE LOGICA DEL TESTO:
            // Primo livello: Il numero è dispari? 
            //   - Se SI (true) -> restituisce "dispari".
            //   - Se NO (false) -> entra nel secondo 
            // operatore ternario tra parentesi.
            // Secondo livello (ramo pari): Il numero è minore di 10?
            //   - Se SI (true) -> "pari minore 10"
            //   - Se NO (false) -> "pari maggiore o uguale a 10"
            nome = numero % 2 != 0 
                ? "dispari" 
                : (numero < 10 ? "pari minore 10" : "pari maggiore o uguale a 10");

            Console.WriteLine($"Il numero {numero} è: {nome}");
        }
    }
}