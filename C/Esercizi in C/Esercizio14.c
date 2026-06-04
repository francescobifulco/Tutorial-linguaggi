#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

    int popolazione = 10;
    int tassoDiContagiato = 1;
    int ammalati = 1;
    int gioarni = 1;
    do{
        popolazione -= ammalati;
        
        if (gioarni == 1){
            ammalati += tassoDiContagiato;
        }else if (tassoDiContagiato == 1 && gioarni > 1){
            ammalati = ammalati * 2; 
        }else{
            ammalati = ammalati * tassoDiContagiato;
        }
        

        gioarni++;
    } while (ammalati < popolazione);
    
    printf("Ci sono %d ammalati e siamo al giorno: %d", ammalati, gioarni);
    return 0;
}