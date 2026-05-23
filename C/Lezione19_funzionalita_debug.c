#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // FONDAMENTALE: per usare strlen e strcpy

void stampa(char* arch[], int sizeA) {
    printf("\n   [DEBUG - stampa] Indirizzi dei puntatori nell'array:\n");
    for (int i = 0; i < sizeA; i++) {
        // Stampiamo l'indirizzo del puntatore stesso e l'indirizzo della stringa puntata
        printf("   Elemento [%d] -> Indirizzo Slot: %p | Punta a: %p (%s)\n", 
               i, (void*)&arch[i], (void*)arch[i], arch[i]);
    }
}

// CORREZIONE: rimosso il duplicato 'int size' interno
void leggi(char* archivio[], int size) {
    printf("--- [FUNZIONE leggi] Stampa delle stringhe ---\n");
    for (int i = 0; i < size; i++) {
        printf("Archivio [%d]: %s\n", i, archivio[i]);
    }
    stampa(archivio, size);
}

void printArray(char* array[], int size) {
    printf("--- [FUNZIONE printArray] ---\n");
    for (int i = 0; i < size; i++) {
        // CORREZIONE: aggiunto '%s' che mancava nella printf
        printf("Parola [%d]: %s\n", i, array[i]); 
    }
    printf("\n");
}

// Lezione 19: Le funzionalità di Debug e gestione della memoria
int main() {

    printf("================ PARTE 1 =================\n");
    char* a[3] = {"alberello", "rosea", "roma"};
    leggi(a, 3);
    printf("\n");

    printf("================ PARTE 2 =================\n");
    char* words[] = {"mela", "banana", "cherry", "date"};
    int size = sizeof(words) / sizeof(words[0]);
    printArray(words, size);

    printf("================ PARTE 3 (Dinamica) =================\n");
    // CORREZIONE: Allocatati 4 slot invece di 3 per contenere in sicurezza anche il NULL alla fine
    char** dynamicWords = (char**)malloc(4 * sizeof(char*));
    
    if (dynamicWords == NULL) {
        printf("Errore di allocazione memoria!\n");
        return 1;
    }

    // CORREZIONE CRITICA: Uso di strcpy per non perdere il puntatore della malloc
    dynamicWords[0] = (char*)malloc(50 * sizeof(char));
    strcpy(dynamicWords[0], "grape");

    dynamicWords[1] = (char*)malloc(50 * sizeof(char));
    strcpy(dynamicWords[1], "kiwi");

    dynamicWords[2] = (char*)malloc(50 * sizeof(char));
    strcpy(dynamicWords[2], "melone");
    
    // Il terminatore NULL serve a fermare il ciclo for qui sotto
    dynamicWords[3] = NULL; 

    printf("Lettura delle parole allocate dinamicamente:\n");
    for (int i = 0; dynamicWords[i] != NULL; i++) {
        printf("DynamicWords [%d]: %s\n", i, dynamicWords[i]);
    }

    // CORREZIONE LIBERAZIONE MEMORIA: 
    // Prima si liberano i singoli cassetti (le stringhe)
    for (int i = 0; i < 3; i++) {
        free(dynamicWords[i]);
    }
    // Solo alla fine si libera l'armadio intero (l'array di puntatori)
    free(dynamicWords);
    
    printf("\n[DEBUG] Tutta la memoria dinamica e' stata liberata con successo.\n");
    
    return 0;
}