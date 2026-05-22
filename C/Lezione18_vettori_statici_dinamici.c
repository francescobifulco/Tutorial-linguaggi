#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // FONDAMENTALE: Serve per usare la funzione time()

// Lezione 18: Gli arrey (Statici, Dinamici)
int main(){

    // Inizializziamo il generatore di numeri casuali usando l'ora attuale
    srand((unsigned int)time(NULL));
    
    // ==========================================
    // 1. ARRAY STATICI (Allocati nello STACK)
    // ==========================================
    
    printf("--- [PARTE 1] Array Statico ---\n");
    
    // Dimensione fissa decisa prima di avviare il programma. Non può cambiare!
    int arr_statico[10];

    // Riempimento dell'array statico con numeri casuali da 1 a 100
    for(int i = 0; i < 10; i++){
        arr_statico[i] = rand() % 100 + 1;
    }

    // Stampa dell'array statico
    printf("Contenuto di arr_statico: ");
    for (int i = 0; i < 10; i++){
        printf("[%d] ", arr_statico[i]);
    }
    printf("\n\n");

    // ==========================================
    // 2. ARRAY DINAMICI (Allocati nell'HEAP)
    // ==========================================
    printf("--- [PARTE 2] Array Dinamico ---\n");

    int numero;
    printf("Quanti elementi vuoi inserire nell'array dinamico? ");
    // Aggiunta la '&' per salvare correttamente l'input dell'utente
    scanf("%d", &numero); 

    if (numero <= 0) {
        printf("Numero non valido. Uscita.\n");
        return 1;
    }

    // Allocazione con MALLOC (Memory Allocation)
    // Lascia la memoria sporca con i vecchi dati presenti in quel blocco.
    int* arr_dinamico_malloc = (int*)malloc(numero * sizeof(int));

    // Allocazione con CALLOC (Clear Allocation)
    // Sintassi corretta: calloc(numero_elementi, dimensione_singolo_elemento)
    // Vantaggio: calloc azzera automaticamente tutti i valori portandoli a 0!
    int* arr_dinamico_calloc = (int*)calloc(numero, sizeof(int));

    // Controllo di sicurezza: se la memoria è piena, malloc/calloc restituiscono NULL
    if (arr_dinamico_malloc == NULL || arr_dinamico_calloc == NULL) {
        printf("Errore: Memoria insufficiente!\n");
        return 1;
    }

    // Riempimento e stampa dell'array dinamico creato con malloc
    for (int i = 0; i < numero; i++) {
        arr_dinamico_malloc[i] = rand() % 100 + 1;
    }

    printf("Contenuto di arr_dinamico_malloc: ");
    for (int i = 0; i < numero; i++) {
        printf("[%d] ", arr_dinamico_malloc[i]);
    }
    printf("\n");

    // Mostriamo che calloc ha azzerato la memoria inizialmente (prima di inserire dati)
    printf("Contenuto iniziale di arr_dinamico_calloc (pulito a 0): ");
    for (int i = 0; i < numero; i++) {
        printf("[%d] ", arr_dinamico_calloc[i]);
    }
    printf("\n\n");


    // FONDAMENTALE: Liberiamo la memoria dinamica occupata nell'Heap prima di chiudere il programma
    free(arr_dinamico_malloc);
    free(arr_dinamico_calloc);
    
    printf("--- Memoria dinamica liberata correttamente. ---\n");

    return 0;
    
}