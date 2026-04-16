public class Lezione32_copiare_oggetto {
    public static void main(String[] args) {
        Persona1 persona1 = new Persona1("Luca", "Rossi");
        Persona1 persona2 = new Persona1("Marco", "Verdi");

        System.out.println("--- SITUAZIONE INIZIALE (Due oggetti distinti) ---");
        System.out.println("P1: " + persona1.getNome() + " | Indirizzo: " + persona1);
        System.out.println("P2: " + persona2.getNome() + " | Indirizzo: " + persona2);

        // --- ERRORE COMUNE: Copia del riferimento ---
        persona2 = persona1; 
        System.out.println("\n--- DOPO persona2 = persona1 (Stesso indirizzo!) ---");
        System.out.println("P1: " + persona1.getNome() + " | Indirizzo: " + persona1);
        System.out.println("P2: " + persona2.getNome() + " | Indirizzo: " + persona2);

        persona1.setNome("Orazio");
        System.out.println("\n[Modifico P1 in Orazio] -> Anche P2 cambia perché sono lo STESSO oggetto:");
        System.out.println("P2 si chiama: " + persona2.getNome());

        // --- SOLUZIONE: Il metodo copy ---
        // Prima ricreiamo un oggetto distinto per persona2
        persona2 = new Persona1("Filippo", "Neri"); 
        persona2.copy(persona1); // Ora copiamo solo i DATI di Orazio dentro Filippo

        System.out.println("\n--- DOPO IL METODO COPY (Dati uguali, oggetti diversi) ---");
        System.out.println("P1: " + persona1.getNome() + " | Indirizzo: " + persona1);
        System.out.println("P2: " + persona2.getNome() + " | Indirizzo: " + persona2);

        persona1.setNome("Luigi");
        System.out.println("\n[Modifico P1 in Luigi] -> P2 resta Orazio perché ora è un CLONE INDIPENDENTE:");
        System.out.println("P1: " + persona1.getNome());
        System.out.println("P2: " + persona2.getNome());
    }
}