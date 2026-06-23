#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Wrapper.h"

// Progetto: La gestione delle librerie in C
int main(){

    // Chiamata per verificare ed eventualmente creare i file di testo necessari
    creareFileNoEsiste();

    printMenu();    
    
    return 0;
}