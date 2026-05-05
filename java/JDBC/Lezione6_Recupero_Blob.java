import java.sql.*;
import java.io.InputStream;      // Per leggere il flusso dal DB
import java.io.FileOutputStream; // Per scrivere il file sul tuo PC

public class Lezione6_Recupero_Blob {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        // DATI DI TEST
        int idUtente = 1; 
        // Specifica il nome del file finale (es. .jpg o .pdf a seconda di cosa hai salvato)
        String percorsoDestinazione = "C:/immagini/foto_recuperata.jpg"; 

        String sql = "SELECT foto FROM utenti WHERE id = ?";

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setInt(1, idUtente);

            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    // 1. Otteniamo il flusso binario dalla colonna "foto"
                    try (InputStream is = rs.getBinaryStream("foto");
                         // 2. Prepariamo il file fisico dove scrivere i byte
                         FileOutputStream fos = new FileOutputStream(percorsoDestinazione)) {

                        if (is != null) {
                            System.out.println("--- DOWNLOAD IN CORSO ---");
                            
                            byte[] buffer = new byte[1024]; // "Secchio" per trasportare i byte
                            int byteLetti;
                            
                            // Leggiamo dal database finché ci sono dati e scriviamo nel file
                            while ((byteLetti = is.read(buffer)) != -1) {
                                fos.write(buffer, 0, byteLetti);
                            }
                            
                            System.out.println(">>> SUCCESSO: File scaricato correttamente in: " + percorsoDestinazione);
                        } else {
                            System.out.println(">>> ATTENZIONE: L'utente con ID " + idUtente + " non ha alcuna foto nel database.");
                        }
                    }
                } else {
                    System.out.println(">>> ERRORE: Utente con ID " + idUtente + " non trovato.");
                }
            }
        } catch (Exception e) {
            System.err.println(">>> ERRORE DURANTE IL RECUPERO:");
            e.printStackTrace();
        }
    }
}