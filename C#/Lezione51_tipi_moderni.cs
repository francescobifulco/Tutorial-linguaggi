using System;

namespace Lezione51 {

    // --- 1. RECORD (Oggetti Immutabili per Dati) ---
    // Sintassi posizionale: crea automaticamente 
    // proprietà 'init-only', costruttore e uguaglianza per valore!
    public record PersonaRecord(string Nome, string Cognome, int Eta);

    // --- 2. STRUCT vs CLASS (Stack vs Heap) ---
    
    // Struct: Value Type (Allocato nello STACK, copiato per valore)
    public struct PuntoStruct {
        public int X { get; set; }
        public int Y { get; set; }

        public PuntoStruct(int x, int y) {
            X = x;
            Y = y;
        }
    }

    // Class: Reference Type (Allocato nell'HEAP, copiato per riferimento)
    public class PuntoClass {
        public int X { get; set; }
        public int Y { get; set; }

        public PuntoClass(int x, int y) {
            X = x;
            Y = y;
        }
    }

    public class Lezione51_tipi_moderni {
        static void Main(string[] args) {
            
            Console.WriteLine("--- 1. RECORD E IMMUTABILITÀ ---");

            PersonaRecord p1 = new PersonaRecord("Mario", "Rossi", 30);
            PersonaRecord p2 = new PersonaRecord("Mario", "Rossi", 30);

            // A. Confronto uguaglianza
            // Nelle Classi 'p1 == p2' controlla il riferimento (sarebbe False). 
            // Nei Record controlla I VALORI dei campi (è True)!
            Console.WriteLine($"p1 è uguale a p2 per valore? {p1 == p2}"); 

            // B. Immutabilità e clonazione con modifica ('with')
            // p1.Nome = "Luigi"; // ERRORE! I record sono immutabili per default.
            PersonaRecord p3 = p1 with { Nome = "Luigi" }; // Crea una NUOVA copia modificando solo 'Nome'

            Console.WriteLine($"Originale p1: {p1}");
            Console.WriteLine($"Copia modificata p3: {p3}");


            Console.WriteLine("\n--- 2. STRUCT (Stack) vs CLASS (Heap) ---");

            // STRUCT (Copia del valore)
            PuntoStruct s1 = new PuntoStruct(10, 20);
            PuntoStruct s2 = s1; // Viene creata una COPIA INDIPENDENTE nello Stack
            s2.X = 99;
            Console.WriteLine($"Struct -> s1.X: {s1.X} | s2.X: {s2.X} (s1 NON è cambiato!)");

            // CLASS (Copia del riferimento)
            PuntoClass c1 = new PuntoClass(10, 20);
            PuntoClass c2 = c1; // c2 punta allo STESSO OGGETTO nell'Heap
            c2.X = 99;
            Console.WriteLine($"Class  -> c1.X: {c1.X} | c2.X: {c2.X} (c1 È CAMBIATO!)");


            Console.WriteLine("\n--- 3. TUPLE E PATTERN MATCHING AVANZATO ---");

            // A. Tuple con elementi nominati
            (string Nome, double Prezzo, bool InSconto) prodotto = ("Laptop", 899.99, true);
            Console.WriteLine($"Prodotto: {prodotto.Nome}, Prezzo: {prodotto.Prezzo}€");

            // B. Pattern Matching su Tipi, Proprietà e Tuple
            object[] oggettiVari = new object[] {
                15,
                "Ciao Mondo",
                new PersonaRecord("Anna", "Verdi", 17),
                new PersonaRecord("Giuseppe", "Bianchi", 25),
                (3, 4) // Tupla di coordinate (x, y)
            };

            foreach (var item in oggettiVari) {
                // Switch Expression con Pattern Matching avanzato
                string descrizione = item switch {
                    int n when n > 10 => $"Un numero intero grande ({n})",
                    string s => $"Una stringa di {s.Length} caratteri",
                    
                    // Property Pattern: controlla la proprietà 'Eta' direttamente nel pattern
                    PersonaRecord { Eta: < 18 } p => $"Minorenne: {p.Nome} ({p.Eta} anni)",
                    PersonaRecord p => $"Maggiorenne: {p.Nome} ({p.Eta} anni)",
                    
                    // Positional Pattern / Tuple Pattern
                    (int x, int y) => $"Coordinate punto: X={x}, Y={y}",
                    
                    _ => "Oggetto di tipo sconosciuto"
                };

                Console.WriteLine($"-> {descrizione}");
            }
        }
    }
}