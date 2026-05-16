#include <stdio.h>

int main(){
    // 1. Intero (int) -> Si stampa con %d
    int primaVariabile = 10;
    printf("%d\n", primaVariabile);
    
    // 2. Numero con virgola a singola precisione (float) -> Si stampa con %f
    float secondaVariabile = 20.0;
    printf("%f\n", secondaVariabile);

    // 3. Numero con virgola a doppia precisione (double) -> Si stampa con %lf
    double terzaVariabile = 30.3422;
    printf("%ln\n", terzaVariabile);

    // 4. Stringa di caratteri (char*) -> Si stampa con %s
    char* quartaVariabile = "ciao sono un umano";
    printf("%s\n", quartaVariabile);

    // 5. Singolo carattere (char) -> Si stampa con %c
    char quintaVariabile = 'C';
    printf("%c\n", quintaVariabile);

    // 6. Costante intera (const int) -> Essendo un intero, si stampa sempre con %d
    const int costante = 1000;
    printf("%d\n", costante);

    return 0;

}