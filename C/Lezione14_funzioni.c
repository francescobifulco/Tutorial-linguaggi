#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

// 1. Funzione VOID senza parametri
// Non richiede dati in ingresso e non restituisce nulla al main (void = vuoto)
void stampaCiao()
{
    printf("--- Esecuzione stampaCiao ---\n");

    for (int i = 0; i < 5; i++)
    {
        printf("Ciao: %d\n", i);
    }
    printf("\n");
}

// 2. Funzione VOID con parametri
// Riceve due numeri, stampa direttamente il risultato, ma non "restituisce" il valore al main
void stampaSomma(int a, int b)
{
    printf("--- Esecuzione stampaSomma (void) ---\n");

    int somma = a + b;
    printf("La somma stampata direttamente e': %d\n\n", somma);
}

// 3. Funzione con VALORE DI RITORNO (int)
// Riceve due numeri, fa dei calcoli e "sputa fuori" un intero usando la parola chiave 'return'
int stampaSommaInt(int a, int b)
{
    // NOTA LOGICA: Sovrascrivendo 'a' e 'b' qui dentro, i valori 10 e 90 passati dal main
    // vengono ignorati e sostituiti da 3 e 17.
    a = 3;
    b = 17;
    int somma = a + b;

    return somma; // Restituisce 20 al main
}

// Lezione 14: Le funzioni
int main()
{

    // Chiamata alla prima funzione
    stampaCiao();

    int a = 10;
    int b = 90;

    // Chiamata alla seconda funzione (quella che avevi dimenticato di testare!)
    stampaSomma(a, b); // Passa 10 e 90 -> Stamperà 100

    printf("--- Esecuzione stampaSommaInt (con return) ---\n");
    // Chiamiamo la terza funzione e salviamo il suo 'return' dentro la variabile somma1
    int somma1 = stampaSommaInt(a, b);

    // DIMOSTRAZIONE DEL PASSAGGIO PER VALORE:
    // Anche se dentro 'stampaSommaInt' abbiamo cambiato a e b in 3 e 17,
    // le variabili 'a' e 'b' del main sono rimaste intatte (10 e 90)!
    printf("Valori nel main dopo la funzione -> a: %d, b: %d\n", a, b);

    // Stampa il valore che la funzione ci ha restituito (3 + 17 = 20)
    printf("Valore restituito dalla funzione (somma1): %d\n", somma1);

    return 0;
}