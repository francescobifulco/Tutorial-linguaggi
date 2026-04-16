public class Lezione34_polimorfismo {
    public static void main(String[] args) {
        
        // Creazione degli oggetti specifici
        Studente studente1 = new Studente("Luca", "Rossi", 24, "Matematica");
        Studente studente2 = new Studente("Orazio", "Esposito", 22, "Storia");
        Insegnante insegnante1 = new Insegnante("Marco", "Verdi", 45, "Storia");
        
        // POLIMORFISMO: Creiamo un array di 'Persona1' che ospita sottoclassi diverse.
        // Anche se sono oggetti diversi, Java li vede tutti come "Persone".
        Informazione[] classe = {studente1, studente2, insegnante1};

        System.out.println("--- INIZIO APPELLO IN CLASSE ---\n");

        // Ciclo for-each: per ogni 'persona' dentro l'array 'classe'
        for(Informazione persona : classe) {
            // Qui avviene la magia: Java capisce da solo se chiamare il saluto 
            // dello studente o dell'insegnante in base all'oggetto REALE.
            persona.saluta();
        }

        System.out.println("\n--- FINE APPELLO ---");
    }
}