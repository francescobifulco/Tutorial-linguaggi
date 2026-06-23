import java.sql.*;
import java.io.FileInputStream; // Necessario per leggere il file dal disco
import java.io.File;

public class Lezione6_Gestione_Blob {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        // DATI DI TEST
        int idUtente = 1; // L'ID dell'utente a cui vuoi aggiungere la foto
        String percorsoFile = "C:\\Users\\Roman\\OneDrive\\Immagini\\Gemini_Generated_Image_llymtzllymtzllym.pmg";

        String sql = "UPDATE utenti SET foto = ? WHERE id = ?";

        // Verifichiamo prima se il file esiste per evitare errori banali
        File file = new File(percorsoFile);
        if (!file.exists()) {
            System.err.println("ERRORE: Il file non esiste al percorso specificato: " + percorsoFile);
            return;
        }

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             // FileInputStream apre il file per "leggerlo" come flusso di dati binari
             FileInputStream fis = new FileInputStream(file);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            System.out.println("--- CARICAMENTO FILE IN CORSO ---");

            // 1. Inseriamo il flusso di dati (il file) nel primo parametro ?
            pstmt.setBinaryStream(1, fis, (int) file.length());

            // 2. Inseriamo l'ID nel secondo parametro ?
            pstmt.setInt(2, idUtente);

            int righeColpite = pstmt.executeUpdate();

            if (righeColpite > 0) {
                System.out.println(">>> SUCCESSO: Immagine salvata per l'utente " + idUtente);
            } else {
                System.out.println(">>> ATTENZIONE: Nessun utente trovato con ID " + idUtente);
            }

        } catch (Exception e) {
            System.err.println(">>> ERRORE DURANTE IL CARICAMENTO:");
            e.printStackTrace();
        }
    }
}
