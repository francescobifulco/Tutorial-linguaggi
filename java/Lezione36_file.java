import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Lezione36_file {
    public static void main(String[] args) {

        // 1. GESTIONE INFORMAZIONI FILE
        File file = new File("prova.txt");

        System.out.println("--- INFO FILE ---");
        if (file.exists()) {
            System.out.println("Stato: Il file esiste.");
            System.out.println("Path Relativo: " + file.getPath());
            System.out.println("Path Assoluto: " + file.getAbsolutePath());
            System.out.println("È un file valido? " + file.isFile());
        } else {
            System.out.println("Stato: Il file 'prova.txt' non esiste ancora.");
        }

        // 2. SCRITTURA (FileWriter)
        System.out.println("\n--- SCRITTURA IN CORSO ---");
        try (FileWriter writer = new FileWriter("prova.txt")) { // Try-with-resources chiude in automatico
            writer.write("Ciao sono Franci\n");
            writer.write("Sto imparando a gestire i file in Java.\n");
            writer.append("Questo file è stato creato automaticamente.");
            System.out.println("Salvataggio completato con successo.");
        } catch (IOException e) {
            System.out.println("Errore durante la scrittura: " + e.getMessage());
        }

        // 3. LETTURA (FileReader)
        System.out.println("\n--- CONTENUTO DEL FILE ---");
        try (FileReader reader = new FileReader("prova.txt")) {
            int data = reader.read();
            while (data != -1) {
                // Castiamo l'intero 'data' in (char) per vedere la lettera, non il codice ASCII
                System.out.print((char) data); 
                data = reader.read();
            }
            System.out.println("\n\n--- FINE LETTURA ---");
        } catch (IOException e) {
            System.out.println("Errore durante la lettura: " + e.getMessage());
        }
    }
}