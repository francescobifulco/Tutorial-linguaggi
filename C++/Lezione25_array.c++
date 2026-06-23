#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// Lezione 25: Gli Array in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    // --- 1. ARRAY MONODIMENSIONALE ---
    int vot_storia[5] = {6, 8, 2, 8, 9}; // Sistemato il refuso "stroia"

    // Modifica e lettura tramite indice (Base 0)
    vot_storia[0] = 10;
    cout << "=== 1. Singolo elemento modificato ===\n";
    cout << "Primo voto: " << vot_storia[0] << "\n\n";

    // STAMPA DEL NOME DELL'ARRAY
    // Nota: stampare il nome di un array statico senza indici sputa fuori un indirizzo di memoria!
    // Questo perché in C++ il nome dell'array è a tutti gli effetti un PUNTATORE al suo primo elemento.
    cout << "=== 2. Indirizzo base dell'array ===\n";
    cout << vot_storia << "\n\n";

    // Scorrimento classico
    cout << "=== 3. Scorrimento con For Tradizionale ===\n";
    for (int i = 0; i < 5; i++){
        cout << vot_storia[i] << " ";
    }
    cout << "\n\n";

    // Scorrimento con Foreach
    cout << "=== 4. Scorrimento con Range-based For ===\n";
    for(int voto : vot_storia){
        cout << voto << " ";
    }
    cout << "\n\n";

    // --- 2. IL TRUCCO DEL SIZEOF ---
    // sizeof(vot_storia) restituisce il peso in byte dell'intero array (5 interi * 4 byte = 20 byte).
    // Dividendo per il peso di un singolo int (4 byte), otteniamo matematicamente la lunghezza (5).
    cout << "=== 5. Calcolo dinamico della lunghezza ===\n";
    cout << "Peso totale in byte: " << sizeof(vot_storia) << "\n";
    
    int lunghezza = sizeof(vot_storia) / sizeof(int);
    cout << "Numero di elementi calcolato: " << lunghezza << "\n";
    for (int i = 0; i < lunghezza; i++){
        cout << vot_storia[i] << " ";
    }
    cout << "\n\n";
    
    // --- 3. MATRICI (ARRAY BIDIMENSIONALI) ---
    // Struttura: string nome[RIGHE][COLONNE]
    string celle[2][4] = {
        {"A1", "B1", "C1", "D1"}, // Riga 0
        {"A2", "B2", "C2", "D2"}  // Riga 1
    };

    cout << "=== 6. Lettura Matrice ===\n";
    // CORRETTO: celle[2][3] andava fuori dai limiti. Accediamo all'ultima cella sicura della riga 1.
    cout << "Elemento in posizione [1][3]: " << celle[1][3] << "\n\n"; 

    // Scorrimento della matrice con doppi cicli annidati
    cout << "=== 7. Scorrimento completo della Matrice ===\n";
    for(int riga = 0; riga < 2; riga++){
        for (int colonna = 0; colonna < 4; colonna++){
            cout << "Cella [" << riga << "][" << colonna << "] = " << celle[riga][colonna] << "\t";
        }
        cout << "\n"; // Va a capo alla fine di ogni riga
    }

    return 0;
}