#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void robinHood(double* x, double* y){
    double diff;

    if(*y >= *x){
        diff = *y - *x;
        *y -= diff / 2;
        *x += diff / 2;
    }else{
        diff = *x - *y;
        *y += diff / 2;
        *x -= diff / 2;
    }
    printf("Valori bilanciati dentro la funzione: X = %.2f, Y = %.2f\n", *x, *y);
}

int main(){
    double x = 20.0;
    double y = 35.0;

    printf("Valori di partenza nel main: X = %.2f, Y = %.2f\n", x, y);
    
    robinHood(&x, &y);

    printf("Valori finali nel main: X = %.2f, Y = %.2f\n", x, y);
    return 0;
}