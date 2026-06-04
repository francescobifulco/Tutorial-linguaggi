#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int alunni;
    float voti; 
    float media;
    float somma;

    printf("Inserisci quanti alunni ci sono in una classe: \n");
    scanf("%d", &alunni);

    for (int i = 1; i <= alunni; i++){
        somma = 0; 
        printf("\n--- Inserimento voti per l'Alunno %d ---\n", i);
        for (int j = 0; j < 5; j++){
            printf("Inserisci il voto %d: ", j + 1);
            scanf("%f", &voti);

            somma = somma + voti;
        }

        media = somma / 5;
        printf("Alunno %d, la media dei suoi 5 voti e': %.2f \n", i, media);

        somma = 0;
    }
    
    return 0;
}