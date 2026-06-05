#include <iostream>

// Lezione 3: Le variabili in C++
int main(){

    // 1. DICHIARAZIONE: Diciamo al computer di riservare uno 
    // spazio in memoria per un numero intero (int) chiamato 'eta'.
    int eta;

    // 2. ASGNAZIONE: Diamo un valore alla 
    // variabile precedentemente dichiarata usando l'operatore '='.
    eta = 24; 

    // 3. INIZIALIZZAZIONE: Facciamo dichiarazione e 
    // assegnazione nello stesso momento, sulla stessa riga.
    int eta_padre = 45;

    // STAMPE CON CONCATENAZIONE
    // Usiamo l'operatore '<<' per unire (concatenare) 
    // il testo statico con il valore dinamico della variabile.
    std::cout << "Ciao, ho " << eta << " anni.\n";
    std::cout << "Ho " << eta << " anni dallo scorso anno.\n";
    std::cout << "Anche tu hai " << eta << " anni?\n";

    // MODIFICA DEL VALORE (Riassegnazione)
    // Le variabili possono cambiare valore durante l'esecuzione 
    // del programma. Il vecchio valore (24) viene sovrascritto
    eta = 26;
    std::cout << "Anzi no, ci ho ripensato: ora ho " << eta << " anni!\n";

    // Nota: puoi usare anche la variabile 'eta_padre' per 
    // fare una prova di stampa!
    std::cout << "Mio padre invece ha " << eta_padre << " anni.\n";

    return 0;
}