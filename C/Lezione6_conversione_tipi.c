#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h> // FONDAMENTALE: serve per poter usare la funzione atoi()

// Lezione 6: Conversione dei tipi (Casting) e Operatori di scorciatoia
int main() {

    // 1. Conversione Implicita: il C somma e poi "tronca" la parte decimale 
    // perché la variabile destinazione è un 'int'. (10 + 10 + 76.5 = 96.5 -> diventa 96)
    int numero = 10 + 10 + 76.5;
    printf("Numero (troncato): %d\n", numero + 10); // Stamperà 96 + 10 = 106

    char* parola = "ciao";
    char c = 'c';

    // 2. Conversione da stringa a intero tramite funzione (atoi = ASCII to Integer)
    int conversione = atoi(parola); 
    printf("Parola originaria: %s\n", parola);
    printf("Parola convertita in int con atoi: %d\n", conversione);

    // 3. Conversione Esplicita (Casting) di un carattere
    // Mostra il codice numerico ASCII corrispondente al carattere 'c' (che è 99)
    int conversione1 = (int) c;
    printf("Carattere 'c' convertito in ASCII: %d\n", conversione1);

    // Se volevi il valore numerico, si usa atoi() come fatto sopra. Per evitare errori, commentiamo la vecchia riga:
    // int conversione2 = (int) parola; 
    printf("Indirizzo di memoria della stringa: %p\n", (void*)parola);


    printf("\n--- Operatori di Incremento, Decremento e Assegnamento Rapido ---\n");

    int nume = 20;
    
    // Incremento classico
    nume++; // n = n + 1 (21)
    printf("Dopo nume++: %d\n", nume);

    // Decremento classico
    nume--; // n = n - 1 (20)
    printf("Dopo nume--: %d\n", nume); 

    // Due modi diversi per sottrarre 1
    nume--;  // n diventa 19
    nume -= 1; // n = n - 1 (diventa 18)
    printf("Dopo due decrementi: %d\n", nume);

    // Due modi diversi per sommare 1
    nume++;  // n diventa 19
    nume += 1; // n = n + 1 (diventa 20)
    printf("Dopo due incrementi: %d\n", nume);

    // Moltiplicazione combinata
    nume++;  // n diventa 21
    nume *= 2; // n = n * 2 (diventa 42)
    printf("Dopo *= 2: %d\n", nume);

    // Divisione combinata
    nume--;  // n diventa 41
    nume /= 2; // n = n / 2 (41 / 2 in logica intera fa 20, perde il resto)
    printf("Dopo /= 2: %d\n", nume);

    return 0;
}