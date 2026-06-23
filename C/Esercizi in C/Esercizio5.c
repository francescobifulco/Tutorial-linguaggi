#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int x = 10;

    printf("Valore originale di X: %d\n", x);

    x +=1;
    printf("Valore di X incrementato di uno: %d\n", x);

    x -=1;
    printf("Valore di X decrementato di uno: %d\n", x);

    x +=3;
    printf("Valore di X incrementato di tre: %d\n", x);

    x -=5;
    printf("Valore di X decrementato di cinque: %d\n", x);

    return 0;
}