public class Lezione27_parola_final_static {
    public static void main(String[] args) {
        
        // --- PAROLA CHIAVE FINAL ---
        // Una variabile 'final' è una costante: una volta assegnata, non può cambiare.
        final int PROVA = 5; 
        // PROVA = 10; // Questo causerebbe un errore di compilazione!
        System.out.println("Costante finale: " + PROVA);

        // --- UTILIZZO DEGLI OGGETTI ---
        Informazione persona1 = new Informazione("Luca", "Rossi", 25, "blu");
        System.out.println(persona1);

        Informazione persona2 = new Informazione("Marco", "Verdi", 32, "giallo");
        System.out.println(persona2);
        
        // --- ACCESSO A MEMBRI STATICI ---
        // Non serve persona1.numeroPersona (anche se funzionerebbe).
        // Si usa il nome della Classe: Informazione.numeroPersona
        System.out.println("\nNumero persone registrate: " + Informazione.numeroPersona);

        // Chiamata al metodo statico
        Informazione.mostraNumPersone();
    }
}