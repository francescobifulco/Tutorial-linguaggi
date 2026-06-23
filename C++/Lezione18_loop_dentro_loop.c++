#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// Lezione 18: La gestione dei LOOP dentre ai altri LOOP in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    // --- ESEMPIO 1: COORDINATE (IL TUO CODICE) ---
    cout << "=== 1. Griglia di Coordinate (Lettera + Numero) ===\n";
    string colonne = "ABCDEFG";
    int righe = 10;

    // Il ciclo ESTERNO si muove più lentamente: cambia solo quando 
    // quello interno ha finito tutto il suo giro
    for (int colonna = 0; colonna < colonne.length(); colonna++){
        
        // Il ciclo INTERNO è quello veloce: fa un giro completo 
        // (da 1 a 10) per OGNI passo del ciclo esterno
        for (int riga = 1; riga <= righe; riga++){
                cout << colonne[colonna] << " " << riga << "\n";
            }
            cout << "\n";
        }
        cout << "\n\n";

    // --- ESEMPIO 2: LA TAVOLA PITAGORICA (NUOVO ESEMPIO) ---
    cout << "=== 2. Tavola Pitagorica (Tabelline da 1 a 5) ===\n";

    // Righe della tabella (moltiplicando)
    for (int i = 1; i <= 5; i++) {
        
        // Colonne della tabella (moltiplicatore)
        for (int j = 1; j <= 5; j++) {
            // Calcoliamo il prodotto tra 
            // l'indice esterno (i) e quello interno (j)
            cout << i * j << "\t"; // '\t' inserisce una tabulazione per tenere i numeri allineati in colonne
        }
        cout << "\n"; // Finito di stampare una riga della tabellina, andiamo a capo
    }
    
    return 0;
}