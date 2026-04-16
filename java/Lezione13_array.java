public class Lezione13_array {
    public static void main(String[] args) {
        
        // --- 1. CREAZIONE DI UN ARRAY VUOTO ---
        // Stai dicendo: "Crea un array di interi chiamato 'numeri' con 3 posti".
        // Inizialmente i cassetti contengono il valore di default (0).
        int[] numeri = new int[3];

        // --- 2. ASSEGNAZIONE PER INDICE ---
        // ATTENZIONE: In informatica si inizia sempre a contare da ZERO.
        numeri[0] = 10; // Primo cassetto
        numeri[1] = 20; // Secondo cassetto
        numeri[2] = 30; // Terzo cassetto

        // --- 3. PROPRIETÀ E ACCESSO ---
        // .length restituisce il numero totale di elementi (qui 3).
        System.out.println("Lunghezza array: " + numeri.length);
        System.out.println("Elemento alla posizione 1: " + numeri[1]); // Stampa 20

        // --- 4. MODIFICA ---
        // Puoi cambiare il contenuto di un cassetto in qualsiasi momento.
        numeri[1] = 100;
        System.out.println("Nuovo valore posizione 1: " + numeri[1]); // Stampa 100

        // --- 5. INIZIALIZZAZIONE RAPIDA ---
        // Se sai già cosa metterci, puoi crearlo così senza usare 'new int[n]'.
        int[] voti = {10, 20, 30, 40}; 
        System.out.println("Terzo voto: " + voti[2]); // Stampa 30

        // --- 6. TRUCCO DELL'ULTIMO ELEMENTO ---
        // Poiché si parte da 0, l'ultimo indice è sempre (lunghezza - 1).
        // Qui numeri.length è 3, quindi 3-1 = 2. Stampa voti[2] che è 30.
        System.out.println("Elemento dinamico: " + voti[numeri.length - 1]);

        // --- 7. SCORRERE L'ARRAY (Loop Classico) ---
        // Utile se ti serve sapere l'indice (la posizione 'i') mentre lavori.
        System.out.println("--- Ciclo For Classico ---");
        for(int i = 0; i < voti.length; i++){
            System.out.println("Indice " + i + ": " + voti[i]);
        }

        // --- 8. SCORRERE L'ARRAY (For-Each) ---
        // Molto più rapido e pulito se non ti serve l'indice ma solo il valore.
        System.out.println("--- Ciclo For-Each ---");
        for (int voto : voti) {
            System.out.println("Voto: " + voto);
        }
    }
}