import java.sql.*;

public class Lezione4_Batch_Processing {
    public static void  main(String[] args){
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        String sql = "INSERT INTO utenti (nome, cognome, eta) VALUES (?, ?, ?)";

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS)) {

            // 1. Disabilitiamo l'auto-commit per gestire tutto come un'unica transazione
            conn.setAutoCommit(false);

            try (PreparedStatement pstmt = conn.prepareStatement(sql)) {

                // Simuliamo l'aggiunta di 3 utenti nel "pacchetto" (Batch)

                // Utente 1
                pstmt.setString(1, "Mario");
                pstmt.setString(2, "Rossi");
                pstmt.setInt(3, 30);
                pstmt.addBatch(); // Lo aggiunge al pacchetto, non lo invia ancora

                // Utente 2
                pstmt.setString(1, "Anna");
                pstmt.setString(2, "Bianchi");
                pstmt.setInt(3, 25);
                pstmt.addBatch(); // Lo aggiunge al pacchetto

                // Utente 3
                pstmt.setString(1, "Luca");
                pstmt.setString(2, "Verdi");
                pstmt.setInt(3, 40);
                pstmt.addBatch(); // Lo aggiunge al pacchetto

                // 2. INVIA TUTTO IL PACCHETTO IN UN COLPO SOLO
                int[] risultati = pstmt.executeBatch();

                // 3. CONFERMA la transazione
                conn.commit();

                System.out.println("Operazione Batch completata! Righe inserite: " + risultati.length);

            } catch (SQLException e) {
                System.err.println("Errore durante il Batch. Eseguo il rollback.");
                conn.rollback();
                e.printStackTrace();
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
