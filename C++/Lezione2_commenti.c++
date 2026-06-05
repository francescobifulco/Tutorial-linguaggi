#include <iostream>

// Lezione 2: I commenti in C++
int main(){

    std::cout << "Ciao sono francy\n";

    // 1. COMMENTO SU RIGA SINGOLA (Single-line comment)
    // Si usano due barre oblique (//). Tutto ciò che scrivi dopo le barre, 
    // fino alla fine della riga, viene completamente ignorato dal compilatore.
    // Utile per brevi spiegazioni o per "spegnere" temporaneamente una riga di codice.
    
    // Questo è un commento su una riga

    /* 2. COMMENTO SU PIÙ RIGHE (Multi-line comment)
       Si apre con barra e asterisco (/*) e si chiude con asterisco e barra.
       Tutto ciò che si trova all'interno di questo blocco viene ignorato.
       È l'ideale per spiegazioni lunghe, documentazione o per escludere
       intere porzioni di codice durante i test. */

    /* Invece questo è un 
       commento su più righe */
    std::cout << "Mi piace la programmazione\n";

    return 0;
}