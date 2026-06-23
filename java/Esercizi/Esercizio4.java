/*Usa uno switch per ricevere un numero da 1 a 7 e stampare 
il nome del giorno corrispondente */

import java.util.Scanner;

public class Esercizio4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int scelta;
        System.out.println("inserisci un numero tra 1 a 7: ");
        scelta = scan.nextInt();

        switch (scelta) {
            case 1 -> System.out.println("Lunedì");
            case 2 -> System.out.println("Martedì");
            case 3 -> System.out.println("Mercoledì");
            case 4 -> System.out.println("Giovedì");
            case 5 -> System.out.println("Venerdì");
            case 6 -> System.out.println("Sabato");
            case 7 -> System.out.println("Domenica");
            default -> System.out.println("Errore: inserisci un numero da 1 a 7");
        }

        scan.close();
    }
}
