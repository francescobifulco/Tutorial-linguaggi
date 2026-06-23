#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int a = 5;
    int b = 10;
    int temp;

    printf("il cavolre della variabile di a: %d\n", a);
    printf("il cavolre della variabile di b: %d\n", b);

    temp = a;
    a = b;
    b = temp;

    printf("il cavolre della variabile di a dopo lo scambio: %d\n", a);
    printf("il cavolre della variabile di b dopo lo scambio: %d\n", b); 

    return 0;
}