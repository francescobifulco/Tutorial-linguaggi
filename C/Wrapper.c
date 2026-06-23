#define _CRT_SECURE_NO_WARNINGS
#include "Wrapper.h"

// Struttura Prestiti (Utilizziamo una lista concatenata semplice per la riscrittura)
typedef struct prestiti{
    char codiceFiscale[17];
    char dataPrestito[11];
    char autoreLibro[200];
    char nomeLibro[200];

    struct prestiti* next;
} prestiti;

typedef struct{
    char dataScadenza[11];
    char codiceFiscale[17];
    char nomeLibro[200];
    char autoreLibro[200];
} restituzioni;

void creareFileNoEsiste(){
    // Assegniamo a un puntatore temporaneo e chiudiamo subito il file
    FILE* temp;
    
    if (_access("restituzioni.txt", F_OK) != 0) {
        temp = fopen("restituzioni.txt", "w");
        if (temp != NULL) fclose(temp);
    }

    if (_access("prestiti.txt", F_OK) != 0) {
        temp = fopen("prestiti.txt", "w");
        if (temp != NULL) fclose(temp);
    }
}

void inserisciPrestito(){
    // Scriviamo dati puliti separati da spazi per facilitare la fscanf successiva
    FILE* file = fopen("prestiti.txt", "a"); 
    if (file == NULL) {
        printf("Errore nell'apertura del file prestiti!\n");
        return;
    }

    prestiti* prestito = (prestiti*)malloc(sizeof(prestiti));
    if (prestito == NULL) {
        fclose(file);
        return;
    }

    printf("\n--- INSERIMENTO NUOVO PRESTITO ---\n");
    
    printf("Inserisci il codice fiscale (16 caratteri): ");
    scanf("%s", prestito->codiceFiscale);
    
    printf("Inserisci il nome del libro (usa l'underscore _ al posto degli spazi): ");
    scanf(" %[^\n]s", prestito->nomeLibro); // " %[^\n]s" serve a leggere anche gli spazi tra le parole!
    
    printf("Inserisci il nome del autore (usa l'underscore _ al posto degli spazi): ");
    scanf(" %[^\n]s", prestito->autoreLibro);

    printf("Inserisci la data del prestito (gg/mm/aaaa): ");
    scanf("%s", prestito->dataPrestito);

    // Scrittura formattata: separiamo i campi con un carattere speciale (es. '|') o teniamo gli spazi
    fprintf(file, "CF: %s | Data: %s | Autore: %s | Libro: %s\n", 
            prestito->codiceFiscale, prestito->dataPrestito, prestito->autoreLibro, prestito->nomeLibro);

    printf("[OK] Prestito salvato nel file con successo!\n\n");

    // Pulizia e chiusura
    free(prestito);
    fclose(file);
}

void inserisciRestituzione(){

    FILE* file = fopen("restituzioni.txt", "a"); 
    if (file == NULL) {
        printf("Errore nell'apertura del file restituzioni!\n");
        return;
    }

    restituzioni* restrituzione = (restituzioni*)malloc(sizeof(restituzioni));
    if (restrituzione == NULL) {
        fclose(file);
        return;
    }

    printf("\n--- INSERIMENTO NUOVO RESTUTUZIONE ---\n");
    
    printf("Inserisci il codice fiscale (16 caratteri): ");
    scanf("%s", restrituzione->codiceFiscale);
    
    printf("Inserisci il nome del libro: ");
    scanf(" %[^\n]s", restrituzione->nomeLibro); // " %[^\n]s" serve a leggere anche gli spazi tra le parole!
    
    printf("Inserisci il nome del autore: ");
    scanf(" %%[^\n]s", restrituzione->autoreLibro);

    printf("Inserisci la data del prestito (gg/mm/aaaa): ");
    scanf("%s", restrituzione->dataScadenza);

    fprintf(file, "CF: %s | Data: %s | Autore: %s | Libro: %s\n", 
            restrituzione->codiceFiscale, restrituzione->dataScadenza, 
            restrituzione->autoreLibro, restrituzione->nomeLibro);

    printf("[OK] restituito salvato nel file con successo!\n\n");

    // Pulizia e chiusura
    fclose(file);
    
    // =================================================================
    // ALGORITMO DI ELIMINAZIONE DEL PRESTITO CORRISPONDENTE
    // =================================================================

    FILE* filePrestito = fopen("prestiti.txt", "r");
    if (filePrestito == NULL) {
        free(restrituzione);
        return;
    }

    prestiti* head = NULL;
    prestiti* current = NULL;
    prestiti tempRead;

    // Leggiamo i vecchi prestiti e li carichiamo in una lista concatenata pulita
    // CORREZIONE 2: Ora il formato combacia perfettamente con la scrittura di inserisciPrestito
    while (fscanf(filePrestito, "%s %s %s %s %s", tempRead.codiceFiscale, tempRead.dataPrestito, 
                  tempRead.autoreLibro, tempRead.nomeLibro) == 4){
                    prestiti* nuovoNodo = (prestiti*)malloc(sizeof(prestiti));
                    strcpy(nuovoNodo->codiceFiscale, tempRead.codiceFiscale);
                    strcpy(nuovoNodo->dataPrestito, tempRead.dataPrestito);
                    strcpy(nuovoNodo->autoreLibro, tempRead.autoreLibro);
                    strcpy(nuovoNodo->nomeLibro, tempRead.nomeLibro);
                    nuovoNodo->next = NULL;
                    if (head == NULL) {
                        head = nuovoNodo;
                        current = head;
                    } else {
                        current->next = nuovoNodo;
                        current = current->next;
                    }
    }

    //Chiudiamo il file dei prestiti PRIMA di provare a rimuoverlo o modificarlo!
    fclose(filePrestito);
    
    // Scriviamo il nuovo file temporaneo saltando il libro restituito
    FILE* stream2 = fopen("prestititmp.txt", "w");
    if (stream2 != NULL) {
        current = head;
        //Ciclo di scorrimento corretto per liste concatenate
        while (head->next != NULL){
            // Controlliamo se questo prestito corrisponde a quello restituito
            if (strcmp(head->codiceFiscale, restrituzione->codiceFiscale) == 0 &&
                strcmp(head->nomeLibro, restrituzione->nomeLibro) != 0){
                    // Trovato! Lo saltiamo (non lo scriviamo nel file aggiornato)
                    fprintf(stream2, "%s %s %s %s\n", 
                        current->codiceFiscale, current->dataPrestito, 
                        current->autoreLibro, current->nomeLibro);
            }
            current = current->next;
        }
        fclose(stream2);
    }

    // Liberiamo la memoria della lista usata per il controllo
    prestiti* svuota;
    while (head != NULL) {
        svuota = head->next;
        free(head);
        head = svuota;
    }

    // Sostituzione finale dei file fisici sul disco
    remove("prestiti.txt");
    rename("prestititmp.txt", "prestiti.txt");
    
    free(restrituzione);
}

void stampaFile(char* filePath){
    FILE* file = fopen(filePath, "r");

    if (file == NULL) {
        printf("\n[INFO] Registro dei prestiti vuoto o inesistente.\n\n");
        return;
    }

    char currentLine[250];
    printf("\n================ REGISTRO (%s) ================\n");
    while (fgets(currentLine, sizeof(currentLine), file) != NULL) {
        printf("%s", currentLine);
    }
    printf("===================================================\n\n");

    fclose(file);   
}

void printMenu(){
    int scelta = 0;
    char pausa[50];
    
    do{
        printf("================ MENU LIBRERIA ================\n");
        printf("[1] Inserisci prestito\n");
        printf("[2] Inserisci restituzione\n");
        printf("[3] Stampa tutti i prestiti\n");
        printf("[4] Stampa tutte le restituzioni\n");
        printf("[5] Esci dal programma\n");
        printf("===============================================\n");
        printf("Scegli un'opzione: ");

        if (scanf("%d", &scelta) != 1) {
            printf("\n[ERRORE] Inserisci un numero valido!\n");
            // Pulizia del buffer in caso di inserimento di caratteri errati (lettere)
            while (getchar() != '\n'); 
            scelta = -1; // Forza il riavvio del ciclo
        }

        if (scelta == 1){
            inserisciPrestito();
        }
        else if (scelta == 2){
            inserisciRestituzione();

            printf("\nHai inserito correttamente i dati...\n");
        }
        else if (scelta == 3){
            stampaFile("prestiti.txt");
        }
        else if (scelta == 4){
            stampaFile("restituzione.txt");
        }
        else if (scelta == 5){
            printf("\nUscita dal programma in corso. Arrivederci!\n");
            break; // Rompe il ciclo infinito ed esce dal main
        }else if (scelta != -1) {
            printf("\nOpzione non valida! Riprova.\n");
        }
        
        if (scelta != 0) {
            printf("\nPremi un carattere qualsiasi e INVIO per tornare al menu: ");
            // CORREZIONE 5: Rimossa la '&' davanti all'array di caratteri
            scanf("%s", pausa); 
            
            // Pulisce la console (Funziona su Windows)
            system("cls"); 
        }
    }while (1);
}