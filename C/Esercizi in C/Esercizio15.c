#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero;

    printf("Inserisci un numero per fare la moltiplicazione: \n");
    scanf("%d", &numero);

    for (int i = 0; i <= 10; i++){
        int molti = numero * i;
        printf("%d * %d = %d \n", i, numero, molti);
    }
    
    return 0;
}