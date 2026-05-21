#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lezione 12: I cilci (While, Do-While, For)
int main() {
    int  contatore = 0;

    printf("--- 1. INIZIO CICLO WHILE ---\n");

    while (contatore < 7){
        // Il 'while' controlla PRIMA la condizione. Se è vera entra, altrimenti no.
        printf("Giro [%d]: ciao mondo sono dentro il ciclo while\n", contatore);
        contatore++; // Incremento fondamentale per evitare un ciclo infinito!
    }

    printf("Fine del ciclo while. Valore attuale di contatore: %d\n\n", contatore);

    printf("--- 2. INIZIO CICLO DO-WHILE ---\n");
    
    int contare = 0;

    // Il 'do-while' esegue il codice ALMENO una volta, poi controlla la condizione in fondo.
    do{
        printf("Giro [%d]: ciao mondo sono dentro il ciclo do-while\n", contare);
        contare++;
    } while (contare < 7);
    
    printf("fine del cilco do while\n"); // Attenzione al punto e virgola ';' alla fine, qui è obbligatorio!
    
    for (int i = 0; i < contatore; i++){
        printf("ciao mondo sono dentro il ciclo di for\n");
    }
    
    printf("fine del cilco for\n");
    
    return 0;
}