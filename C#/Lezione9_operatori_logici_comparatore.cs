using System;

namespace Lezione9 {
    public class Lezione9_operatori_logici_comparatore {
        static void Main(string[] args) {
            
            // --- VARIABILI DI PROVA ---
            int prova = 4;
            bool isOnline = true;
            int tagliaDisponibile = 39;
            string coloreDisponibile = "nero";

            // ==========================================
            // 1. OPERATORI DI CONFRONTO (Restituiscono sempre true o false)
            // ==========================================
            Console.WriteLine("--- 1. Operatori di Confronto ---");
            
            Console.WriteLine($"5 < 6  (Minore): {5 < 6}");    
            Console.WriteLine($"5 > 6  (Maggiore): {5 > 6}");  
            Console.WriteLine($"5 == 6 (Uguale): {5 == 6}");   
            Console.WriteLine($"5 != 6 (Diverso): {5 != 6}");  
            Console.WriteLine($"5 <= 6 (Minore o Uguale): {5 <= 6}"); 
            Console.WriteLine($"5 >= 6 (Maggiore o Uguale): {5 >= 6}");

            // ==========================================
            // 2. OPERATORI LOGICI BOOLEANI
            // ==========================================
            Console.WriteLine("\n--- 2. Operatori Logici ---");

            // Operatore AND (&&): Restituisce true SOLO 
            // SE ENTRAMBE le condizioni sono vere.
            // 5 < 3 è False, 5 > 6 è False -> False && False = False
            Console.WriteLine($"AND (5 < 3 && 5 > 6): {5 < 3 && 5 > 6}");

            // Operatore OR (||): Restituisce true SE ALMENO 
            // UNA delle condizioni è vera.
            // 5 < 3 è False, 5 > 6 è False -> False || False = False
            Console.WriteLine($"OR  (5 < 3 || 5 > 6): {5 < 3 || 5 > 6}");

            // Operatore NOT (!): Inverte il valore booleano 
            // (restituisce il contrario).
            Console.WriteLine($"Valore di isOnline: {isOnline}");
            Console.WriteLine($"NOT (!isOnline): {!isOnline}");

            // ==========================================
            // 3. LOGICA COMBINATA (Espressioni complesse)
            // ==========================================
            Console.WriteLine("\n--- 3. Logica Combinata (E-Commerce) ---");

            // Pensa a un filtro di un negozio online: cerchi scarpe 
            // taglia 39 NERE oppure ROSSE.
            // Le parentesi tonde isolano l'OR, stabilendo 
            // la precedenza (esattamente come in matematica).
            // Passo 1: (coloreDisponibile == "nero" [True] 
            // || coloreDisponibile == "rosso" [False]) -> Diventa True
            // Passo 2: tagliaDisponibile == 39 [True] 
            // && True -> Il risultato finale è True.
            bool risultatoFiltro = tagliaDisponibile == 39 && (coloreDisponibile == "nero" || coloreDisponibile == "rosso");

            Console.WriteLine($"L'articolo (Taglia 39, Nero/Rosso) è disponibile? {risultatoFiltro}");

        }
    }
}