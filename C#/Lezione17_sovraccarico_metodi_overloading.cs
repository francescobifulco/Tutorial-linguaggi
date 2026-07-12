using System;

namespace Lezione17 {
    public class Lezione17_sovraccarico_metodi_overloading { 
        static void Main(string[] args) {
            // 1. Chiama il metodo faiSomma(int, int) -> Ritorna un int
            int risInt1 = faiSomma(10, 20);
            Console.WriteLine($"1. Somma di due interi: {risInt1}");

            // 2. Chiama il metodo faiSomma(int, double) -> Ritorna un double
            // CORREZIONE: Il risultato deve essere salvato in una 
            // variabile double
            double risDouble1 = faiSomma(10, 20.0);
            Console.WriteLine($"2. Somma di int e double: {risDouble1}");

            // 3. Chiama il metodo faiSomma(int, int, int) -> Ritorna un int
            int risInt2 = faiSomma(10, 20, 30);
            Console.WriteLine($"3. Somma di tre interi: {risInt2}");

            // 4. Chiama il 
            // metodo faiSomma(double, double) -> Ritorna un double
            // CORREZIONE: Il risultato deve essere salvato in una 
            // variabile double
            double risDouble2 = faiSomma(10.0, 20.0);
            Console.WriteLine($"4. Somma di due double: {risDouble2}");
        }

        // =============================================================================
        // SOVRACCARICO (OVERLOADING) DEI METODI
        // C# capisce quale metodo avviare guardando i tipi di argomenti che gli passi.
        // =============================================================================

        // Firma 1: faiSomma(int, int)
        static int faiSomma(int num1, int num2) {
            return num1 + num2;
        }

        // Firma 2: faiSomma(int, double)
        // CORREZIONE: La variabile interna deve essere 
        // double perché int + double fa double,
        // ed è coerente con il tipo di ritorno del metodo.
        static double faiSomma(int num1, double num2) {
            double somma = num1 + num2;            
            return somma;
        }

        // Firma 3: faiSomma(int, int, int)
        static int faiSomma(int num1, int num2, int num3) {
            return num1 + num2 + num3;
        }

        // Firma 4: faiSomma(double, double)
        static double faiSomma(double num1, double num2) {
            double somma = num1 + num2;            
            return somma;
        }
    }
}