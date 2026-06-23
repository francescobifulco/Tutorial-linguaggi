#include <iostream>
#include <string>
#include <typeinfo>

using std::cin;
using std::cout;
using std::string;

// --- 1. SCOPE GLOBALE ---
// Questa variabile è dichiarata fuori da ogni funzione. 
// È visibile OVUNQUE nel file, dal main a qualsiasi 
// altra funzione, per tutta la durata del programma.
int variabileGlobale = 90;

// --- 2. SCOPE DI FUNZIONE ---
int somma(int x, int y){
    // variabileFunzione e i parametri x e y nascono quando 
    // la funzione viene chiamata 
    // e VENGONO DISTRUTTI non appena la funzione arriva al 'return'.
    int variabileFunzione = 5;
    cout << "[Dentro somma()] variabileFunzione = " << variabileFunzione << "\n";
    return variabileFunzione;
}

// Lezione 21: La gestione dello scope delle variabili in C++
int main() {
    std::setlocale(LC_ALL, "it_IT.utf8");

    // --- 3. SCOPE LOCALE (DI METODO/MAIN) ---
    // Queste variabili sono visibili all'interno di tutto il main, 
    // anche dentro i blocchi interni (if, cicli).
    int variabileMain = 30;
    int variabileProva;

    cout << "=== Test Scope delle Variabili ===\n\n";

    // --- 4. SCOPE DI BLOCCO (Graffe anonime) ---
    {
        int variabileBlocco = 5;
        // variabileBlocco esiste SOLO dentro queste graffe.
        cout << "[Blocco Anonimo] variabileBlocco = " << variabileBlocco << "\n";
    }
    // Se provassi a scrivere: cout << variabileBlocco; qui fuori, 
    // il compilatore darebbe ERRORE!
    // variabileBlocco a questo punto è già stata cancellata dalla memoria.

    // --- 5. SCOPE DI BLOCCO (Strutture di controllo come IF o Cicli) ---
    if(5 < 10){
        int variabileIF = 10; // Nasce e muore dentro questo IF
        variabileProva = 50;  // Modifica una variabile esterna (si può fare perché variabileProva è locale al main)
       
        cout << "[Dentro IF] variabileMain (esterna) = " << variabileMain << "\n";
        cout << "[Dentro IF] variabileIF (interna) = " << variabileIF << "\n";
        cout << "[Dentro IF] variabileProva (modificata) = " << variabileProva << "\n";
    }
    // Se provassi a scrivere: cout << variabileIF; qui fuori, darebbe ERRORE!


    // --- VERIFICHE FINALI ---
    cout << "\n[Main] variabileGlobale = " << variabileGlobale << "\n";
    
    cout << "\n[Chiamata 1 a somma()]\n";
    somma(1, 2);
    
    cout << "\n[Chiamata 2 a somma()]\n";
    somma(variabileMain, 5);
    return 0;
}