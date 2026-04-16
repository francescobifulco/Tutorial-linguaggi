public class Lezione15_metodi_stringhe {
    public static void main(String[] args) {
        String nome = "Leonardo";

        // .equals(): Confronta il contenuto di due stringhe. 
        // Restituisce true solo se sono identiche (anche nelle maiuscole).
        boolean risultato = nome.equals("Leanardo"); 
        System.out.println("Uguale a 'Leanardo'?: " + risultato); // false

        // .length(): Restituisce il numero totale di caratteri nella stringa.
        int riusltato1 = nome.length();
        System.out.println("Lunghezza: " + riusltato1); // 8

        // .charAt(index): Restituisce il carattere alla posizione specificata.
        // Ricorda: si parte da 0. L'indice 7 è l'ultimo carattere di "Leonardo".
        char risultato2 = nome.charAt(7);
        System.out.println("Carattere all'indice 7: " + risultato2); // 'o'

        // .indexOf(): Cerca un carattere o una parola e restituisce la sua prima posizione.
        // Se non trova nulla, restituisce -1.
        int riusltato3 = nome.indexOf("a");
        System.out.println("Posizione della 'a': " + riusltato3); // 2

        // .isEmpty(): Controlla se la stringa è vuota (cioè se è "").
        boolean risultato4 = nome.isEmpty();
        System.out.println("La stringa è vuota?: " + risultato4); // false

        // .toUpperCase() / .toLowerCase(): Trasformano tutto in MAIUSCOLO o minuscolo.
        String risultato5 = nome.toUpperCase();
        System.out.println("Tutto maiuscolo: " + risultato5); // LEONARDO

        String riusltato6 = nome.toLowerCase();
        System.out.println("Tutto minuscolo: " + riusltato6); // leonardo

        // .trim(): Rimuove gli spazi vuoti accidentali all'inizio e alla fine della stringa.
        // Utilissimo quando si puliscono i dati inseriti dagli utenti.
        String risultato7 = nome.trim();
        System.out.println("Senza spazi esterni: " + risultato7);

        // .replace(vecchio, nuovo): Sostituisce tutte le occorrenze di un carattere con un altro.
        String risultato8 = nome.replace('o','w');
        System.out.println("Sostituzione 'o' con 'w': " + risultato8); // Lewnardw
    }
}