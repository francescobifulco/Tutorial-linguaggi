using System;
using System.Threading.Tasks;

namespace Lezione43 {
    public class Lezione43_async_await {
        
        static async Task Main(string[] args) {
            
            Console.WriteLine("--- 1. FLUSSO ESECUZIONE ASINCRONA ---");
            Console.WriteLine("[Main] Inizio del processo principale...");

            // Chiamata a un metodo asincrono personalizzato
            // Il programma non si blocca: il controllo torna 
            // al chiamante finché non c'è l'await
            Task<string> taskDati = ScaricaDatiDaServerAsync();

            Console.WriteLine("[Main] Faccio altre operazioni locali mentre il server risponde...");
            SimulaLavoroTemporaneo();

            // Ora che ci serve il risultato reale, usiamo 'await'
            string risultato = await taskDati;
            Console.WriteLine($"[Main] Risultato finale ricevuto: '{risultato}'");


            Console.WriteLine("\n--- 2. CONCATENAZIONE DI METODI ASINCRONI (Chain) ---");
            
            // Eseguiamo una sequenza di operazioni asincrone in modo fluido e leggibile
            bool successo = await ElaboraOrdineCompletoAsync("ORD-98765");
            
            if (successo) {
                Console.WriteLine("[Main] Ordine completato con successo!");
            }
        }

        // --- METODI ASINCRONI HELPER ---

        // Un metodo asincrono deve avere 'async' nella firma e 
        // restituire Task<T> (o Task se void)
        private static async Task<string> ScaricaDatiDaServerAsync() {
            Console.WriteLine("  [Server] Connessione al database in corso...");
            
            // Task.Delay è l'equivalente asincrono (non bloccante) di Thread.Sleep!
            await Task.Delay(2000); 

            Console.WriteLine("  [Server] Dati recuperati!");
            return "Payload JSON: { status: 200, ok: true }";
        }

        private static void SimulaLavoroTemporaneo() {
            Console.WriteLine("  [Local] Prepariamo la grafica dell'interfaccia...");
        }

        private static async Task<bool> ElaboraOrdineCompletoAsync(string idOrdine) {
            Console.WriteLine($"\n[Processo] Inizio gestione {idOrdine}...");

            // Step 1: Verifica magazzino (asincrono)
            await Task.Delay(1000);
            Console.WriteLine($"  1. Prodotto disponibile in magazzino.");

            // Step 2: Elaborazione pagamento (asincrono)
            await Task.Delay(1500);
            Console.WriteLine($"  2. Pagamento approvato.");

            // Step 3: Invio email di conferma (asincrono)
            await Task.Delay(800);
            Console.WriteLine($"  3. Email di conferma inviata.");

            return true;
        }
    }
}