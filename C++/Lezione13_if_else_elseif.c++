#include <iostream>
#include <string>
#include <typeinfo> 

using std::cout; 
using std::cin;
using std::string; 

// Lezione 13: L'IF, ELSE IF e ELSE in C++
int main() {

    // Gestione dei caratteri accentati nel terminale Windows
    std::setlocale(LC_ALL, "it_IT.utf8");

    int numero1 = 93;
    int numero2 = 104;

    cout << "=== Analisi di numero1 (" << numero1 << ") ===\n";
    
    // --- STRUTTURA CONDIZIONALE PRINCIPALE ---
    // Ricorda: in una catena di if/else if/else, il computer 
    // esegue SOLO la prima strada vera che trova!
    if (numero1 < 100){
        cout << "Strada 1: numero1 e' minore di 100" << "\n";

        // IF NIDIFICATO (Nested If): viene controllato solo 
        // se siamo entrati in questo blocco
        if (numero1 % 2 != 0){
        cout << "-> Nota: ed e' anche un numero DISPARI (resto != 0)" << "\n";
        }
    }else if (numero1 >= 100 && numero1 <200){
        cout << "Strada 2: numero1 e' compreso tra 100 e 199" << "\n";
    }else if (numero1 % 2 != 0){
        // Se numero1 fosse 203, entrerebbe qui perché è maggiore di 200 e dispari!
        cout << "Strada 3: numero1 e' maggiore di 200 ed e' DISPARI" << "\n";
    }else{
        // L'ultimo else è il paracadute: scatta se TUTTE le 
        // condizioni precedenti erano false.
        cout << "Strada 4: numero1 e' maggiore o uguale a 200 ed e' PARI" << "\n";
    }
    
    return 0;
}