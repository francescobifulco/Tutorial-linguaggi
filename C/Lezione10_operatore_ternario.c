#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// Lezione 10: Operatore Ternario e precedenze logiche
int main() {
    int a = 10;
    int b = 20;
    int c = 15;

    printf("--- Test Precedenze Logiche Complesse ---\n\n");
    // RECOLA D'ORO: L'operatore && ha la precedenza rispetto all'operatore || (proprio come la moltiplicazione sulla somma)
    
    // Senza parentesi, il C calcola prima i due blocchi con &&:
    // Blocco 1: (a > b && b != a)      -> (10 > 20 && 20 != 10) -> FALSO && VERO = FALSO
    // Blocco 2: (c < a && b == a)      -> (15 < 10 && 20 == 10) -> FALSO && FALSO = FALSO
    // Infine fa l'OR: FALSO || FALSO   -> FALSO (Non stampa nulla)
    if (a > b && b != a || c < a && b == a){
        printf("[1] Condizione senza parentesi: VERA\n");
    }

    // Qui hai aggiunto le parentesi esplicite, ma poiché il && aveva già la precedenza,
    // il calcolo viene eseguito esattamente nello stesso ordine di prima -> FALSO (Non stampa nulla)
    if (a > b && b != a || (c < a && b == a)){
        printf("[2] Condizione con parentesi: VERA\n");
    }

    printf("--- Confronto: IF/ELSE classico vs Operatore Ternario ---\n\n");

    // Metodo 1: Il classico costrutto IF / ELSE
    if (a > b) { // 10 > 20 -> FALSO
        printf("[IF/ELSE] ciao\n");
    } else {
        printf("[IF/ELSE] NON ciao\n"); // Si attiva questo
    }

    // Metodo 2: L'Operatore Ternario ? :
    // Sintassi: (condizione) ? valore_se_vero : valore_se_falso;
    // In questo caso passiamo direttamente il risultato come stringa dentro la printf!
    printf("[TERNARIO] %s", (a > b) ? "ciao\n": "NON ciao\n");

    return 0;
}