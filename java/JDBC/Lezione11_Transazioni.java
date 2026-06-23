import java.sql.*;

public class Lezione11_Transazioni {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        Connection conn = null;

        try {
            conn = DriverManager.getConnection(DB_URL, USER, PASS);

            // 1. DISABILITIAMO L'AUTO-COMMIT
            // Da questo momento, nulla viene salvato finché non lo diciamo noi
            conn.setAutoCommit(false);

            try (PreparedStatement prelievo = conn.prepareStatement(
                    "UPDATE utenti SET saldo = saldo - ? WHERE id = ?");
                 PreparedStatement deposito = conn.prepareStatement(
                         "UPDATE utenti SET saldo = saldo + ? WHERE id = ?")) {

                // OPERAZIONE A: Prelievo da ID 1
                prelievo.setDouble(1, 100.0);
                prelievo.setInt(2, 1);
                prelievo.executeUpdate();

                // Simulo un errore improvviso (es. un'eccezione o un crash)
                // if (true) throw new SQLException("Errore di rete improvviso!");

                // OPERAZIONE B: Deposito su ID 2
                deposito.setDouble(1, 100.0);
                deposito.setInt(2, 2);
                deposito.executeUpdate();

                // 2. SE TUTTO È ANDATO BENE, CONFERMIAMO
                conn.commit();
                System.out.println("Transazione completata con successo!");

            } catch (SQLException e) {
                // 3. SE C'È UN ERRORE, ANNULLIAMO TUTTO
                if (conn != null) {
                    System.err.println("Errore riscontrato. Eseguo il ROLLBACK...");
                    conn.rollback();
                }
                e.printStackTrace();
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            // Ripristiniamo lo stato e chiudiamo la connessione
            try {
                if (conn != null) conn.close();
            } catch (SQLException ex) {
                ex.printStackTrace();
            }
        }
    }
}