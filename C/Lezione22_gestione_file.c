#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Stringa[100];
    int numeroIntero;
    char nome2[100];
} nomi;

// Lezione 22: La gestione dei file in C
int main() {
    
    // ==========================================
    // PARTE 1: Lettura testo riga per riga (fgets)
    // ==========================================
    printf("--- [PARTE 1] Lettura con fgets ---\n");
    FILE* file = fopen("file.txt", "r");
    
    // Controllo di sicurezza: verifichiamo che il file esista davvero
    if (file == NULL) {
        printf("[ERRORE] Impossibile aprire file.txt in lettura! Assicurati che esista.\n\n");
    } else {
        char buffer[100];
        // Legge riga per riga finché non incontra la fine del file (NULL)
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("Riga letta: %s", buffer); // buffer contiene già il '\n' del file
        }
        
        // CORREZIONE 1: Per riutilizzare lo stesso file con fscanf, 
        // dobbiamo riportare il cursore all'inizio del documento!
        rewind(file); 

        // ==========================================
        // PARTE 2: Lettura formattata di numeri (fscanf)
        // ==========================================
        printf("\n\n--- [PARTE 2] Lettura numeri con fscanf ---\n");
        int arrayProva[8];
        int contatore_numeri = 0;

        // fscanf restituisce il numero di elementi letti con successo (in questo caso cerchiamo 1 intero)
        while (contatore_numeri < 8 && fscanf(file, "%d", &arrayProva[contatore_numeri]) == 1) {
            contatore_numeri++;
        }

        // CORREZIONE 6: Stampiamo solo i numeri EFFETTIVAMENTE letti, non per forza 8
        for (int j = 0; j < contatore_numeri; j++) {
            printf("Posizione array %d: %d\n", j, arrayProva[j]);
        }
        
        fclose(file); // FONDAMENTALE: Chiudiamo sempre il file appena finito!
    }


    // ==========================================
    // PARTE 3: Lettura di record strutturati (fscanf + Struct)
    // ==========================================
    printf("\n--- [PARTE 3] Lettura di Struct da filecontesto.txt ---\n");
    FILE* file1 = fopen("filecontesto.txt", "r");

    if (file1 == NULL) {
        printf("[ERRORE] Impossibile aprire filecontesto.txt! Crealo inserendo righe come: Parola 123 AltraParola\n\n");
    } else {
        nomi arrayNomi[4];
        int contatore_nomi = 0; // CORREZIONE 2: Azzeriamo il contatore prima del ciclo

        // CORREZIONE 4: Rimossa '&' dalle stringhe e aggiunta '&' davanti all'intero
        while (contatore_nomi < 4 && fscanf(file1, "%s %d %s", 
                     arrayNomi[contatore_nomi].Stringa, 
                    &arrayNomi[contatore_nomi].numeroIntero, 
                     arrayNomi[contatore_nomi].nome2) == 3) {
            contatore_nomi++;
        }
        
        // Stampa dei record letti
        for (int j = 0; j < contatore_nomi; j++) {
            // CORREZIONE 5: Cambiato l'ultimo specificatore da %d a %s
            printf("Record [%d] -> Stringa: %s | Intero: %d | Nome2: %s\n", 
                    j, arrayNomi[j].Stringa, arrayNomi[j].numeroIntero, arrayNomi[j].nome2);
        }
        
        fclose(file1);
    }


    // ==========================================
    // PARTE 4: Scrittura sul file (w = sovrascrivi, a = appendi)
    // ==========================================
    printf("\n--- [PARTE 4] Scrittura su file ---\n");
    
    // Modalità "w": cancella tutto il contenuto precedente e scrive da zero
    FILE* file2 = fopen("file_output.txt", "w");
    if (file2 != NULL) {
        char buf[20] = "Scrivi nel file\n";
        // fwrite scrive blocchi binari: (sorgente, dim_elemento, num_elementi, destinazione)
        fwrite(buf, sizeof(char), strlen(buf), file2);
        fclose(file2);
        printf("[OK] Stringa scritta con successo in 'file_output.txt' (modalita' 'w').\n");
    }

    // Modalità "a" (Append): non cancella nulla, si posiziona alla fine e aggiunge testo
    FILE* file3 = fopen("file_output.txt", "a");
    if (file3 != NULL) {
        char buf_append[30] = "Testo aggiunto alla fine!\n";
        fwrite(buf_append, sizeof(char), strlen(buf_append), file3);
        fclose(file3);
        printf("[OK] Ulteriore testo appeso con successo (modalita' 'a').\n");
    }
    // da rivedere
    return 0;
}