#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int base, altezza;
    
    printf("Inserisci la base: \n");
    scanf("%d", &base);

    printf("Inserisci l altezza: \n");
    scanf("%d", &altezza);

    for (int i = 0; i <= altezza; i++){
        for (int j = 0; j < base; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}