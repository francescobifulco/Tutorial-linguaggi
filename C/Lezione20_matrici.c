#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Lezione 20: Le matrici (Statiche e Dinamiche)
int main(){
    // ==========================================
    // 1. MATRICE STATICA
    // ==========================================
    printf("--- [PARTE 1] Matrice Statica 3x3 ---\n");

    // Dichiarazione e inizializzazione di una matrice statica
    int matrice_statica[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Stampa della matrice statica utilizzando due cicli for annidati
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%d] ", matrice_statica[i][j]);
        }
        printf("\n"); // Va a capo alla fine di ogni riga
    }
    printf("\n");
    
    // ==========================================
    // 2. MATRICE DINAMICA (Allocazione nell'Heap)
    // ==========================================
    printf("--- [PARTE 2] Creazione Matrice Dinamica ---\n");

    int righe, colonne;
    printf("Inserisci il numero di righe e colonne: ");
    scanf("%d %d", &righe, &colonne);

    if (righe <= 0 || colonne <= 0) {
        printf("Dimensioni non valide.\n");
        return 1;
    }

    // 1. Allocazione del "vettore di puntatori" (le righe della tabella)
    // CORREZIONE: Cast corretto a (int**) e parametri ordinati per calloc
    int** matrice_dinamica = (int**)calloc(righe * sizeof(int*), righe);

    if (matrice_dinamica == NULL) {
        printf("Errore di allocazione memoria principale!\n");
        return 1;
    }

    // 2. Allocazione di un array di interi per ogni riga (le colonne)
    // CORREZIONE: Il ciclo gira fino a 'righe' e assegna lo spazio a ciascun elemento della matrice
    for (int i = 0; i < righe; i++) {
        matrice_dinamica[i] = (int*)calloc(colonne, sizeof(int));
        
        // Controllo sicurezza allocazione singola riga
        if (matrice_dinamica[i] == NULL) {
            printf("Errore di allocazione alla riga %d!\n", i);
            return 1;
        }
    }

    // Riempiamo la matrice dinamica con qualche valore di esempio (es. tabellina i * j)
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            matrice_dinamica[i][j] = (i + 1) * (j + 1);
        }
    }

    // Stampa della matrice dinamica
    printf("\nVisualizzazione Matrice Dinamica %dx%d:\n", righe, colonne);
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) { // CORREZIONE: Sistemati gli indici del ciclo interno
            printf("[%2d] ", matrice_dinamica[i][j]); // '%2d' serve a incolonnare bene i numeri
        }
        printf("\n");
    }

    // ==========================================
    // 3. LIBERAZIONE DELLA MEMORIA (FONDAMENTALE)
    // ==========================================
    // Si procede al contrario rispetto all'allocazione:
    // Prima eliminiamo i singoli pavimenti (le righe)...
    for (int i = 0; i < righe; i++) {
        free(matrice_dinamica[i]);
    }
    // ...e infine demoliamo l'edificio intero (il puntatore a puntatori)
    free(matrice_dinamica);

    printf("\n--- Memoria della matrice dinamica liberata correttamente. ---\n");

    return 0;
}