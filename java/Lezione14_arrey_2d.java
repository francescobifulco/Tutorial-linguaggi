public class Lezione14_arrey_2d {
    public static void main(String[] args) {
        
        // --- 1. DICHIARAZIONE E ALLOCAZIONE ---
        // String[righe][colonne]. Qui creiamo una griglia 3x3.
        String[][] classi = new String[3][3];

        // --- 2. ASSEGNAZIONE VALORI ---
        // Riga 0 (la prima)
        classi[0][0] = "Luca";
        classi[0][1] = "Anna";
        classi[0][2] = "Antonio";

        // Riga 1 (la seconda)
        classi[1][0] = "Marco";
        classi[1][1] = "Edoardo";
        classi[1][2] = "Leonardo";

        // Riga 2 (la terza)
        classi[2][0] = "Arianna";
        classi[2][1] = "Paolo";
        classi[2][2] = "Andrea";

        // --- 3. ACCESSO E MODIFICA ---
        System.out.println(classi[2][1]); // Stampa "Paolo"
        classi[2][1] = "Orazio";         // Modifica il valore in quella coordinata
        System.out.println(classi[2][1]); // Ora stampa "Orazio"

        // --- 4. STAMPA CON FOR ANNIDATO ---
        // Il primo ciclo scorre le righe, il secondo le colonne di quella riga.
        for(int riga = 0; riga < classi.length; riga++){
            System.out.println(); // Va a capo all'inizio di ogni nuova riga
            for(int colonna = 0; colonna < classi[riga].length; colonna++){
                System.out.print(classi[riga][colonna] + " ");
            }
        }

        System.out.println();
        
        // --- 5. INIZIALIZZAZIONE RAPIDA (Literal) ---
        // Molto più leggibile se i dati sono già noti.
        String[][] classe2 = {
            {"Luca", "Anna", "Antonio"},    // riga 0
            {"Marco", "Edoardo", "Leonardo"}, // riga 1
            {"Arianna", "Paolo", "Andrea"}   // riga 2
        };

        // --- 6. STAMPA CON FOR-EACH ANNIDATO ---
        // Estremamente pulito: "Per ogni array 'classe' dentro 'classe2'..."
        // "...e per ogni 'studente' dentro quella 'classe'..."
        for (String[] classe : classe2) {
            System.out.println();
            for (String studente : classe) {
                System.out.print(studente + " ");
            }
        }
    }
}