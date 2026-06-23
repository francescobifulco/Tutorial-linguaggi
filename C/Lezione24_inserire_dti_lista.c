#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct prodotto{
    char nome[50];
    char categoria[50];
    float prezzo;
    int qualita;
    int id;
    struct prodotto* next;
} prodotto;

//Modificata la condizione per stampare anche l'ultimo elemento
void stampaLista(prodotto* current) {
    if (current == NULL) {
        printf("La lista e' vuota.\n");
        return;
    }

    printf("\n=================================================================================\n");
    printf("%-6s | %-15s | %-15s | %-10s | %-10s\n", "ID", "NOME", "CATEGORIA", "QUALITA'", "PREZZO");
    printf("=================================================================================\n");
    
    // si ferma quando current stesso diventa NULL
    while (current != NULL) {
        // Rimosse tutte le '&' che rompevano la printf
        printf("%-6d | %-15s | %-15s | %-10d | %-10.2f €\n", 
               current->id, current->nome, current->categoria, current->qualita, current->prezzo);
        
        current = current->next; // Spostamento al nodo successivo
    }
    printf("=================================================================================\n\n");
}

// Lezione 24: Come inserire dati in una lista da un file in C
int main(){
    
    FILE* f = fopen("dati.txt", "r");

    // Controllo di sicurezza sul file
    if (f == NULL) {
        printf("[ERRORE] Impossibile aprire 'dati.txt'. Assicurati che il file esista!\n");
        return 1;
    }

    prodotto* head = (prodotto*)malloc(sizeof(prodotto));
    prodotto* current = head;
    prodotto* previous = NULL;

    printf("--- Caricamento dati da file in corso... ---\n");

    while (fscanf(f, "%s %s %f %d %d\n", 
        current->nome, 
        current->categoria, 
        current->prezzo, 
        current->qualita, 
        current->id) == 5){
            current->next = (prodotto*)malloc(sizeof(prodotto));
            previous = current;
            current = current->next;
        }

    // Gestione della coda della lista e pulizia dell'ultimo nodo vuoto allocato in eccesso
    if (previous != NULL) {
        previous->next = NULL; 
        free(current); // Libera l'ultimo blocco vuoto creato dal while prima di uscire
    } else {
        // Se il file era totalmente vuoto, anche la head va liberata
        free(head);
        head = NULL;
    }

    fclose(f); // Chiudiamo il file!
    printf("[OK] File letto con successo.\n");

    // Mostriamo la tabella dei prodotti
    stampaLista(head);

    // ==========================================
    // LIBERAZIONE DELLA MEMORIA HEAP
    // ==========================================
    prodotto* temp;
    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }
    printf("[DEBUG] Memoria di tutti i nodi liberata correttamente.\n");

    return 0;
}