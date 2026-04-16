public class Lezione28_ereditarieta {
    public static void main(String[] args) {
        
        // 1. Oggetto base
        Informazione persona1 = new Informazione("Luca", "Rossi", 25);
        System.out.println("--- PERSONA GENERICA ---");
        System.out.println(persona1);
        persona1.saluta();

        // 2. Lo Studente (Eredita nome, cognome, eta + ha materiaPreferita)
        System.out.println("\n--- REGISTRAZIONE STUDENTE ---");
        Studente studente1 = new Studente("Mario", "Esposito", 14, "Storia");
        System.out.println(studente1);
        studente1.saluta(); // Metodo sovrascritto
        studente1.studia(); // Metodo esclusivo di Studente

        // 3. L'Insegnante (Eredita nome, cognome, eta + ha materia)
        System.out.println("\n--- REGISTRAZIONE INSEGNANTE ---");
        Insegnante insegnante1 = new Insegnante("Luigi", "Verdi", 38, "Matematica");
        System.out.println(insegnante1);
        insegnante1.saluta(); // Metodo sovrascritto
        insegnante1.insegna(); // Metodo esclusivo di Insegnante
    }
}