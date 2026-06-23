#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// La funzione accetta un PUNTATORE a intero (int* a) e un intero normale (int b)
int stampaSomma(int* a, int b){
    // Modifica il valore all'indirizzo puntato da 'a'. 
    // Questa modifica cambierà permanentemente la 'a' del main!
    *a = 3;
    printf("Indirizzo memorizzato nel puntatore 'a': %p\n", (void*)a);
    
    // Modifica la variabile locale 'b' (che è solo una copia di quella del main)
    b = 17;
    printf("Indirizzo della variabile locale 'b' (nello stack della funzione): %p\n", (void*)&b);
    printf("Valore della variabile locale 'b': %d\n", b);

    // Prendiamo il VALORE dentro 'a' usando *a (quindi 3) e lo sommiamo a b (17)
    int somma = *a + b;
    return somma;
}

// Lezione 16: Puntatori e i riferimenti
int main() {

    int a = 10;
    int b = 90;

    // Creiamo un puntatore che "punta" all'indirizzo di memoria della variabile 'a'
    int* ptr = &a;

    printf("--- [MAIN] Stato iniziale delle variabili ---\n");
    // CORREZIONE SINTASSI: Separati correttamente gli argomenti della printf
    printf("Valore di a: %d | Indirizzo di a (&a): %p | Valore del puntatore (ptr): %p\n\n", a, (void*)&a, (void*)ptr);

    // CORREZIONE CHIAMATA: Passiamo l'indirizzo di 'a' (&a oppure ptr) e il valore di 'b'
    int risultato = stampaSomma(&a, b);
    
    printf("\n--- [MAIN] Stato finale dopo la funzione ---\n");
    // NOTA IL MIRACOLO: 'a' è diventata 3 perché la funzione ha agito direttamente sulla sua memoria!
    // 'b' invece è rimasta 90 perché era stata passata solo come copia (valore).
    printf("Valore finale di a (modificata via puntatore): %d\n", a);
    printf("Valore finale di b (rimasta intatta): %d\n", b);
    printf("Risultato restituito dalla funzione: %d\n", risultato);
    
    return 0;
}