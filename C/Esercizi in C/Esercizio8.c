#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int grado_voto;

    printf("Inserisci il tuo punteggio scolastico: \n");
    scanf("%d", &grado_voto);

    if (grado_voto >= 90 && grado_voto <= 100){
        printf("Il tuo punteggio %d e sei di grando A.\n", grado_voto);
    }else if (grado_voto >= 80 && grado_voto <= 89){
        printf("Il tuo punteggio %d e sei di grando B.\n", grado_voto);
    }else if (grado_voto >= 70 && grado_voto <= 79){
        printf("Il tuo punteggio %d e sei di grando C.\n", grado_voto);
    }else if (grado_voto >= 60 && grado_voto <= 69){
        printf("Il tuo punteggio %d e sei di grando D.\n", grado_voto);
    }else if (grado_voto < 60){
        printf("Il tuo punteggio %d e sei di grando F.\n", grado_voto);
    }
    
    return 0;
}