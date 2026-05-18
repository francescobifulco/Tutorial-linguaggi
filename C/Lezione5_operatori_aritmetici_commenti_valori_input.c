#define _CRT_SECURE_NO_WARNINGS // Rende sicuro l'uso di scanf su Visual Studio
#include <stdio.h>

//Lezione 5: Operatori aritmetici, commenti e input da tastiera
//Questa riga è un commento su una riga singola
    /* Questo è il 
   commento su più 
   righe */
int main(){
    
    // --- OPERATORI ARITMETICI CON VALORI FISSI ---

    int somma = 10 + 10;
    printf("Somma: %d\n", somma);

    int sottrazione = 10 - 10;
    printf("Sottrazione: %d\n", sottrazione);

    int moltiplicazione = 10 * 10;
    printf("Moltiplicazione: %d\n", moltiplicazione);

    float divisione = 10.0 / 10;
    printf("Divisione: %f\n", divisione);

    // --- INPUT DA TASTIERA (scanf) ---

    int numero1;
    printf("Inserisci il primo numero: ");
    // La & (e commerciale) serve a indicare l'indirizzo di memoria della variabile
    scanf("%d", &numero1);

    int numero2;
    printf("Inserisci il secondo numero: ");
    scanf("%d", &numero2);

    int new_somma = numero1 + numero2;
    printf("La somma dei tuoi numeri e': %d\n", new_somma);

    // --- LOGICA DELLE VARIABILI (Assegnazione per valore) ---

    int num1 = 10;
    int num2 = num1; // num2 copia il VALORE attuale di num1 (cioè 10)

    num1 = 90; // num1 cambia, ma num2 non sa nulla di questo cambiamento!

    // Stamperà: "90 10"
    printf("Valori finali -> num1: %d, num2: %d\n", num1, num2);

    return 0;
}