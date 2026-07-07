// "using" serve a importare un "namespace" (una libreria di codice).
// In questo caso, importiamo il namespace di base "System", che contiene 
// le classi fondamentali per gestire l'input e l'output (come Console).
using System;

// Il "namespace" è come un grande contenitore o una cartella utilizzato 
// per organizzare il codice e raggruppare le classi correlate, evitando conflitti di nomi.
namespace Lezione1
{
    // Una "class" (classe) è il mattone fondamentale della programmazione orientata agli oggetti.
    // Tutto il codice eseguibile in C# deve trovarsi all'interno di una classe.
    class Lezione1_sintassi
    {
        // "Main" è il punto di partenza (entry point) di qualsiasi applicazione C#.
        // Quando avvii il programma, il computer cerca questa riga ed esegue il codice al suo interno.
        // - "static": significa che il metodo appartiene alla classe stessa e non a un oggetto specifico.
        // - "void": indica che questo metodo esegue delle azioni ma non restituisce alcun valore.
        // - "string[] args": permette al programma di ricevere parametri esterni al momento dell'avvio.
        static void Main(string[] args)
        {
            // "Console.WriteLine" è un'istruzione che ordina al computer di stampare a schermo 
            // il testo racchiuso tra le virgolette, andando poi a capo automaticamente.
            Console.WriteLine("Ciao mondo prova 1");

            // "Console.Read" mette il programma in attesa che l'utente prema un tasto.
            // Spesso si usa alla fine per evitare che la finestra del terminale si chiuda 
            // istantaneamente, permettendoti di leggere il risultato.
            Console.Read();
        }
    }
}