#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int nume1, nume2, nume3;

    printf("Inserisci il primo numero: \n");
    scanf("%d", &nume1);

    printf("Inserisci il secondo numero: \n");
    scanf("%d", &nume2);

    printf("Inserisci il terzo numero: \n");
    scanf("%d", &nume3);

    if (nume1 >= nume2 && nume1 >= nume3){
        printf("Il numero maggiore è: %d\n", nume1);
    }else if (nume2 >= nume1 && nume2 >= nume3){
        printf("Il numero maggiore è: %d", nume2);
    }else{
        printf("Il numero maggiore è: %d\n", nume3);
    }
    
    return 0;
}