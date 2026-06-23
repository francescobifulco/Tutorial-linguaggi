import java.util.ArrayList;
import java.util.Scanner;

public class GestoreBiblioteca {
    private ArrayList<Libro> gestione = new ArrayList<>();
    private Scanner scan = new Scanner(System.in);

    public void aggiungiLibro() {
        while (true) {
            System.out.println("Inserisci l'ID del libro (oppure digita 'esci'):");
            String id = scan.nextLine();
            if (id.equalsIgnoreCase("esci")) {
                break;
            }
            boolean giaEsiste = false;
            for (Libro libro : gestione) {
                if (libro._getID().equalsIgnoreCase(id)) {
                    giaEsiste = true;
                    break;
                }
            }
            if (giaEsiste) {
                System.out.println("ID del libro gia esiste");
            } else {
                System.out.println("Inserisci il titolo del libro:");
                String titolo = scan.nextLine();

                System.out.println("Inserisci l' autore del libro:");
                String autore = scan.nextLine();

                Libro nuovoLibro = new Libro(id, titolo, autore);
                gestione.add(nuovoLibro);
                System.out.println("Libro aggiunto con successo!");
            }
            System.out.println("---\n");
        }
    }

    public void listaLibri() {
        System.out.println("--- Lista di tutti i libri in biblioteca ---");

        if (gestione.isEmpty()) {
            System.out.println("La biblioteca è vuota.");
            return;
        }

        for (Libro libro : gestione) {
            System.out.println("ID: " + libro.getID() + " - Titolo: " + libro.getTitolo() + " - Autore: " + libro.getAutore() + "\n");
        }
    }

    public void eliminaLibro() {
        System.out.println("--- Eliminare un libri nella biblioteca ---");

        if (gestione.isEmpty()) {
            System.out.println("La biblioteca è vuota. Nulla da eliminare.");
            return;
        }

        System.out.println("Inserisci l'ID del libro da eliminare: ");
        String id_eliminare = scan.nextLine();

        Libro libroTrovato = null;

        for (Libro libro : gestione) {
            if (libro.__getID().equalsIgnoreCase(id_eliminare)) {
                libroTrovato = libro;
                break;
            }
        }
        if (libroTrovato != null) {
            gestione.remove(libroTrovato); // Rimuoviamo l'oggetto Libro corretto
            System.out.println("Libro eliminato con successo!\n");
        } else {
            System.out.println("Errore: Nessun libro trovato con l'ID fornito.");
        }
    }
}

