#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero;

    printf("Inserisci il numero: \n");
    scanf("%d", &numero);

    if (numero % 2 == 0){
        printf("Il numero %d e pari.\n", numero);
    }else{
        printf("Il numero %d e dispari.\n", numero);
    }
    
    return 0;
}