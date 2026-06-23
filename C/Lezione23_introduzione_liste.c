#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Diamo il nome 'prodotto' sia alla struct che all'alias finale
typedef struct prodotto{
    int ID;
    char nomeProdotto[50];
    struct prodotto* next; // Ora il compilatore capisce correttamente questo puntatore
}prodotto;

// Funzione utilissima per scorrere e stampare qualsiasi lista concatenata
void stampaLista(prodotto* nodoCorrente) {
    printf("--- [LISTA] Scorrimento dei nodi ---\n");
    int contatore = 1;
    
    // Il ciclo continua finché il puntatore non incontra il NULL (fine della lista)
    while (nodoCorrente != NULL) {
        printf("Nodo %d [Indirizzo: %p] -> ID: %d | Prodotto: %s | Successivo (next): %p\n", 
               contatore, (void*)nodoCorrente, nodoCorrente->ID, nodoCorrente->nomeProdotto, (void*)nodoCorrente->next);
        
        // Passiamo al nodo successivo modificando il puntatore!
        nodoCorrente = nodoCorrente->next; 
        contatore++;
    }
    printf("--- Fine della lista (Raggiunto il NULL) ---\n\n");
}

// Lezione 23: Introduzione delle liste in C
int main(){
    printf("--- [MAIN] Creazione della Lista Concatenata ---\n\n");

    // ==========================================
    // 1. ALLOCAZIONE DEL PRIMO NODO (HEAD)
    // ==========================================
    prodotto* head = (prodotto*)malloc(sizeof(prodotto));
    if (head == NULL) return 1; // Controllo memoria

    head->ID = 1;
    strcpy(head->nomeProdotto, "Alberello");
    
    // ==========================================
    // 2. ALLOCAZIONE E AGGANCIO DEL SECONDO NODO
    // ==========================================
    head->next = (prodotto*)malloc(sizeof(prodotto));
    if (head->next == NULL) return 1;

    head->next->ID = 2;
    strcpy(head->next->nomeProdotto, "Rosea");
    
    // ==========================================
    // 3. ALLOCAZIONE E AGGANCIO DEL TERZO NODO (CODA)
    // ==========================================
    // Per comodità di scrittura, possiamo agganciare un terzo nodo andando ancora più a fondo
    head->next->next = (prodotto*)malloc(sizeof(prodotto));
    if (head->next->next == NULL) return 1;

    head->next->next->ID = 3;
    strcpy(head->next->next->nomeProdotto, "Roma");
    
    // CORREZIONE CRITICA: L'ultimo elemento deve SEMPRE terminare con NULL!
    head->next->next->next = NULL; 

    // Chiamiamo la funzione per stampare tutta la catena partendo dalla testa (head)
    stampaLista(head);

    // ==========================================
    // 4. LIBERAZIONE DELLA MEMORIA (FONDAMENTALE)
    // ==========================================
    // Non possiamo fare free(head) subito, altrimenti perderemmo i puntatori ai nodi successivi!
    // Bisogna liberarli uno a uno salvando l'indirizzo del successivo.
    prodotto* temp;
    while (head != NULL) {
        temp = head->next; // Salviamo l'indirizzo del prossimo nodo
        free(head);        // Liberiamo il nodo corrente
        head = temp;       // Ci spostiamo sul prossimo
    }
    
    printf("[DEBUG] Memoria di tutti i nodi liberata con successo.\n");

    return 0;
}