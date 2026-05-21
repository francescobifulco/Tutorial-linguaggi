#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Lezione 13: Le istruzioni di salto (Break, Continue, Return)
int main() {
    printf("--- 1. TEST CON 'continue' (Salta il giro) ---\n\n");

    // Il 'continue' dice al computer: "Ignora tutto quello che c'è sotto DIENTRO AL CICLO
    // e passa immediatamente al prossimo giro".
    for (int i = 0; i < 10; i++){
        if (i % 2 != 0){
            // Se il numero è dispari, saltiamo direttamente al prossimo i++
            continue;
        }else{
            printf("Numero pari trovato: %d\n", i);
        }
        // Questa riga NON verrà stampata quando il numero è dispari, 
        // perché il 'continue' ha già fatto saltare il giro!
        printf("[Ciclo 1] Fine del giro %d raggiunto!\n");
    }
    printf("\n>> Uscito correttamente dal primo ciclo <<\n\n\n");

    printf("--- 2. TEST CON 'break' (Spezza il ciclo) ---\n\n");

    // Il 'break' dice al computer: "Basta, esci immediatamente e permanentemente da questo ciclo",
    // ignorando tutti i giri che mancavano.
    for (int i = 0; i < 10; i++){
        if (i % 2 != 0){
            // Appena i diventa 1 (dispari), il break distrugge il ciclo!
            break;
        }else{
            printf("Numero pari trovato: %d\n", i);
        }
        printf("[Ciclo 2] Fine del giro %d raggiunto!\n", i);
    }
    printf("\n>> Uscito bruscamente dal secondo ciclo grazie al 'break' <<\n\n\n");
    
    // --- 3. SPIEGAZIONE DEL 'return' ---
    // Il 'return 0;' non ferma solo un ciclo, ma chiude l'INTERA FUNZIONE (in questo caso il main).
    // Se lo mettessimo dentro un ciclo, il programma si chiuderebbe all'istante.
    printf("--- 3. TEST CON 'return' ---\n");
    printf("Adesso eseguiamo il return 0; finale che chiude tutto il programma.\n");
    
    return 0;
}