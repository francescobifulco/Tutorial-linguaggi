import java.util.TreeSet;

public class Lezione47_treeset {
    public static void main(String[] args) {
        // Creazione: Nota che gli elementi saranno ordinati alfabeticamente
        TreeSet<String> nomi = new TreeSet<>();

        System.out.println("--- AGGIUNTA ELEMENTI ---");
        nomi.add("Zaira");
        nomi.add("Marco");
        nomi.add("Anna");
        nomi.add("Luca");

        // La stampa mostrerà: Anna, Luca, Marco, Zaira (ordine alfabetico)
        System.out.println("Set ordinato: " + nomi);

        System.out.println("\n--- METODI DI NAVIGAZIONE ---");
        
        // Primi e ultimi
        System.out.println("Il primo (minimo): " + nomi.first()); 
        System.out.println("L'ultimo (massimo): " + nomi.last());

        // Ricerca relativa
        System.out.println("Il primo dopo 'Luca': " + nomi.higher("Luca")); // Marco
        System.out.println("Il primo prima di 'Luca': " + nomi.lower("Luca")); // Anna

        // Estrazione (Rimuove e restituisce)
        System.out.println("\nRimuovo il primo elemento: " + nomi.pollFirst());
        System.out.println("Set aggiornato: " + nomi);
    }
}