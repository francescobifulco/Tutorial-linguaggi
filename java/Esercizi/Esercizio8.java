/*Usa un ArrayList<String>. Crea un programma che permetta di
aggiungere prodotti, rimuoverli e visualizzare la lista completa.*/

import java.util.ArrayList;
import java.util.Scanner;

public class Esercizio8 {
    public static void main(String[] args) {
        ArrayList<String> prodotti = new ArrayList<>();
        Scanner scan = new Scanner(System.in);

        System.out.println("Inserisci il numero di quandi prodotti vuoi inserire: ");
        int numero = scan.nextInt();

        scan.nextLine();

        for (int i = 0; i < numero; i++) {
            System.out.print("Inserisci il nome del prodotto " + (i + 1) + ": ");
            String nome_pro = scan.nextLine();
            prodotti.add(nome_pro);
        }

        System.out.println("\nLista attuale: " + prodotti);

        System.out.print("\nQuale prodotto vuoi eliminare? ");
        String nome_ele = scan.nextLine();

        // Il metodo remove restituisce true se l'elemento esisteva ed è stato rimosso
        if (prodotti.remove(nome_ele)) {
            System.out.println("Prodotto rimosso con successo.");
        } else {
            System.out.println("Errore: Prodotto non trovato in lista.");
        }

        System.out.println("Lista finale: " + prodotti);

        scan.close();
    }
}