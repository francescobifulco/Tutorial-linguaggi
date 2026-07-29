using System;
using System.IO; // FONDAMENTALE: Namespace per lavorare con File, Cartelle e Percorsi

namespace Lezione45 {
    public class Lezione45_system_io {
        static void Main(string[] args) {
            
            Console.WriteLine("--- 1. GESTIONE DEI PERCORSI CON System.IO.Path ---");

            // Costruire un percorso in modo sicuro per qualsiasi Sistema Operativo (Windows/Linux/Mac)
            string cartellaBase = "MieiDocumenti";
            string nomeFile = "note.txt";
            string percorsoCompleto = Path.Combine(cartellaBase, nomeFile);

            Console.WriteLine($"Percorso combinato: {percorsoCompleto}");
            Console.WriteLine($"Estensione del file: {Path.GetExtension(percorsoCompleto)}");
            Console.WriteLine($"Nome file senza estensione: {Path.GetFileNameWithoutExtension(percorsoCompleto)}");


            Console.WriteLine("\n--- 2. GESTIONE DELLE CARTELLE CON System.IO.Directory ---");

            // Creazione della cartella se non esiste
            if (!Directory.Exists(cartellaBase)) {
                Directory.CreateDirectory(cartellaBase);
                Console.WriteLine($"Cartella '{cartellaBase}' creata con successo!");
            } else {
                Console.WriteLine($"La cartella '{cartellaBase}' esiste già.");
            }


            Console.WriteLine("\n--- 3. CREAZIONE E SCRITTURA FILE CON System.IO.File ---");

            // Scrittura di testo in un file (se il file esiste, viene sovrascritto)
            string contenutoIniziale = "Lezione 45: Gestione I/O in C#.\nPrimo rigo di prova.";
            File.WriteAllText(percorsoCompleto, contenutoIniziale);
            Console.WriteLine($"Scritto contenuto nel file '{percorsoCompleto}'.");

            // Aggiungere contenuto in coda (Append) senza cancellare quello esistente
            string rigoAggiuntivo = "\nQuesto rigo è stato aggiunto successivamente con AppendAllText.";
            File.AppendAllText(percorsoCompleto, rigoAggiuntivo);
            Console.WriteLine("Nuovo rigo aggiunto in coda.");


            Console.WriteLine("\n--- 4. LETTURA FILE CON System.IO.File ---");

            if (File.Exists(percorsoCompleto)) {
                // Leggere tutto il file come singola stringa
                string testoLetto = File.ReadAllText(percorsoCompleto);
                Console.WriteLine("\n--- Contenuto letto dal file ---");
                Console.WriteLine(testoLetto);
                Console.WriteLine("--------------------------------");

                // In alternativa, leggere il file rigo per rigo in un array/lista
                string[] righe = File.ReadAllLines(percorsoCompleto);
                Console.WriteLine($"\nIl file contiene in totale {righe.Length} righe.");
            }


            Console.WriteLine("\n--- 5. ELIMINAZIONE FILE E CARTELLE ---");

            // Pulizia di prova: eliminiamo il file e la cartella creata
            if (File.Exists(percorsoCompleto)) {
                File.Delete(percorsoCompleto);
                Console.WriteLine($"File '{percorsoCompleto}' eliminato.");
            }

            if (Directory.Exists(cartellaBase)) {
                // Il parametro 'true' permette di cancellare la cartella anche se contiene file/sottocartelle
                Directory.Delete(cartellaBase, true); 
                Console.WriteLine($"Cartella '{cartellaBase}' eliminata.");
            }
        }
    }
}