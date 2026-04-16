public class Lezione20_programmazione_oggetti {
    public static void main(String[] args) {
        
        // Creiamo due istanze (oggetti) della classe Persona
        Persona persona1 = new Persona();
        Persona persona2 = new Persona();

        // Modifichiamo i dati di persona2 per distinguerla,
        // altrimenti sarebbero due cloni identici chiamati Luca Rossi.
        persona2.nome = "Marco";
        persona2.cognome = "Verdi";

        // --- STAMPE LOGICHE ---
        System.out.println("--- INFO PERSONA 1 ---");
        System.out.println("Nome: " + persona1.nome);
        System.out.println("Colore Preferito: " + persona1.colorePreferito);
        persona1.saluta(); // Chiama il metodo per persona1
        persona1.cammina();

        System.out.println("\n--- INFO PERSONA 2 ---");
        System.out.println("Nome: " + persona2.nome);
        persona2.saluta(); // Chiama il metodo per persona2
    }
}