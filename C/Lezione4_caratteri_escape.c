#include <stdio.h>

//Lezione 4: Carattere di Escape
int main(){

    // --- IL TERMINE DI STRINGA (\0) ---
    // In C, '\0' (carattere nullo) dice al programma: "La stringa finisce qui!".
    // Di conseguenza, la printf stamperà solo "ci" e ignorerà completamente "ao".
    char* ciao = "ci\0ao";
    printf("Stringa interrompibile: %s\n", ciao);
    
    printf("\n--- Test Caratteri di Escape ---\n");

    // Stampa il carattere di backslash (\)
    printf("Backslash: \\\n");

    // Stampa le virgolette doppie (") senza confondere il compilatore
    printf("Virgolette doppie: \"\n");

    // Stampa l'apice singolo (')
    printf("Apice singolo: \'\n");

    // \n inserisce una Nuova Riga (New Line)
    printf("Riga 1\nRiga 2\n");

    // \t inserisce una Tabulazione orizzontale (un grande spazio per incolonnare)
    printf("ColonnaA\tColonnaB\n");

    // \b è il Backspace: cancella il carattere precedente (in questo caso cancella la 'o')
    printf("ciaoo\b\n");

    // \r è il Carriage Return: riporta il cursore all'inizio della riga corrente.
    // "Mondo" sovrascriverà "Ciao"
    printf("Ciao \rMondo\n");

    // \f (Form Feed) e \v (Vertical Tab) sono storici (usati per le stampanti).
    // Nei terminali moderni spesso stampano simboli strani o vanno a capo in modo particolare.
    printf("Test tabulazione verticale:\vIn verticale\n");
    printf("Prima pagina di testo.\n");
    printf("\f");
    printf("Seconda pagina di testo.\n");
    
    // \e[31m imposta il colore del testo a rosso
    // \e[0m resetta il colore
    printf("\e[31mQuesto testo è rosso!\e[0m\n");

    // \e[1;32m imposta il testo in verde brillante
    printf("\e[1;32mQuesto testo è verde brillante!\e[0m\n");

    // Mostra il valore ASCII di \e
    printf("Il valore ASCII di \\e è: %d\n", '\e');

    // --- AVANZATI: RAPPRESENTAZIONI NUMERICHE ---
    
    // \x seguito da cifre esadecimali permette di stampare un carattere tramite il suo codice.
    // 41 in esadecimale corrisponde alla lettera 'A' nella tabella ASCII.
    printf("Esadecimale (\\x41): \x41\n");

    // \ seguito da tre cifre ottali fa la stessa cosa.
    // 101 in ottale corrisponde sempre alla lettera 'A'.
    printf("Ottale (\\101): \101\n");
    
    // \a (Alert) fa emettere un "bip" sonoro o visivo dal sistema operativo!
    printf("Senti il suono della scheda madre!\a\n");

    return 0;
}