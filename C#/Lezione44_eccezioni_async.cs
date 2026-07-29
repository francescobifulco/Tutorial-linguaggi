using System;
using System.Threading.Tasks;

namespace Lezione44 {
    public class Lezione44_eccezioni_async {
        static async Task Main(string[] args) {
            
            Console.WriteLine("--- 1. GESTIONE BASE DI UN'ECCEZIONE IN UN METODO ASYNC ---");

            try {
                // Quando usiamo 'await', l'eccezione lanciata dentro il metodo asincrono
                // viene "spacchettata" e catturata dal blocco catch standard!
                string risultato = await ScaricaDatiSitoWebAsync("https://sito-inesistente-12345.com");
                Console.WriteLine(risultato);
            } 
            catch (Exception ex) {
                Console.WriteLine($"[CATTURATA]: {ex.Message}");
            }


            Console.WriteLine("\n--- 2. ECCEZIONI IN TASK MULTIPLI (Task.WhenAll e AggregateException) ---");

            // Creiamo tre task asincroni, di cui due lanceranno un'eccezione
            Task task1 = OperazioneRischiosaAsync("Task 1 (OK)", dovrebbeFallire: false);
            Task task2 = OperazioneRischiosaAsync("Task 2 (Errore A)", dovrebbeFallire: true);
            Task task3 = OperazioneRischiosaAsync("Task 3 (Errore B)", dovrebbeFallire: true);

            Task tuttiITask = Task.WhenAll(task1, task2, task3);

            try {
                // Usando await su WhenAll, catturiamo solo la PRIMA eccezione sollevata
                await tuttiITask;
            } 
            catch (Exception ex) {
                Console.WriteLine($"[AWAIT CATTURA SOLO IL PRIMO ERRORE]: {ex.Message}");
            }

            // Se invece vogliamo accedere a TUTTE le eccezioni generate dai task in parallelo:
            if (tuttiITask.Exception != null) {
                Console.WriteLine("\n[ANALISI DI TUTTI GLI ERRORI CON AggregateException]:");
                
                // AggregateException contiene l'elenco completo (InnerExceptions)
                foreach (var innerEx in tuttiITask.Exception.InnerExceptions) {
                    Console.WriteLine($"  * Dettaglio Errore: {innerEx.Message}");
                }
            }
        }

        // --- METODI ASINCRONI DI SUPPORTO ---

        private static async Task<string> ScaricaDatiSitoWebAsync(string url) {
            await Task.Delay(1000); // Simula la richiesta di rete
            
            // Simuliiamo un errore di connessione lanciando un'eccezione
            throw new InvalidOperationException($"Impossibile connettersi al server remoto '{url}'.");
        }

        private static async Task OperazioneRischiosaAsync(string nomeTask, bool dovrebbeFallire) {
            await Task.Delay(500);

            if (dovrebbeFallire) {
                throw new Exception($"Fallimento critico durante l'esecuzione di {nomeTask}");
            }

            Console.WriteLine($"  -> {nomeTask} completato con successo.");
        }
    }
}