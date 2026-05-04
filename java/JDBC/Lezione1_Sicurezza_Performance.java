import java.sql.*;

public class Lezione1_Sicurezza_Performance {
    public static void main(String[] args) {
        // Parametri di connessione
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        // ESEMPIO: Ricerca utente per ID
        // Query con segnaposto '?' per la massima sicurezza
        String sql = "SELECT id, nome, cognome, eta FROM utenti WHERE id = ?"; // Il '?' è un segnaposto

        System.out.println("--- RICERCA UTENTE SICURA ---");

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
                PreparedStatement pstmt = conn.prepareStatement(sql)) {

            // Definiamo l'ID da cercare
            int idRicercato = 100;
            pstmt.setInt(1, idRicercato); // Sostituisce il primo '?' con idRicercato

            try (ResultSet rs = pstmt.executeQuery()) {
                System.out.println("Risultati della ricerca:");
                System.out.println("------------------------------------------------------------");

                if (rs.next()) {
                    // Recupero dati
                    int id = rs.getInt("id");
                    String nome = rs.getString("nome");
                    String cognome = rs.getString("cognome");
                    int eta = rs.getInt("eta");

                    // Stampa formattata
                    System.out.printf("STATO: Utente trovato! %n");
                    System.out.printf("ID:      [%d] %n", id);
                    System.out.printf("NOME:    %s %n", nome);
                    System.out.printf("COGNOME: %s %n", cognome);
                    System.out.printf("ETÀ:     %d anni %n", eta);
                } else {
                    // Caso in cui l'ID non esiste nel DB
                    System.out.printf("STATO: Nessun utente trovato con ID: %d %n", idRicercato);
                }
                System.out.println("------------------------------------------------------------");
            }

        } catch (SQLException e) {
            System.err.println("Errore durante l'esecuzione della query sicura:");
            System.err.println("Messaggio: " + e.getMessage());
        }
    }
}