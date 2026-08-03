using System;
using System.IO;
using System.Text.Json; // FONDAMENTALE per JSON
using System.Xml.Serialization; // FONDAMENTALE per XML

namespace Lezione47 {

    // N.B. Per la serializzazione XML la classe e le proprietà 
    // DEVONO essere pubbliche 
    // e la classe deve avere un costruttore vuoto di default!
    public class Utente {
        public int Id { get; set; }
        public string Nome { get; set; } = string.Empty;
        public string Email { get; set; } = string.Empty;
        public bool IsAttivo { get; set; }

        // Costruttore vuoto richiesto da XmlSerializer
        public Utente() { }

        public Utente(int id, string nome, string email, bool isAttivo) {
            Id = id;
            Nome = nome;
            Email = email;
            IsAttivo = isAttivo;
        }
    }

    public class Lezione47_serializzazione {
        static void Main(string[] args) {
            
            // Oggetto C# di prova
            Utente utenteOriginale = new Utente(1, "Mario Rossi", "mario.rossi@email.com", true);

            Console.WriteLine("--- 1. SERIALIZZAZIONE E DESERIALIZZAZIONE JSON ---");

            // Opzioni per formattare il JSON in modo leggibile (con rientri/spazi)
            JsonSerializerOptions opzioniJson = new JsonSerializerOptions { WriteIndented = true };

            // A. Serializzazione (Oggetto C# -> Stringa JSON)
            string jsonString = JsonSerializer.Serialize(utenteOriginale, opzioniJson);
            Console.WriteLine("Stringa JSON generata:");
            Console.WriteLine(jsonString);

            // B. Deserializzazione (Stringa JSON -> Oggetto C#)
            Utente? utenteDaJson = JsonSerializer.Deserialize<Utente>(jsonString);
            Console.WriteLine($"\nOggetto ripristinato da JSON: Nome = {utenteDaJson?.Nome}, Email = {utenteDaJson?.Email}");


            Console.WriteLine("\n--- 2. SERIALIZZAZIONE E DESERIALIZZAZIONE XML ---");

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(Utente));
            string fileXml = "utente.xml";

            // A. Serializzazione XML (Oggetto C# -> File XML su disco)
            using (StreamWriter writer = new StreamWriter(fileXml)) {
                xmlSerializer.Serialize(writer, utenteOriginale);
            }
            Console.WriteLine($"File '{fileXml}' creato con successo!");

            // Visualizziamo il contenuto del file XML appena creato
            Console.WriteLine("\nContenuto del file XML:");
            Console.WriteLine(File.ReadAllText(fileXml));

            // B. Deserializzazione XML (File XML -> Oggetto C#)
            Utente? utenteDaXml;
            using (StreamReader reader = new StreamReader(fileXml)) {
                utenteDaXml = (Utente?)xmlSerializer.Deserialize(reader);
            }

            Console.WriteLine($"Oggetto ripristinato da XML: Nome = {utenteDaXml?.Nome}, ID = {utenteDaXml?.Id}");


            Console.WriteLine("\n--- 3. PULIZIA DEI FILE DI PROVA ---");
            if (File.Exists(fileXml)) {
                File.Delete(fileXml);
                Console.WriteLine($"File temporaneo '{fileXml}' eliminato.");
            }
        }
    }
}