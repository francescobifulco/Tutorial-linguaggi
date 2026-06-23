#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// Funzione che accetta un puntatore a intero come parametro
void funzione(int* x) {
    // Modifichiamo direttamente il valore presente a quell'indirizzo di memoria
    *x = 50; 
}

// Lezione 23: La gestione dei puntatori in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    int prova = 5;

    // Dichiarazione di un puntatore a intero. 
    // Ottima pratica inizializzarlo a nullptr 
    // (puntamento a zero/nullo) anziché lasciarlo "finto".
    int* ptr_prova = nullptr;
    
    // Assegnazione: ptr_prova adesso CONTIENE l'indirizzo di memoria di 'prova'
    ptr_prova = &prova;

    cout << "=== 1. Lettura dei Valori e degli Indirizzi ===\n";
    cout << "Valore di 'prova': " << prova << "\n";
    cout << "Indirizzo di memoria di 'prova' (&prova): " << &prova << "\n";
    cout << "Valore dentro 'ptr_prova' (l'indirizzo): " << ptr_prova << "\n";
    cout << "Valore dereferenziato (*ptr_prova): " << *ptr_prova << "\n\n";

    cout << "=== 2. Modifica tramite Puntatore ===\n";
    // Accediamo alla cella di memoria e sovrascriviamo il valore
    *ptr_prova = 200;
    cout << "Nuovo valore di 'prova' dopo (*ptr_prova = 200): " << prova << "\n\n";

    cout << "=== 3. Passaggio del Puntatore a una Funzione ===\n";
    // Passiamo l'indirizzo di memoria di 'prova' alla funzione
    funzione(&prova);
    cout << "Valore di 'prova' dopo la chiamata a funzione(&prova): " << prova << "\n";

    return 0;
}