#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero1, numero2, scelta;

    printf("Inserisci un numero: \n");
    scanf("%d", &numero1);

    printf("Inserisci un numero: \n");
    scanf("%d", &numero2);

    printf("Inserisci un operazione [1] '+', [2] '-', [3] '*', [4] '/': \n");
    scanf("%d", &scelta);

    if (scelta == 1){
        int somma = numero1 + numero2;
        printf("La somma tra i due numeri (%d + %d) e: %d\n", numero1, numero2, somma);
    }else if (scelta == 2){
        int sotrazione = numero1 - numero2;
        printf("La sotrazione tra i due numeri (%d - %d) e: %d\n", numero1, numero2, sotrazione);
    }else if (scelta == 3){
        int moltiplicazione = numero1 * numero2;
        printf("La moltiplicazione tra i due numeri (%d * %d) e: %d\n", numero1, numero2, moltiplicazione);
    }else if (scelta == 4){
        if(numero2 != 0){
            float divisione = numero1 + numero2;
            printf("La divisione tra i due numeri (%d / %d) e: %d\n", numero1, numero2, divisione);
        }else {
            printf("Errore: Impossibile dividere un numero per zero!\n");
        }     
    }else {
        printf("Operazione non trovato");
    }

    return 0;
}