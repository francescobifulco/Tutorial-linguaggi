using System;

namespace Lezione19 {
    public class Lezione19_array_multidimensione_2d_3d { 
        static void Main(string[] args) {
            
            // =================================================================
            // 1. ARRAY BIDIMENSIONALE (2D) - RIGHE E COLONNE
            // =================================================================
            Console.WriteLine("--- 1. Array 2D (Matrice 3x2) ---");

            // La virgola dentro le parentesi quadre [,] indica un array 
            // a 2 dimensioni.
            // new string[3,2] significa: 3 righe e 2 colonne.
            string[,] codici = new string[3, 2] {
                { "010", "011" }, // Riga 0
                { "020", "021" }, // Riga 1
                { "030", "031" }  // Riga 2
            };

            // Accesso diretto all'elemento (Riga 0, Colonna 0) -> "010"
            Console.WriteLine($"Elemento in [0,0]: {codici[0, 0]}\n");

            // SCORRIMENTO CON FOREACH:
            // Il foreach "appiattisce" l'array e stampa ogni elemento
            //  dall'alto verso il basso,
            // da sinistra a destra, senza che tu debba preoccuparti di 
            // righe e colonne.
            Console.WriteLine("-> Scorrimento completo con Foreach:");
            foreach (string codice in codici) {
                 Console.WriteLine(codice);
            }

            // SCORRIMENTO CON DOPPIO FOR ANNIDATO:
            // .GetLength(0) restituisce la lunghezza della prima 
            // dimensione (righe = 3)
            // .GetLength(1) restituisce la lunghezza della 
            // seconda dimensione (colonne = 2)
            Console.WriteLine("\n-> Scorrimento dettagliato con due cicli For:");
            for (int riga = 0; riga < codici.GetLength(0); riga++) {
                Console.WriteLine($"--- Inizio Riga {riga} ---");
                for (int colonna = 0; colonna < codici.GetLength(1); colonna++) {
                    Console.WriteLine($"[Riga {riga}, Colonna {colonna}] -> Valore: {codici[riga, colonna]}");
                }
            }


            // =================================================================
            // 2. ARRAY TRIDIMENSIONALE (3D) - UN CUBO DI DATI
            // =================================================================
            Console.WriteLine("\n==================================================");
            Console.WriteLine("--- 2. Array 3D (Blocco 3x2x2) ---");
            Console.WriteLine("====================================================");

            // Due virgole [,,] indicano 3 dimensioni (Profondità, Righe, Colonne).
            string[,,] array3D = new string[3, 2, 2] {
                { // Dimensione 1 (Indice 0)
                    { "010", "011" }, // Dimensione 2 (Indice 0) -> Elementi 
                    // (Dimensione 3)
                    { "020", "021" }  // Dimensione 2 (Indice 1)
                },
                { // Dimensione 1 (Indice 1)
                    { "030", "031" },
                    { "040", "041" }
                },
                { // Dimensione 1 (Indice 2)
                    { "050", "051" },
                    { "060", "061" }
                }
            };

            // SCORRIMENTO CON TRIPLO FOR ANNIDATO:
            // Necessario quando devi mappare con precisione chirurgica 
            // le coordinate spaziali del dato.
            for (int dim1 = 0; dim1 < array3D.GetLength(0); dim1++) {
                for (int dim2 = 0; dim2 < array3D.GetLength(1); dim2++) {
                    for (int dim3 = 0; dim3 < array3D.GetLength(2); dim3++) {
                        Console.WriteLine($"Coordinata [{dim1},{dim2},{dim3}] -> Valore: {array3D[dim1, dim2, dim3]}");
                    }
                }
            }

            // SCORRIMENTO CON FOREACH SU ARRAY 3D:
            // Anche in questo caso, il foreach si rivela una bomba di 
            // pulizia se devi solo leggere i dati sequenzialmente.
            Console.WriteLine("\n-> Scorrimento completo del 3D con Foreach:");
            foreach (string codice in array3D) {
                 Console.WriteLine(codice);
            }
        }
    }
}