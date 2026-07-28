using System;
using System.Threading;
using System.Threading.Tasks; // FONDAMENTALE: Namespace per lavorare con Task e Multithreading

namespace Lezione42 {
    public class Lezione42_task {
        
        // Eseguiamo il Main in modo asincrono cambiando la firma in 'static async Task'
        static async Task Main(string[] args) {
            
            Console.WriteLine("--- 1. TASK SEMPLICE SENZA RITORNO (Task) ---");

            Console.WriteLine("[Main] Inizio scaricamento file...");
            
            // Task.Run avvia un'operazione su un thread secondario in background
            Task taskScarica = Task.Run(() => {
                Console.WriteLine("  [Background] Simulazione download in corso...");
                Thread.Sleep(2000); // Simula un'attesa di 2 secondi (operazione pesante)
                Console.WriteLine("  [Background] Download completato!");
            });

            Console.WriteLine("[Main] Il programma principale NON si è bloccato e continua a lavorare!");

            // 'await' fa attendere il completamento del Task prima di proseguire, senza bloccare il sistema
            await taskScarica;


            Console.WriteLine("\n--- 2. TASK CON VALORE DI RITORNO (Task<T>) ---");

            Console.WriteLine("[Main] Richiesta calcolo pesante in corso...");

            // Task<int> indica che l'operazione in background restituirà un numero intero
            Task<int> taskCalcolo = Task.Run(() => CalcolaSommaComplessa(10, 20));

            Console.WriteLine("[Main] Sto facendo altre operazioni mentre attendo il risultato...");

            // 'await' attende la fine del Task ed estrae direttamente il valore di ritorno (int)
            int risultato = await taskCalcolo;
            Console.WriteLine($"[Main] Risultato ricevuto dal Task: {risultato}");


            Console.WriteLine("\n--- 3. ESECUZIONE DI PIÙ TASK IN PARALLELO ---");

            Console.WriteLine("[Main] Avvio di 3 compiti in parallelo...");

            Task task1 = Task.Run(() => { Thread.Sleep(1000); Console.WriteLine("  -> Task 1 finito (1s)"); });
            Task task2 = Task.Run(() => { Thread.Sleep(1500); Console.WriteLine("  -> Task 2 finito (1.5s)"); });
            Task task3 = Task.Run(() => { Thread.Sleep(500);  Console.WriteLine("  -> Task 3 finito (0.5s)"); });

            // Task.WhenAll attende che TUTTI i task nella lista siano stati completati
            await Task.WhenAll(task1, task2, task3);

            Console.WriteLine("[Main] Tutti i task in parallelo sono terminati con successo!");
        }

        // Metodo helper che simula un calcolo lungo
        private static int CalcolaSommaComplessa(int a, int b) {
            Thread.Sleep(1500); // Simula il calcolo
            return a + b;
        }
    }
}