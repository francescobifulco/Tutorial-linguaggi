import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Lezione38_date_ore {
    public static void main(String[] args) {
        
        // 1. Orario corrente
        LocalTime orario = LocalTime.now();
        System.out.println("--- ORARIO ATTUALE ---");
        System.out.println("Formato default: " + orario);

        // 2. Data e Orario completi
        LocalDateTime dataOra = LocalDateTime.now();
        System.out.println("\n--- DATA E ORA COMPLETI ---");
        System.out.println("Formato default: " + dataOra);

        // 3. Formattazione personalizzata
        // Creiamo due stili diversi
        DateTimeFormatter formatoData = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        DateTimeFormatter formatoOrario = DateTimeFormatter.ofPattern("HH:mm:ss");

        System.out.println("\n--- FORMATTAZIONE PERSONALIZZATA ---");
        // Formattiamo la data (usando l'oggetto LocalDateTime)
        System.out.println("Data leggibile:    " + dataOra.format(formatoData));
        
        // Formattiamo l'orario (usando l'oggetto LocalTime)
        System.out.println("Orario leggibile:  " + orario.format(formatoOrario));
    }
}