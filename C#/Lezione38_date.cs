using System;

namespace Lezione38 {
    public class Lezione38_date {
        static void Main(string[] args) {
            
            // 1. Costruttore vuoto: crea la data di default (01/01/0001 00:00:00)
            DateTime data = new DateTime();
            Console.WriteLine($"Data vuota (default): {data}");

            // 2. Creazione di una data specifica (Anno, Mese, Giorno)
            DateTime data1 = new DateTime(2026, 7, 27);
            Console.WriteLine($"Data personalizzata (Solo data): {data1.ToShortDateString()}");

            // 3. Creazione con Data e Ora (Anno, Mese, Giorno, Ore, Minuti, Secondi)
            DateTime data2 = new DateTime(2021, 7, 27, 16, 30, 34);
            Console.WriteLine($"Data e ora personalizzata: {data2}");

            Console.WriteLine("\n--- PROPRIETÀ DI ORA CORRENTE ---");

            // 4. Data di oggi con orario impostato a mezzanotte (00:00:00)
            data = DateTime.Today;
            Console.WriteLine($"DateTime.Today: {data.ToShortDateString()}");

            // 5. Data e Ora esatta del sistema locale in questo momento
            data = DateTime.Now;
            Console.WriteLine($"DateTime.Now: {data}");

            Console.WriteLine("\n--- ESTRAZIONE DEI SINGOLI COMPONENTI ---");
            
            // Proprietà per accedere a singole parti della data/ora
            Console.WriteLine($"Anno: {data.Year}");
            Console.WriteLine($"Giorno della settimana (in inglese): {data.DayOfWeek}");
            Console.WriteLine($"Giorno del mese: {data.Day}");
            Console.WriteLine($"Giorno dell'anno (1-365/366): {data.DayOfYear}");
            Console.WriteLine($"Minuto corrente: {data.Minute}");

            Console.WriteLine("\n--- FUSI ORARI (UTC vs LOCALE) ---");

            // UTC (Coordinated Universal Time) e Ora Locale del sistema
            DateTime dataUTC = DateTime.UtcNow;
            DateTime dataLocal = DateTime.Now;

            Console.WriteLine($"Ora UTC (Tempo Universale): {dataUTC}");
            Console.WriteLine($"Ora Locale: {dataLocal}");

            Console.WriteLine("\n--- OPERAZIONI SULLE DATE (Aggiungere e Sottrarre) ---");

            // AddDays(): aggiunge giorni alla data corrente senza modificarla direttamente (restituisce un nuovo DateTime)
            Console.WriteLine($"Tra 11 giorni sarà il: {dataLocal.AddDays(11).ToShortDateString()}");

            // AddYears(): aggiunge anni e possiamo concatenare altre proprietà (es. DayOfWeek)
            Console.WriteLine($"Giorno della settimana tra 2 anni: {dataLocal.AddYears(2).DayOfWeek}");

            // Subtract(): calcola la differenza tra due date restituendo un oggetto 'TimeSpan'
            DateTime dataProva = new DateTime(2026, 7, 27);
            TimeSpan differenza = dataLocal.Subtract(dataProva);
            Console.WriteLine($"Differenza (TimeSpan) da dataProva: {differenza}");

            Console.WriteLine("\n--- FORMATTAZIONE DELLE DATE (ToString Specifiers) ---");

            // Formattazione standard con identificatori di formato
            Console.WriteLine($"Formato 'D' (Data estesa): {dataLocal.ToString("D")}");
            Console.WriteLine($"Formato 'f' (Data e ora estesa): {dataLocal.ToString("f")}");
            Console.WriteLine($"Formato 'u' (Formato universale ordinabile): {dataLocal.ToString("u")}");
            Console.WriteLine($"Formato 'Y' (Mese e Anno): {dataLocal.ToString("Y")}");
            
            // Formattazione personalizzata (dddd = giorno della settimana esteso, MMMM = mese esteso)
            Console.WriteLine($"Formato personalizzato (dddd, dd MMMM): {dataLocal.ToString("dddd, dd MMMM")}");
        }
    }
}