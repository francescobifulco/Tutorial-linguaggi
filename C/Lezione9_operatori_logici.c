#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

// Lezione 9: Operatori logici (&&, ||, !)
int main() {
    int a = 11;
    int b = 15;
    int c = 20;

    printf("--- Test Operatori Logici ---\n\n");

    // 1. OPERATORE AND (&&) - Entrambe devono essere VERE
    // (11 < 15) è VERO  E  (20 > 15) è VERO -> Il blocco si esegue
    if (a < b && c > b){
        printf("[1] AND - Entrambe le condizioni sono vere!\n");
    }
    
    // (11 > 15) è FALSO E  (20 > 15) è VERO -> Una è falsa, quindi NON si esegue
    if (a > b && c > b) {
        printf("[2] AND - Questo non lo vedrai mai a schermo.\n");
    }
    
    // 2. OPERATORE OR (||) - Almeno una deve essere VERA
    // (11 < 15) è VERO  OPPURE (20 > 15) è VERO -> Entrambe vere, si esegue
    if (a < b || c > b) {
        printf("[3] OR  - Almeno una condizione (in questo caso entrambe) e' vera!\n");
    }

    // (11 > 15) è FALSO OPPURE (20 < 15) è FALSO -> Entrambe false, NON si esegue
    if (a > b || c < b) {
        printf("[4] OR  - Questo non lo vedrai mai a schermo.\n");
    }
    
    // 3. OPERATORE NOT (!) - Ribalta il risultato (il VERO diventa FALSO e viceversa)
    // (11 < 15) sarebbe VERO, ma il '!' davanti lo trasforma in FALSO.
    // Quindi la riga diventa: [FALSO || (20 > 15 che e' VERO)]. 
    // Poiche' e' un OR ed esiste una parte vera, il blocco SI esegue!
    if (!(a < b) || c > b) {
        printf("[5] NOT - Il NOT ha ribaltato la prima parte, ma l'OR si salva grazie a c > b!\n");
    }

    return 0;