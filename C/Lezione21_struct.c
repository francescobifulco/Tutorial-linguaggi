#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Incluso per gestire correttamente le stringhe se necessario

// Definizione della struttura con sintassi typedef corretta
typedef struct{
    char nome[50];
    char cognome[50];
    int eta;
    char genere;
}Persona; // Il nome del tipo va posizionato qui alla fine;


// Lezione 21: Le Struct
int main() {

    // ==========================================
    // 1. GESTIONE DI UNA SINGOLA STRUCT
    // ==========================================
    printf("--- [PARTE 1] Singola Istanza di Persona ---\n");

    // Inizializzazione rapida posizionale
    Persona p = {"Marco", "Rossi", 20, 'M'};

    // Accesso ai campi tramite l'operatore punto '.'
    printf("Nome: %s | Cognome: %s | Eta': %d | Genere: %c\n\n", 
            p.nome, p.cognome, p.eta, p.genere);
    
    // ==========================================
    // 2. VETTORE DINAMICO DI STRUCT (HEAP)
    // ==========================================
    printf("--- [PARTE 2] Vettore Dinamico di 10 Persone ---\n");

    //Parametro unico per malloc (moltiplicazione)
    Persona* vettore = (Persona*)malloc(10 * sizeof(Persona));

    // Controllo di sicurezza sulla memoria
    if (vettore == NULL) {
        printf("Errore di allocazione della memoria!\n");
        return 1;
    }

    // Riempimento del vettore usando i Compound Literals
    for (int i = 0; i < 10; i++) {
        // Usiamo l'indice i per differenziare l'età e mostrare che cambiano
        vettore[i] = (Persona){"Mario", "Rossi", 20 + i, 'M'};
    }

    // Stampa del vettore dinamico
    for (int i = 0; i < 10; i++) {
        // Quando usi l'indice [i], accedi alla struct reale, quindi usi il punto '.'
        printf("Vettore[%d] -> %s %s, Anni: %d, Sesso: %c\n", 
                i, vettore[i].nome, vettore[i].cognome, vettore[i].eta, vettore[i].genere);
    }
    printf("\n");


    // ==========================================
    // 3. SINTASSI FRECCIA '->' PER I PUNTATORI
    // ==========================================
    printf("--- [PARTE 3] Accesso tramite Puntatore ---\n");
    
    // Creiamo un puntatore che punta alla nostra prima singola persona 'p'
    Persona* ptr_persona = &p;

    // RECOLA D'ORO: Se hai una struct normale usi il punto (p.nome)
    // Se hai un PUNTATORE a una struct, usi la freccia (ptr_persona->nome)
    printf("Accesso con freccia -> Nome: %s, Cognome: %s\n", 
            ptr_persona->nome, ptr_persona->cognome);


    // Liberazione della memoria allocata nell'Heap
    free(vettore);
    printf("\n--- Memoria del vettore liberata correttamente. ---\n");

    return 0;
    
}