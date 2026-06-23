#include <stdio.h>

//Lezione 7: Priorità degli operatori aritmetici e precisione dei decimali
int main(){

    // --- PARTE 1: LE PRECEDENZE MATEMATICHE ---
    // Il C segue le regole dell'algebra: prima Moltiplicazioni e Divisioni (da sinistra a destra), 
    // poi Addizioni e Sottrazioni.
    // Calcolo: (10 * 10 / 10) - (10 * 10)  -->  10 - 100 = -90
    int numero = 10 * 10 / 10 - 10 * 10;
    printf("Risultato 1 (Precedenza standard): %d\n", numero);

    // Le parentesi tonde forzano il C a cambiare l'ordine dei calcoli.
    // Calcolo: ((20) / 10) - 100  -->  2 - 100 = -98
    int numero2 = ((10 + 10) / 10) - 10 * 10;
    printf("Risultato 2 (Con parentesi): %d\n", numero2);

    // --- PARTE 2: PRECISIONE FLOAT VS DOUBLE ---
    // Facciamo la divisione 3713 / 7 = 530.4285714285714... (è un numero periodico)

    // float: ha una precisione singola (circa 7 cifre decimali affidabili).
    // Noterai che dopo le prime cifre, il computer inizia a "inventare" numeri a caso!
    float divisione = (float) 3713 / 7;
    printf("Float a 30 decimali:  %.30f\n", divisione);

    // double: ha una precisione doppia (circa 15-17 cifre decimali affidabili).
    // È molto più preciso del float, ma anche lui alla fine deve arrendersi e approssimare.
    double divisione2 = (double) 3713 / 7;
    printf("Double a 30 decimali: %.30lf\n", divisione2);

    // --- PARTE 3: DIVISIONE TRA VARIABILI ---

    double num1 = 3713;
    double num2 = 7;

    // Poiché num1 e num2 sono già dichiarati come double, non serve fare il cast esplicito.
    double divisione3 = num1 / num2;
    printf("Divisione standard:   %.30lf\n", divisione3);
    return 0;

}