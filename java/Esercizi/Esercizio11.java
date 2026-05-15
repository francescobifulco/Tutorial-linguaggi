/*Crea un programma che divida due numeri inseriti dall'utente. 
Gestisci l'eccezione ArithmeticException se l'utente inserisce 0 come divisore.*/

import java.util.Scanner;

public class Esercizio11 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        try {
            System.err.println("Inserisci un numero per dividere: ");
            int numero1 = scan.nextFloat();

            System.out.println("Inserisci un numero per fare una divisione: ");
            int numero2 = scan.nextFloat();

            int risultato = numero1 / numero2;
            System.out.println("Il risultato della divisione tra (" + numero1 + " e " + numero2 + "): " + risultato);
        } catch (ArithmeticException e) {
            System.out.println("ERRORE: Non si può dividere un intero per zero!");
        } catch (Exception e) {
            // Gestisce anche se l'utente inserisce lettere invece di numeri
            System.out.println("ERRORE: Inserimento non valido.");
        } finally {
            scan.close();
            System.out.println("Scanner chiuso correttamente.");
        }
    }
}
