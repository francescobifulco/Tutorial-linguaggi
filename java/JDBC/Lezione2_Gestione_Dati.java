import java.sql.*;

public class Lezione2_Gestione_Dati {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS)) {

            // DISABILTIARE L'AUTO-COMMIT per gestire la transazione manualmente
            conn.setAutoCommit(false);

            String sqlInsert = "INSERT INTO utenti (nome, cognome, eta) VALUES (?, ?, ?)";

            try (PreparedStatement pstmt = conn.prepareStatement(sqlInsert)) {

                System.out.println("--- INIZIO TRANSAZIONE ---");
                System.out.println("--- ESECUZIONE OPERAZIONI ---");

                // Operazione 1
                pstmt.setString(1, "Mario");
                pstmt.setString(2, "Esposito");
                pstmt.setInt(3, 40);
                pstmt.executeUpdate();
                System.out.println("[LOG]: Dati di Mario pronti per l'invio...");

                // Operazione 2 (Esempio: aggiungiamo un altro utente)
                pstmt.setString(1, "Lucia");
                pstmt.setString(2, "Verdi");
                pstmt.setInt(3, 22);
                pstmt.executeUpdate();
                System.out.println("[LOG]: Dati di Lucia pronti per l'invio...");

                // SE TUTTO È ANDATO BENE, CONFERMIAMO
                conn.commit();
                System.out.println("\n>>> SUCCESSO: Dati salvati definitivamente nel DB!");

            } catch (SQLException e) {
                // SE C'È UN ERRORE, ANNULLIAMO TUTTO
                System.err.println("\n>>> ERRORE: Qualcosa è andato storto. Eseguo il ROLLBACK.");
                conn.rollback();
                e.printStackTrace();
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}