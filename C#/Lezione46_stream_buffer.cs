using System;
using System.IO;
using System.Text;

namespace Lezione46 {
    public class Lezione46_stream_buffer {
        static void Main(string[] args) {
            
            string fileLog = "app_log.txt";

            Console.WriteLine("--- 1. SCRITTURA EFFICIENTE CON StreamWriter ---");

            // Il blocco 'using' garantisce che lo stream venga CHIUSO e svuotato (Flush) 
            // in modo sicuro anche se si verificano errori.
            using (StreamWriter writer = new StreamWriter(fileLog, append: true, Encoding.UTF8)) {
                writer.WriteLine($"[LOG {DateTime.Now:HH:mm:ss}] Avvio dell'applicazione...");
                writer.WriteLine($"[LOG {DateTime.Now:HH:mm:ss}] Connessione al database stabilita.");
                writer.WriteLine($"[LOG {DateTime.Now:HH:mm:ss}] Operazione completata.");
            } // Qui lo StreamWriter si chiude automaticamente salvando i dati su disco.

            Console.WriteLine($"Scritte 3 righe nel file '{fileLog}' tramite StreamWriter.");


            Console.WriteLine("\n--- 2. LETTURA RIGO PER RIGO CON StreamReader ---");

            if (File.Exists(fileLog)) {
                using (StreamReader reader = new StreamReader(fileLog, Encoding.UTF8)) {
                    string? riga;
                    int contaRighe = 1;

                    // Legge il file riga per riga fino alla fine (ReadLine restituisce null a fine file)
                    while ((riga = reader.ReadLine()) != null) {
                        Console.WriteLine($"Riga {contaRighe++}: {riga}");
                    }
                }
            }


            Console.WriteLine("\n--- 3. GESTIONE DEI DATI BINARI / BUFFER CON FileStream ---");

            string fileBinario = "dati_raw.dat";

            // Creazione di un FileStream per accedere direttamente ai byte (FileMode.Create)
            using (FileStream fs = new FileStream(fileBinario, FileMode.Create, FileAccess.Write)) {
                // Creiamo un buffer di byte manuale
                byte[] bufferScrittura = Encoding.UTF8.GetBytes("Questo è un testo convertito in byte per il buffer.");

                // Scriviamo il buffer nel file: (array di byte, offset di partenza, numero di byte)
                fs.Write(bufferScrittura, 0, bufferScrittura.Length);
            }

            Console.WriteLine($"Dati binari scritti in '{fileBinario}'.");

            // Lettura del file binario a blocchi (Buffer di 16 byte alla volta)
            using (FileStream fsLettura = new FileStream(fileBinario, FileMode.Open, FileAccess.Read)) {
                byte[] bufferLettura = new byte[16]; // Buffer piccolo da 16 byte
                int byteLetti;

                Console.WriteLine("\nLettura a blocchi (Buffer di 16 byte):");
                
                // Read riempie il buffer e restituisce il numero reale di byte letti (0 significa EOF)
                while ((byteLetti = fsLettura.Read(bufferLettura, 0, bufferLettura.Length)) > 0) {
                    string bloccoTesto = Encoding.UTF8.GetString(bufferLettura, 0, byteLetti);
                    Console.WriteLine($"[Blocco da {byteLetti} byte]: {bloccoTesto}");
                }
            }


            Console.WriteLine("\n--- 4. PULIZIA DEI FILE DI PROVA ---");
            if (File.Exists(fileLog)) File.Delete(fileLog);
            if (File.Exists(fileBinario)) File.Delete(fileBinario);
            Console.WriteLine("File temporanei eliminati.");
        }
    }
}