#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero = 0;

    printf("Scegli una seguenza di numeri: \n");
    scanf("%d", &numero);

    while (numero != 0){
        printf("%d", numero % 10);
        numero /= 10;
    }
    
    return 0;
}