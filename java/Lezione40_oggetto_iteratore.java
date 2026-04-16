import java.util.ArrayList;
import java.util.Iterator;

public class Lezione40_oggetto_iteratore {
    public static void main(String[] args) {
        ArrayList<String> persone = new ArrayList<>();

        persone.add("Luca");
        persone.add("Marco");
        persone.add("Anna");
        persone.add("Paolo");

        // 1. Creazione dell'Iteratore
        Iterator<String> it = persone.iterator();

        System.out.println("--- PRIMI DUE ELEMENTI ---");
        // .next() restituisce l'elemento e sposta il cursore avanti
        System.out.println("1°: " + it.next());
        System.out.println("2°: " + it.next());

        System.out.println("\n--- SCORRIMENTO RIMANENTE ---");
        // it.hasNext() controlla se c'è ancora qualcosa dopo la posizione attuale
        while (it.hasNext()) {
            System.out.println("Prossimo: " + it.next());
        }

        // 2. RIMOZIONE SICURA
        // Dobbiamo ricreare l'iteratore perché quello precedente è arrivato alla fine
        Iterator<String> itRimozione = persone.iterator();

        System.out.println("\n[Sistema]: Ricerca e rimozione di 'Anna'...");
        while (itRimozione.hasNext()) {
            String p = itRimozione.next();
            if (p.equals("Anna")) { // .equals() è la via corretta per le Stringhe
                itRimozione.remove();
                System.out.println("Trovata! Anna è stata rimossa correttamente.");
            }
        }

        System.out.println("\n--- LISTA FINALE ---");
        System.out.println(persone);
    }
}