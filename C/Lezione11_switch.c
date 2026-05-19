#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lezione 11: Il costrutto SWITCH, lo Switch interattivo con input dell'utente
int main()
{
    int a = 1;

    printf("--- Test del Costrutto Switch ---\n\n");

    // Lo switch valuta la variabile 'a' e salta direttamente al 'case' corrispondente
    switch (a) {
        case 1:
            printf("[Case 1] La variabile 'a' vale esattamente 1!\n");
            break; // FONDAMENTALE: esce dallo switch. Se lo togli, il C esegue anche i case successivi!
            
        case 2:
            printf("[Case 2] La variabile 'a' vale esattamente 2!\n");
            break;
            
        case 3:
            printf("[Case 3] La variabile 'a' vale esattamente 3!\n");
            break;
            
        default: // Si attiva solo se nessuno dei case precedenti è risultato vero
            printf("[Default] Il valore di 'a' non e' ne' 1, ne' 2, ne' 3.\n");
            break; // Il break qui è opzionale perché è l'ultima riga, ma metterlo è un'ottima abitudine
    }

    int scelta; // Variabile vuota che conterrà la scelta dell'utente

    // Chiediamo all'utente di inserire un numero da tastiera
    printf("=== MENU DI SELEZIONE ===\n");
    printf("Inserisci un numero (1, 2 o 3): ");
    scanf("%d", &scelta); // Ricorda la '&' per salvare il valore in memoria!

    printf("\n--- Risultato dello Switch ---\n");

    // Lo switch ora valuta dinamicamente il numero inserito dall'utente
    switch (scelta) {
        case 1:
            printf("[Opzione 1] Hai premuto 1! Benvenuto nella prima funzionalità.\n");
            break; // Esce dallo switch
            
        case 2:
            printf("[Opzione 2] Hai premuto 2! Questa e' la seconda funzionalità.\n");
            break; // Esce dallo switch
            
        case 3:
            printf("[Opzione 3] Hai premuto 3! Attivazione della terza opzione.\n");
            break; // Esce dallo switch
            
        default: 
            // Questa riga si attiva se l'utente scrive qualsiasi numero diverso da 1, 2 o 3 (es: 0, 5, -10...)
            printf("[Errore] Il numero %d non e' presente nel menu!\n", scelta);
            break; 
    }

    return 0;
}