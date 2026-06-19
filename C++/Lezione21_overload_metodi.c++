#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// --- LE VARIE VERSIONI DI "SOMMA" (OVERLOADING) ---

// Versione 1: Due parametri interi
int somma(int x, int y) {
    cout << "-> Chiamata versione (int, int)\n";
    return x + y;
}

// Versione 2: Un intero e un decimale
double somma(int x, double y) { // Nota: restituisce double perché c'è di mezzo un decimale
    cout << "-> Chiamata versione (int, double)\n";
    return x + y;
}

// Versione 3: Nessun parametro (somma vuota o di default)
int somma() {
    cout << "-> Chiamata versione vuota ()\n";
    return 0;
}

// Versione 4: Tre parametri interi
int somma(int x, int y, int z) {
    cout << "-> Chiamata versione (int, int, int)\n";
    return x + y + z;
}

// Versione 5: Un solo intero
int somma(int x) {
    cout << "-> Chiamata versione singola (int)\n";
    return x;
}

// Versione 6: Un solo decimale
double somma(double x) {
    cout << "-> Chiamata versione singola (double)\n";
    return x;
}

// Lezione 21: La gestione del Overload dei metodi in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== Test dell'Overloading delle Funzioni ===\n\n";

    // Passiamo due interi -> Il C++ sceglie la Versione 1
    int ris1 = somma(5, 6);
    cout << "Risultato: " << ris1 << "\n\n";

    // Passiamo tre interi -> Il C++ sceglie la Versione 4
    int ris2 = somma(10, 20, 30);
    cout << "Risultato: " << ris2 << "\n\n";

    // Passiamo un intero e un decimale -> Il C++ sceglie la Versione 2
    double ris3 = somma(5, 4.5);
    cout << "Risultato: " << ris3 << "\n\n";

    // Non passiamo nulla -> Il C++ sceglie la Versione 3
    int ris4 = somma();
    cout << "Risultato: " << ris4 << "\n\n";

    // Passiamo un singolo decimale -> Il C++ sceglie la Versione 6
    double ris5 = somma(9.99);
    cout << "Risultato: " << ris5 << "\n";

    return 0;
}