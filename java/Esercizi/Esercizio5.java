/*Chiedi un numero all'utente e stampa la sua tabellina 
da 1 a 10 usando un ciclo for.*/

import java.util.Scanner;

public class Esercizio5 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int scelta;
        System.out.println("Inserisci il numero di cui vuoi la tabellina:");
        scelta = scan.nextInt();

        System.out.println("Tabellina del " + numero + ":");

        for(int i = 0; i <= 10; i++ ){
            int risultato = i * scelta;
            System.out.println(scelta + "*" + i + "=" + risultato);
        }

        scan.close();
    }
}