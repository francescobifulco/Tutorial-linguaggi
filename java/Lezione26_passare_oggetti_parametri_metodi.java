public class Lezione26_passare_oggetti_parametri_metodi {
    public static void main(String[] args) {
        // Creiamo i due "attori" della scena
        Informazione persona1 = new Informazione("Luca", "Rossi", 25, "blu");
        Informazione persona2 = new Informazione("Marco", "Verdi", 32, "rosso");
        
        System.out.println("--- INIZIO INTERAZIONE ---\n");

        // persona1 (Luca) chiama il metodo 'saluta' e riceve come parametro persona2 (Marco)
        persona1.saluta(persona2);
        
        System.out.println("\n--- RISPOSTA INVERSA ---");
        
        // Possiamo fare anche il contrario!
        persona2.saluta(persona1);

        System.out.println("\n--- FINE INTERAZIONE ---");
    }
}