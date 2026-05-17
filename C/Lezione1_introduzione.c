#include <stdio.h> // Libreria standard per l'input/output (serve per usare printf)
#include <stdlib.h> // Libreria standard che include funzioni di utilità (serve per usare system)

//Lezione 1: introduzione al linguaggio c
int main(){

    // printf stampa a schermo la stringa di testo. 
    // '\n' serve per andare a capo alla fine della riga.
    printf("ciao, mondo!\n");

    // system("pause") blocca l'esecuzione del programma e mostra il messaggio
    // "Premere un tasto per continuare...". È tipico di Windows per evitare
    // che la finestra del terminale si chiuda istantaneamente alla fine del programma.
    system("pause");

    // Segnala al sistema operativo che il programma è terminato con successo.
    // In C, 0 significa "tutto è andato a buon fine".
    return 0;
    
}