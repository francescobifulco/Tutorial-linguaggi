#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// Lezione 8: Condizione IF, ELSE e Operatori di confronto
int main() {
    
    int a = 12; 
    int ab = 11;

    printf("--- Blocchi IF Indipendenti ---\n");

    // 12 < 11 -> FALSO (Non stampa nulla)
    if (a < ab) {
        printf("hey!!!!\n");
    }

    // 12 > 11 -> VERO (Stampa il messaggio)
    if (a > ab) {
        printf("hey ciao!\n");
    }

    // 12 >= 11 -> VERO (12 è maggiore o uguale a 11, quindi stampa)
    if (a >= ab) {
        printf("hey come va!!\n");
    }

    // 12 <= 11 -> FALSO (Non stampa nulla)
    if (a <= ab) {
        printf("hey che fai!!\n");
    }

    // 12 == 11 -> FALSO (Il doppio uguale '==' serve per controllare l'uguaglianza)
    if (a == ab) {
        printf("ciao, mondo\n");
    }


    printf("\n--- Catena IF / ELSE IF / ELSE ---\n");
    // Regola d'oro: In una catena, viene eseguito SOLO il primo blocco vero, 
    // dopodiché il programma salta direttamente alla fine della catena.

    if (a == ab) {
        // 12 == 11 -> FALSO (Salta al prossimo)
        printf("Primo messaggio\n");
    } 
    else if (a < ab) {
        // 12 < 11 -> FALSO (Salta al prossimo)
        printf("Secondo messaggio\n");
    } 
    else if (a != ab) {
        // 12 != 11 -> VERO (12 è diverso da 11!). 
        // Questo blocco viene eseguito e la catena si ferma qui.
        printf("messaggio diverso\n");
    } 
    else {
        // Questo blocco (l'ultimo baluardo) viene ignorato perché 
        // la condizione precedente era già vera.
        printf("Terzo messaggio\n");
    }

    return 0;
}