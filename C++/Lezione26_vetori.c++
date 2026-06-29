#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Funzione che accetta un vettore come parametro
void prova(vector<int> vettore){
    cout << "--- Stampa dalla funzione prova() ---\n";
    if (vettore.empty()) {
        cout << "Il vettore passato e' vuoto!\n";
    } else {
        for (int numero : vettore) {
            cout << numero << " ";
        }
        cout << "\n";
    }
}

// Lezione 26: La gestione avanzata dei vettori in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");
    
    // Inizializzazione e modifica base
    vector<int> numeri = {10, 20, 30};
    numeri[0] = 100; // Il vettore diventa: {100, 200, 300}
    cout << "=== 1. Stato Iniziale ===\n";
    cout << "Dimensione iniziale (.size()): " << numeri.size() << "\n";
    for (int numero : numeri) {
        cout << numero << " ";
    }
    cout << "\n\n";

    // POP_BACK: Rimuove l'ultimo elemento (il 30)
    cout << "=== 2. Test pop_back() ===\n";
    numeri.pop_back(); // Il vettore diventa: {100, 20
    cout << "Dopo pop_back (ultimo rimosso): ";
    for (int n : numeri) cout << n << " ";
    cout << "\n\n";

    // PUSH_BACK: Aggiunge un elemento in coda (il 50)
    cout << "=== 3. Test push_back() ===\n";
    numeri.push_back(50); // Il vettore diventa: {100, 20, 50}
    cout << "Dopo push_back(50): ";
    for (int n : numeri) cout << n << " ";
    cout << "\n\n";

    // INSERT: Inserisce un elemento in una posizione specifica usando gli iteratori
    cout << "=== 4. Test insert() ===\n";
    // numeri.begin() + 1 indica la seconda posizione (indice 1)
    numeri.insert(numeri.begin() + 1, 0); // Il vettore diventa: {100, 0, 20, 50}
    cout << "Dopo aver inserito '0' all'indice 1: ";
    for (int n : numeri) cout << n << " ";
    cout << "\n\n";

    // ERASE: Elimina un elemento a un indice specifico
    cout << "=== 5. Test erase() ===\n";
    numeri.erase(numeri.begin() + 1); // Rimuove lo 0 appena messo. Torna: {100, 20, 50}
    cout << "Dopo aver cancellato l'elemento all'indice 1: ";
    for (int n : numeri) cout << n << " ";
    cout << "\n\n";

    // Chiamata alla funzione prima di svuotarlo
    cout << "=== 6. Test Passaggio a Funzione ===\n";
    prova(numeri);
    cout << "\n";

    // CLEAR: Svuota totalmente il vettore
    cout << "=== 7. Test clear() ===\n";
    numeri.clear(); // La dimensione diventa 0
    cout << "Dimensione dopo clear(): " << numeri.size() << "\n";
    
    // CORRETTO: Non facciamo numeri[0] perché crasherebbe! Usiamo un controllo sicuro:
    if (numeri.empty()) {
        cout << "Vettore svuotato con successo. Operazione sicura!\n\n";
    }

    // Chiamata finale alla funzione con vettore vuoto
    prova(numeri);

    return 0;
}