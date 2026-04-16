public class Lezione21_costruttore {
    public static void main(String[] args) {
        // Creiamo gli oggetti passando i dati "al volo"
        Informazione persona1 = new Informazione("Luca", "Rossi", 25, "blu");
        Informazione persona2 = new Informazione("Marco", "Verdi", 29, "rosso");

        // Stampe pulite e descrittive
        System.out.println("\n--- DETTAGLI PERSONA 1 ---");
        System.out.println("Nominativo: " + persona1.nome + " " + persona1.cognome);
        System.out.println("Età: " + persona1.eta);
        System.out.println("Colore: " + persona1.colorePreferito);

        System.out.println("\n--- DETTAGLI PERSONA 2 ---");
        System.out.println("Nominativo: " + persona2.nome + " " + persona2.cognome);
        System.out.println("Età: " + persona2.eta);
        System.out.println("Colore: " + persona2.colorePreferito);
    }
}