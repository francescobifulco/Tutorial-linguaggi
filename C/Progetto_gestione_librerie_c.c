#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Wrapper.h"

// Progetto: La gestione delle librerie in C
int main(){
    creareFileNoEsiste();

    printf("Inserisci il numero: \n");
    printf("[1] Inserisci prestiti: \n");
    printf("[2] Inserisci restituzioni: \n");
    printf("[3] Stampa prestiti: \n");
    printf("[4] stampa restituzioni: \n");

    int scelta = 0;

    scanf("%d\n", scelta);

    return 0;
}