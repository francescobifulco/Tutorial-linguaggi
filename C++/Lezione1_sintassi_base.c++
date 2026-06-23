// L'istruzione #include serve a inserire nel programma le funzionalità di una libreria.
// 'iostream' (Input-Output Stream) è la libreria standard che permette di stampare a schermo e ricevere input.
#include <iostream>

// Lezione 1: La sintassi base di C++

// Ogni programma C++ deve avere una funzione chiamata 'main'.
// È il punto di partenza (l'entry point) da cui il computer inizia a eseguire il codice.
int main(){

    // 'std::cout' significa "Character Output" ed è l'oggetto usato per stampare testo.
    // L'operatore '<<' indica la direzione dei dati (manda la stringa verso l'output).
    // '\n' serve per andare a capo alla fine della frase, rendendo il terminale pulito.
    std::cout<<"Ciao sono francy\n";

    // 'return 0;' comunica al sistema operativo che il programma è terminato con successo.
    // Nello standard dei computer, lo zero significa "nessun errore".
    return 0;
}