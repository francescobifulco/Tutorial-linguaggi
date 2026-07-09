using System;

namespace Lezione8 {
    public class Lezione8_try_catch_gestione_eccezioni {
        static void Main(string[] args) {
            
            Console.Write("Inserisci il primo numero: ");
            string input1 = Console.ReadLine();

            // Dichiariamo e inizializziamo num1 fuori dal try, altrimenti 
            // non sarebbe accessibile al di fuori delle 
            // parentesi graffe del try stesso.
            int num1 = 0;
            
            // -----------------------------------------------------------------
            // IL BLOCCO TRY-CATCH-FINALLY
            // -----------------------------------------------------------------
            // Immaginalo come un percorso protetto. Il programma 
            // prova a eseguire il codice.
            // Se incontra un errore, salta immediatamente al 
            // "catch" corrispondente.
            try{
                // Se l'utente inserisce "ciao", questa riga 
                // fallisce ed emette una FormatException.
                // Se l'utente inserisce 9999999999999, 
                // fallisce ed emette una OverflowException.
                num1 = int.Parse(input1);
            }
            // 1. Cattura l'errore se l'input non è un numero 
            // (es. lettere, simboli)
            catch (FormatException){
                Console.WriteLine("[ERRORE] Formato non valido: devi inserire caratteri numerici.");
            }
            // 2. Cattura l'errore se il numero è troppo grande o 
            // troppo piccolo per un tipo 'int' 
            // (Ricorda: l'int va da circa -2 miliardi a +2 miliardi).
            catch (OverflowException){
                Console.WriteLine("[ERRORE] Numero troppo grande o piccolo per un intero standard (int).");
            }
            // 3. Cattura l'errore se il valore passato è 'null' 
            // (improbabile da Console.ReadLine, ma ottima pratica)
            catch (ArgumentNullException){
                Console.WriteLine("[ERRORE] Non hai passato alcun argomento (valore nullo).");
            }
            // 4. Il blocco finally è OPZIONALE. 
            // Viene eseguito SEMPRE, sia se il codice nel 
            // try va a buon fine, sia se viene catturato un errore.
            // Spesso si usa per liberare risorse 
            // (es. chiudere file aperti o connessioni al database).
            finally{
                Console.WriteLine("-> Blocco 'finally' eseguito (avviene in ogni caso).");
            }

            // -----------------------------------------------------------------
            // PROSEGUIMENTO DEL PROGRAMMA
            // -----------------------------------------------------------------
            Console.WriteLine("\n--- Output Finale ---");
            
            // Se il parsing è fallito, num1 è rimasto a 
            // 0 (il valore iniziale), 
            // ma il programma NON è andato in crash! 
            // Continua a girare tranquillamente.
            Console.WriteLine($"Il valore finale di num1 + 2 è: {num1 + 2}");

        }
    }
}