#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// Lezione 15: La gestione degli operatori ternari in C++
int main() {

    std::setlocale(LC_ALL, "it_IT.utf8");

    int numero1 = 90;

    // --- 1. TERNARIO SEMPLICE ---
    // Struttura: (CONDIZIONE) ? VALORE_SE_VERO : VALORE_SE_FALSO;
    string tipoNumero = (numero1 % 2 == 0) ? "pari" : "dispari";

    cout << "=== 1. Ternario Semplice ===\n";
    cout << "Il numero " << numero1 << " e': " << tipoNumero << "\n\n";

    // --- 2.IL CONFRONTO CON IF-ELSE ---
    // Questo blocco fa esattamente lo stesso calcolo del ternario sopra.
    if (numero1 % 2 == 0){
        tipoNumero = "pari";
    }else{
        tipoNumero = "dispari";
    }

    cout << "=== 2. Controllo Equivalente con If-Else ===\n";
    cout << "Risultato dall'If-Else: " << tipoNumero << "\n\n";

    // --- 3. TERNARIO CONCATENATO (NIDIFICATO) ---
    // Spiegazione: 
    // - Se numero1 < 100 -> assegna "minore di 100".
    // - ALTRIMENTI (:) se numero1 <= 200 -> assegna "compreso tra 100 e 200".
    // - ALTRIMENTI (:) -> assegna "superiore a 200".
    string tipoNumero1 = (numero1 < 100) ? "minnore di 100" 
                       : (numero1 <= 200) ? "compreso tra 100 e 200" 
                       : "superiore a 200";

    cout << "=== 3. Ternario Concatenato ===\n";
    cout << "Stato di numero1: " << tipoNumero1 << "\n";
    cout << tipoNumero1 << "\n";

    return 0;
}