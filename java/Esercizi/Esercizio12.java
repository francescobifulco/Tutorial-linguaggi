/*Crea un sistema di gestione per una "Biblioteca".
Crea una classe Libro (ID, Titolo, Autore).
Crea una classe GestoreBiblioteca che usa un ArrayList per memorizzare i libri.
Crea un menu che permetta di inserire, cercare e cancellare libri dalla lista
in memoria.*/

import java.util.Scanner;

public class Esercizio12 {
    public static void main(String[] args) {
        GestoreBiblioteca libro1 = new GestoreBiblioteca();
        Scanner scan = new Scanner(System.in);

        while (true) {
            String scelta;
            System.out.println("Inserisci operazione da fare [A]ggiungi - [L]ista - [E]liminare - [V]ia");
            scelta = scan.nextLine();

            if (scelta.equalsIgnoreCase("V")) {
                break;
            } else if (scelta.equalsIgnoreCase("A")) {
                libro1.aggiungiLibro();
            } else if (scelta.equalsIgnoreCase("L")) {
                libro1.listaLibri();
            } else if (scelta.equalsIgnoreCase("E")) {
                libro1.eliminaLibro();
            }
        }
    }
}

