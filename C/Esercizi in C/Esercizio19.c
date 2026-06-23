#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void debito(int* x, int* y, int* z){
    if (*y < 0){
        *x += *y;
        *y = 0;
    } 
    if(*z < 0){
        *x += *z;
        *z = 0;
    }
}

int main(){

    int x = 5;
    int y = -1;
    int z = -2;

    debito(&x, &y, &z);

    printf("%d %d %d \n", x, y, z);

    return 0;
}