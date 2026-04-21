import java.util.HashSet;

public class Lezione46_hashset {
    public static void main(String[] args) {
        HashSet<String> invitati = new HashSet<>();

        // 1. FASE DI AGGIUNTA
        System.out.println("--- AGGIUNTA INVITATI ---");
        invitati.add("Luca");
        invitati.add("Marta");
        boolean aggiuntoDiNuovo = invitati.add("Luca"); // Duplicato: restituirà false

        System.out.println("Invitati attuali:");
        for (String nome : invitati) {
            System.out.println("- " + nome);
        }
        System.out.println("Luca è stato aggiunto la seconda volta? " + aggiuntoDiNuovo);

        // 2. VERIFICA E RIMOZIONE
        System.out.println("\n--- CONTROLLI E MODIFICHE ---");
        
        // Verifica esistenza (contains)
        if (invitati.contains("Marta")) {
            System.out.println("[Check]: Marta è presente in lista.");
        }

        // Rimozione (remove)
        System.out.println("[Azione]: Rimuovo Luca...");
        invitati.remove("Luca"); 
        
        System.out.println("È rimasto Marco? " + invitati.contains("Marco"));
        System.out.println("Numero totale invitati: " + invitati.size());

        // 3. PULIZIA FINALE
        System.out.println("\n--- RESET DEL SET ---");
        invitati.clear();
        
        System.out.println("Il set è vuoto? " + invitati.isEmpty());
        System.out.println("Dimensione finale: " + invitati.size());
    }
}