#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero = 0;
    int somma = 0;
    while (numero >= 0){
        printf("Inserisci un numero positivo: \n");
        scanf("%d", &numero);

        if (numero < 0) {
            break;
        }

        somma = numero + somma;
    }
    printf("La somma totale e: %d\n", somma);
    
    return 0;
}