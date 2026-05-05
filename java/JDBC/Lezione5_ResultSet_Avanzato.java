import java.sql.*;

public class Lezione5_ResultSet_Avanzato {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        String sql = "SELECT * FROM utenti";

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             // Configuriamo lo statement per permettere lo scorrimento (Scrollable)
             PreparedStatement pstmt = conn.prepareStatement(sql,
                     ResultSet.TYPE_SCROLL_INSENSITIVE,
                     ResultSet.CONCUR_READ_ONLY)) {

            try (ResultSet rs = pstmt.executeQuery()) {

                System.out.println("--- NAVIGAZIONE AVANZATA ---");

                // 1. Vai all'ultima riga
                if (rs.last()) {
                    System.out.println("ULTIMO UTENTE: " + rs.getString("nome"));
                }

                // 2. Torna alla riga precedente
                if (rs.previous()) {
                    System.out.println("PENULTIMO UTENTE: " + rs.getString("nome"));
                }

                // 3. Vai a una riga specifica (es. la seconda riga del DB)
                if (rs.absolute(2)) {
                    System.out.println("SECONDA RIGA: " + rs.getString("nome"));
                }

                // 4. Torna all'inizio (prima della prima riga)
                rs.beforeFirst();
                System.out.println("\n--- ELENCO COMPLETO RE-INIZIATO ---");
                while (rs.next()) {
                    System.out.println("Utente: " + rs.getString("nome"));
                }
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}