#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 1. Esempio di ricorsione ERRETA (Commentata per evitare il crash)
int ricorsione2(){
    printf("ciao\n");

    ricorsione2(); // Errore: Manca un caso base, porterà allo Stack Overflow!
}

// 2. Esempio di ricorsione CORRETTA: Il Fattoriale (es. 5! = 5 * 4 * 3 * 2 * 1)
int ricorsione(int numero){
    // Stampa di controllo: mostra la fase di "discesa"
    printf("-> Entro in ricorsione( %d )\n", numero);

    // CASO BASE: Il freno a mano che interrompe la catena
    if (numero == 1) {
        printf("[Caso Base Raggiunto!] Numero e' 1, iniziamo a risalire...\n");
        return 1;
    }
    // CASO RICORSIVO: La funzione chiama se stessa passando un problema più piccolo (numero - 1)
    else{
        int risultato_parziale = numero * ricorsione(numero - 1);
        printf("<- Esco da ricorsione( %d ) restituendo: %d\n", numero, risultato_parziale);
        return risultato_parziale;
    }
    
}

// Lezione 17: Le funzione ricorsione
int main() {

    printf("--- [MAIN] Calcolo del Fattoriale Interattivo ---\n\n");
    int n = 5;
    int fattoriale = ricorsione(n);

    printf("\nRisultato Finale -> Il fattoriale di %d (%d!) e': %d\n", n, n, fattoriale);

    return 0;
}