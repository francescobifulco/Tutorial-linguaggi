public class Lezione2_variabili {
    public static void main(String[] args) {
        
    // --- NUMERI INTERI (int) ---
        
        int x;// DICHIARAZIONE: Stai dicendo al computer "Preparami una scatola per numeri interi chiamata x".
        x = 45;// ASSEGNAZIONE: Metti il valore 45 dentro la scatola x.
        
        int y = 34; // INIZIALIZZAZIONE: Fai tutto in un colpo solo (crei la scatola e ci metti dentro il valore).

        // --- ALTRI TIPI DI DATI ---
        
        // String: si usa per i testi. Nota le doppie virgolette "" obbligatorie.
        String e = "ciao";
        
        // double: si usa per i numeri con la virgola (numeri decimali). 
        // Nota: si usa il punto (.) e non la virgola (,) come separatore.
        double w = 7.54;
        
        // --- OUTPUT E MODIFICA ---

        // Stampa il valore attuale di x (che è 45)
        System.out.println(x);

        // SOVRASCRITTURA: Il vecchio valore (45) viene buttato via e sostituito da 100.
        x = 100;
        
        // Ora stamperà 100
        System.out.println(x);
        
        // Stampe degli altri valori
        System.out.println(y); // Stampa 34
        System.out.println(e); // Stampa ciao
        System.out.println(w); // Stampa 7.54

        // DICHIARAZIONE e INIZIALIZZAZIONE: 
// Crei una variabile di tipo intero (int) chiamata ETA_ANIMALE e le assegni il valore 0.
int ETA_ANIMALE = 0;

// STAMPA: 
// Comunichi al sistema di scrivere il contenuto della variabile ETA_ANIMALE nella console.
System.out.println(ETA_ANIMALE);
    } 
} 