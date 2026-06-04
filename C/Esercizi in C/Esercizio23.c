#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int array[100];

    for (int i = 0, counter = 100; i < 100; i++, counter--){
        array[i] = counter;
        printf("Il contenuto del array: %d\n", array[i]);
    }
    
    return 0;
}