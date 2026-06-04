#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[7];
    int numero = 0;
    
    for(int k = 0; k < 8; k++){
        printf("Inserisci nei numeri reali: \n");
        scanf("%d", &numero);
        array[k] = numero;
    }

    for(int i = 0; i < 8; i++){
        printf("La lettura del array: %d\n", array[i]);
    }

    int cuont = 0;
    for (int i = 0; i < 7; i++){
        if(array[i] == 0){
            cuont++;
        }
    }
    printf("Nel array ci sono un totale di zeri: %d\n", cuont);
    

    return 0;
}