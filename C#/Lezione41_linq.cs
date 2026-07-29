using System;
using System.Collections.Generic;
using System.Linq; // FONDAMENTALE: Attiva tutti i metodi estensione di LINQ!

namespace Lezione41 {
    
    // Classe di supporto per gli esempi su LINQ
    public class Prodotto {
        public string Nome { get; set; }
        public string Categoria { get; set; }
        public double Prezzo { get; set; }

        public Prodotto(string nome, string categoria, double prezzo) {
            Nome = nome;
            Categoria = categoria;
            Prezzo = prezzo;
        }
    }

    public class Lezione41_linq {
        static void Main(string[] args) {
            
            // Popoliamo una lista di oggetti di prova
            List<Prodotto> prodotti = new List<Prodotto> {
                new Prodotto("Laptop", "Elettronica", 1200.00),
                new Prodotto("Mouse", "Elettronica", 25.50),
                new Prodotto("Tastiera", "Elettronica", 70.00),
                new Prodotto("Scrivania", "Arredamento", 150.00),
                new Prodotto("Sedia", "Arredamento", 85.00),
                new Prodotto("Monitor", "Elettronica", 300.00)
            };

            Console.WriteLine("--- 1. FILTRARE CON .Where() ---");

            // Seleziona solo i prodotti che costano più di 100€
            var prodottiCostosi = prodotti.Where(p => p.Prezzo > 100);

            foreach (var p in prodottiCostosi) {
                Console.WriteLine($"- {p.Nome}: {p.Prezzo}€");
            }


            Console.WriteLine("\n--- 2. ORDINARE CON .OrderBy() E .OrderByDescending() ---");

            // Ordina i prodotti per prezzo in modo crescente
            var ordinatiPerPrezzo = prodotti.OrderBy(p => p.Prezzo);

            Console.WriteLine("Prodotti dal meno caro al più caro:");
            foreach (var p in ordinatiPerPrezzo) {
                Console.WriteLine($"- {p.Nome}: {p.Prezzo}€");
            }


            Console.WriteLine("\n--- 3. TRASFORMARE CON .Select() ---");

            // Estrae solo i nomi dei prodotti trasformandoli in una lista di stringhe
            List<string> nomiProdotti = prodotti.Select(p => p.Nome).ToList();

            Console.WriteLine("Lista dei soli nomi:");
            nomiProdotti.ForEach(nome => Console.WriteLine($"-> {nome}"));


            Console.WriteLine("\n--- 4. RICERCA DI SINGOLI ELEMENTI CON .FirstOrDefault() ---");

            // Cerca il primo prodotto della categoria "Arredamento". 
            // Se non trova nulla, restituisce 'null' senza piantare l'app.
            Prodotto? primoArredo = prodotti.FirstOrDefault(p => p.Categoria == "Arredamento");
            Console.WriteLine($"Primo arredo trovato: {primoArredo?.Nome ?? "Nessuno"}");

            // Cerca un prodotto che non esiste
            Prodotto? introvabile = prodotti.FirstOrDefault(p => p.Categoria == "Abbigliamento");
            Console.WriteLine($"Abbigliamento trovato: {introvabile?.Nome ?? "Nessuno"}");


            Console.WriteLine("\n--- 5. RAGGRUPPARE CON .GroupBy() ---");

            // Raggruppa i prodotti in base alla loro Categoria
            var gruppiPerCategoria = prodotti.GroupBy(p => p.Categoria);

            foreach (var gruppo in gruppiPerCategoria) {
                Console.WriteLine($"\nCategoria: {gruppo.Key} (Totale elementi: {gruppo.Count()})");
                foreach (var p in gruppo) {
                    Console.WriteLine($"  * {p.Nome} - {p.Prezzo}€");
                }
            }
        }
    }
}