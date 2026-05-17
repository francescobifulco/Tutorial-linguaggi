#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdio.h> // Contiene le macro come UINT_MAX e INT_MAX


//Lezione 3: tipi di signed e unsigned
//Lezione extra: la scelta dei nomi delle variabili
int main() {

    // 1. Intero con segno (signed int)
    // Può contenere sia numeri positivi che negativi.
    int a = 100000;
    printf("Intero con segno (a): %d\n", a);
    
    // 2. Intero senza segno (unsigned int)
    // Può contenere solo numeri positivi, ma raddoppia la capacità verso l'alto.
    unsigned int b = 3000000000;
    printf("Intero senza segno (b): %u\n", b);

    // 3. Il valore massimo memorizzabile in un unsigned int
    // Preso direttamente dalla libreria <limits.h>
    unsigned int c = UINT_MAX;
    printf("Valore massimo di unsigned int (c): %u\n", c);

    // --- REGREGOLE PER I NOMI DELLE VARIABILI ---
    //NON devono essere ambigui e DEVONO essere auto-espicativi

    // Stile CamelCase (molto usato in C/C++ e Java)
    int stileCamelCase = 0;
    printf("La varabile con lo stile camelcase (stileCamelCase): %d\n", stileCamelCase);
    
    // Stile snake_case (molto usato in C e Python)
    int stile_snake_case = 0;
    printf("La varabile con lo stile snake case (stile_snake_case): %d\n", stile_snake_case);

    // Esempio extra: usare INT_MAX per vedere il limite dei numeri con segno
    printf("Valore massimo di signed int: %d\n", INT_MAX);

    return 0;
}