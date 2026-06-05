#include <iostream>

// Lezione 4: Le costanti in C++
int main(){
    // DICHIARAZIONE DI COSTANTI
    // Si usa la parola chiave 'const' prima del tipo di dato.
    // Per convenzione (buona pratica), i nomi delle costanti 
    // si scrivono in MAIUSCOLO.
    const int ETA_MASSIMA = 120;
    const int VALORE = 32;

    // STAMPA DEI VALORI
    // Possiamo stampare le costanti esattamente come facciamo con le variabili.
    std::cout << "L'eta massima consentita nel sistema e': " << ETA_MASSIMA << " anni.\n";
    std::cout << "Il valore base di configurazione e': " << VALORE << ".\n";

    // COSA SUCCEDE SE PROVI A MODIFICARE UNA COSTANTE?
    // Se decommenti la riga qui sotto, il compilatore generera' un 
    // ERRORE (error: assignment of read-only variable).
    // ETA_MASSIMA = 130; 

    /* NOTA IMPORTANTE:
       Le costanti devono essere obbligatoriamente inizializzate 
       nel momento in cui vengono create.
       Scrivere:
       const int MIA_COSTANTE;
       MIA_COSTANTE = 10;
       Provochera' un errore di compilazione. */

    return 0;
}