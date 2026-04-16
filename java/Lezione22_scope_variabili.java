public class Lezione22_scope_variabili {
    public static void main(String[] args) {
        System.out.println("--- INIZIO PROGRAMMA ---\n");

        Informazione persona1 = new Informazione("Luca", "Rossi", 25, "blu");
        
        System.out.println("\n--- TEST METODI ---");
        persona1.saluta();
        
        // Chiamando addizione, inneschiamo una reazione a catena che chiama anche qwerty
        persona1.addizione(20, 40);

        System.out.println("\n--- FINE PROGRAMMA ---");
    }
}