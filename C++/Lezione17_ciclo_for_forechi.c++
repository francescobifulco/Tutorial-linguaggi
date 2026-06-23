#include <iostream>
#include <string>
#include <typeinfo>
#include <vector> // Libreria fondamentale per usare i vettori dinamici

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Lezione 17: La gestione del ciclo for e range-based for (foreach) in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    // --- 1. CICLO FOR TRADIZIONALE SU STRINGA ---
    // Ideale quando serve l'indice numerico (i) per 
    // sapere in che posizione ci troviamo.
    cout << "=== 1. For Tradizionale su Stringa ===\n";
    string cognome = "rossi";
    for (int i = 0; i < cognome.length(); i++){
        cout << "Indice [" << i << "] - Il carattere e': " << cognome[i] << "\n";
    }
    cout << "\n";
    
    // --- 2. CICLO FOR CONTATORE STANDARD ---
    cout << "=== 2. For con Contatore Numerico ===\n";
    for (int i = 0; i < 5; i++){
        cout << "Questa e' l'iterazione numero del ciclo for: " << i << "\n";
    }
    cout << "\n";

    // --- 3. RANGE-BASED FOR (FOREACH) SU STRINGA ---
    // Sintassi: for (tipo_elemento variabile : contenitore)
    // Più compatto: non serve gestire l'indice, 
    // estrae un carattere alla volta automaticamente.
    cout << "=== 3. Range-based For (Foreach) su Stringa ===\n";
    string nome  = "luca";

    for(char carattere : nome){
        cout << "Carattere estratto: " << carattere << "\n";
    }
    cout << "\n";

    // --- 4. FOR TRADIZIONALE SU VECTOR ---
    // Usiamo .size() per ottenere il numero di elementi contenuti nel vettore.
    cout << "=== 4. For Tradizionale su Vector ===\n";
    vector<int> numeri = {10, 20, 30, 40};

    for (int i = 0; i < numeri.size(); i++){
        cout << "Indice [" << i << "] - Il valore e': " << numeri[i] << "\n";
    }
    cout << "\n";
    
    // --- 5. RANGE-BASED FOR (FOREACH) SU VECTOR ---
    // Il modo più moderno e pulito per scorrere una 
    // collezione se non ti serve l'indice 'i'.
    cout << "=== 5. Range-based For (Foreach) su Vector ===\n";
    for(int numero : numeri){
       cout << "Valore estratto dal foreach: " << numero << "\n";
    }

    return 0;
}