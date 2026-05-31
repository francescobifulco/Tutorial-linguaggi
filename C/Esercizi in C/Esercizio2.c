#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main (){
    float alterzza, base, area;

    printf("Inserisci il valore del alterzza: \n");
    scanf("%f", &alterzza);

    printf("Inserisci il valore della base: \n");
    scanf("%f", &base);

    area = base * alterzza;
    printf("L area del rettangolo e: %f:.3", area);

    return 0;
}