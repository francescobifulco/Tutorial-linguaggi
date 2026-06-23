#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// 1. PASSAGGIO PER VALORE (Copia)
int funzione(int x) {
    x = 40; // Modifica solo la copia locale
    return x;
}

// 2. PASSAGGIO PER RIFERIMENTO (Reference)
// Corretto il tipo di ritorno in void perché modifica 
// direttamente la variabile originale
void funzione2(int& x) {
    x = 10; // Modifica direttamente la variabile passata dal main!
}

// 3. RITORNO DI UNA REFERENCE
// Questa funzione restituisce un riferimento alla variabile originale più grande
int& maggiore2(int& x, int& y) {
    return (x > y) ? x : y;
}

// Lezione 24: La gestione dei referenze in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    cout << "=== 1. Concetto di Alias/Soprannome ===\n";
    int prova = 5;
    int& referenza_prova = prova; // referenza_prova È prova

    cout << "Valore originale: " << prova << "\n";
    cout << "Valore tramite reference: " << referenza_prova << "\n";

    prova = 50; // Cambiando uno, cambia anche l'altro
    cout << "Dopo modifica (prova = 50):\n";
    cout << "Prova: " << prova << " | Reference: " << referenza_prova << "\n\n";

    cout << "=== 2. Modifiche tramite Funzioni ===\n";
    // Passaggio per valore con riassegnazione manuale
    prova = funzione(prova); 
    cout << "Dopo prova = funzione(prova): " << prova << "\n"; // Stampa 40

    // Passaggio per riferimento puro usando la nuova funzione2
    funzione2(prova);
    cout << "Dopo funzione2(prova) [per riferimento]: " << prova << "\n\n"; // Stampa 10

    cout << "=== 3. Operatore Ternario e Reference di Ritorno ===\n";
    int x = 5;
    int y = 50;

    // Ternario classico (copia il valore 50 dentro 'maggiore')
    int maggiore = (x > y) ? x : y;
    cout << "Maggiore (valore): " << maggiore << "\n";

    // Uso di maggiore2 che restituisce una reference a 'y'
    int& comparazione = maggiore2(x, y);
    cout << "Maggiore (tramite reference a funzione): " << comparazione << "\n";

    // Dimostrazione estrema: se modifico 'comparazione', 
    // sto modificando direttamente 'y'!
    comparazione = 999;
    cout << "Nuovo valore di y nel main: " << y << "\n"; // Stampa 999!

    return 0;
}