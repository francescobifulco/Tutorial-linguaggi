#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Funzioni.h" // Include l'indice delle nostre funzioni personalizzate

// Lezione 15: File di intestazione 
int main() {
    int a = 10, b = 20;

    printf("--- [MAIN] Avvio del programma ---\n");
    printf("Valori di partenza -> a: %d, b: %d\n", a, b);

    // Chiamata alla funzione esterna
    int somma = somma_numeri(a, b);

    // Stampa del risultato finale
    printf("Risultato della somma da file esterno: %d\n", somma);
    printf("--- [MAIN] Fine del programma ---\n");

    return 0;
}