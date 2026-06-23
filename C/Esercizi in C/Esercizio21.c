#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[8];
    int numero = 0;
    
    for(int k = 0; k < 8; k++){
        printf("Inserisci nei numeri reali: \n");
        scanf("%d", &numero);
        array[k] = numero;
    }

    for(int i = 0; i < 8; i++){
        printf("La lettura del array: %d\n", array[i]);
    }
    
    int somma = 0;
    float media;

    for(int j = 0; j < 8; j++){
        somma = array[j] + somma;
    }
    printf("La somma totale del array: %d\n", somma);
    media = (float) somma / 8;
    printf("La media dei valori del array: %.4f\n", media);

}