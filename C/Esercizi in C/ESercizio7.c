#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int eta;

    printf("Inserisci la tua eta: \n");
    scanf("%d", &eta);

    if (eta < 12){
        printf("Sei un bambino perche la tua eta e %d percio e inferiore a 12", eta);
    }else if (eta >= 12 && eta <= 17){
        printf("Sei un adolescente perche la tua eta e %d percio e compreso tra 12 e 17", eta);
    }else if (eta >= 18){
        printf("Sei un adulto perche la tua eta e %d percio e maggiore o uguale a 18", eta);
    }
    
    return 0;
}