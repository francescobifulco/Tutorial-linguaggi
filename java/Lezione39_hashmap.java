import java.util.HashMap;

public class Lezione39_hashmap {
    public static void main(String[] args) {
        // Dichiarazione: <TipoChiave, TipoValore>
        HashMap<String, String> capitali = new HashMap<>();

        // 1. Inserimento dati (put)
        capitali.put("Italia", "Roma");
        capitali.put("Inghilterra", "Londra");
        capitali.put("Germania", "Berlino");
        capitali.put("Francia", "Parigi");

        System.out.println("--- MAPPA COMPLETA ---");
        System.out.println(capitali);

        // 2. Recupero di un valore specifico (get)
        String capitaleItalia = capitali.get("Italia");
        System.out.println("\nLa capitale dell'Italia è: " + capitaleItalia);

        // 3. Rimozione e Verifica
        System.out.println("\n[Sistema]: Rimozione della Francia...");
        capitali.remove("Francia");
        
        System.out.println("La mappa contiene ancora la Francia? " + capitali.containsKey("Francia"));
        System.out.println("Numero di elementi attuale: " + capitali.size());

        // 4. Ciclo per scorrere la mappa (Iterazione)
        System.out.println("\n--- ELENCO DETTAGLIATO ---");
        for (String i : capitali.keySet()) {
            // keySet() ci dà tutte le chiavi, poi usiamo get(i) per il valore
            System.out.println("Stato: " + i + " \t| Capitale: " + capitali.get(i));
        }

        // 5. Pulizia totale
        capitali.clear();
        System.out.println("\n[Sistema]: Mappa svuotata. Size: " + capitali.size());
    }
}