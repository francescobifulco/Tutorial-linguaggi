public class Lezione31_incapsulamento_get_set {
    public static void main(String[] args) {
        // Creazione dell'oggetto tramite costruttore
        Persona1 persona = new Persona1("Luca", "Rossi");

        System.out.println("--- DATI INIZIALI ---");
        // Non possiamo usare persona.nome, dobbiamo usare i Getter
        System.out.println("Nome:    " + persona.getNome());
        System.out.println("Cognome: " + persona.getCognome());

        // Modifica dei dati tramite Setter
        System.out.println("\n[Sistema]: Aggiornamento dati in corso...");
        persona.setNome("Orazio");
        persona.setCognome("Verdi");

        System.out.println("\n--- DATI AGGIORNATI ---");
        System.out.println("Nuova identità: " + persona.getNome() + " " + persona.getCognome());
    }
}