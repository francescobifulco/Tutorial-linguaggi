#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[10];

    for (int i = 0; i < 10; i++){
        array[i] = i;
        printf("Dentro l array: %d\n", array[i]);
    }
    

    return 0;
}