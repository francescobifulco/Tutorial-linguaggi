#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float num1, num2;

    printf("Inserisci un nuemro: \n");
    scanf("%f", &num1);

    printf("Inserisci un nuemro: \n");
    scanf("%f", &num2);

    float risultato = 0;
    bool x = true;

    while (x){
        int scelta;
        printf("Inserisci un operazione [1] somma, [2] sottrazione, [3] prodotto, [4] quoziente [0] esci. \nscegli: ");
        scanf("%d", &scelta);
        switch (scelta){
        case 0:
            x = false; 
            printf("Uscita dalla calcolatrice.\n");
            break;
        case 1:
            float somma;
            somma = num1 + num2;
            printf("La somma dei due numero il primo %.3f e il secondo %.3f e: %.3f\n", num1, num2, somma);
            break;
        case 2:
            float sottrazione;
            sottrazione = num1 - num2;
            printf("La sottrazione dei due numero il primo %.3f e il secondo %.3f e: %.3f\n", num1, num2, sottrazione);
            break;
        case 3:
            float prodotto;
            prodotto = num1 * num2;
            printf("Il prodotto dei due numero il primo %.3f e il secondo %.3f e: %.3f\n", num1, num2, prodotto);
            break;
        case 4:
            if (num2 != 0) {
                risultato = num1 / num2;
                printf("Il quoziente di %.3f e %.3f e': %.3f\n", num1, num2, risultato);
            } else {
                printf("[ERRORE] Impossibile dividere per zero!\n");
            }
            break;

        default:
            printf("Errore, il valore inserito non e valito");
            break;
        }
    }

    return 0;
}