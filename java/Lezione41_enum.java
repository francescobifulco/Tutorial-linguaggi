public class Lezione41_enum {
    public static void main(String[] args) {
        
        // 1. Uso dello Switch con Enum
        GiorniSettimana oggi = GiorniSettimana.Martedi;
        System.out.println("--- TEST GIORNO ---");
        
        switch (oggi) {
            case Lunedi:    System.out.println("Inizio settimana: Lunedì"); break;
            case Martedi:   System.out.println("Siamo a Martedì"); break;
            case Mercoledi: System.out.println("Metà settimana: Mercoledì"); break;
            case Sabato:
            case Domenica:  System.out.println("È il weekend!"); break;
            default:        System.out.println("Un giorno lavorativo qualsiasi"); break;
        }

        // 2. Iterazione su tutti i valori (.values())
        System.out.println("\n--- TUTTI I GIORNI DELLA SETTIMANA ---");
        for(GiorniSettimana g : GiorniSettimana.values()){
            // .ordinal() indica la posizione (0, 1, 2...)
            System.out.println(g.ordinal() + ": " + g);
        }

        // 3. Trasformazione Stringa -> Enum (.valueOf)
        System.out.println("\n--- CONVERSIONE STRINGA ---");
        try {
            GiorniSettimana dom = GiorniSettimana.valueOf("Domenica");
            System.out.println("Convertito con successo: " + dom);
        } catch (IllegalArgumentException e) {
            System.out.println("Errore: Giorno non valido!");
        }

        // 4. Enum con attributi (Seme)
        System.out.println("\n--- INFO SEMI CARTE ---");
        Seme s1 = Seme.Cuori;
        Seme s2 = Seme.Picche;

        stampaSeme(s1);
        stampaSeme(s2);
    }

    // Metodo helper per pulire il main
    public static void stampaSeme(Seme s) {
        System.out.println("Seme: " + s + 
                           " | Rosso: " + (s.isCarteRossa() ? "Sì" : "No") + 
                           " | Carte nel mazzo: " + s.getNumeroCarteNelMazzo());
    }
}