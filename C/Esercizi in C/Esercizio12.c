#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero = 0;
    int divisione = 1;

    printf("Scegli un numero: \n");
    scanf("%d", &numero);

    printf("Divisioni: ");

    while (divisione <= numero){
        if (numero % divisione == 0){
            printf("%d, ", divisione);
        }
        divisione ++;
    }
    
    return 0;
}