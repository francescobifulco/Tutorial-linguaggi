import java.sql.*;

public class Lezione9_Callable {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        // La sintassi standard JDBC per chiamare una procedura è { call nome_procedura(?, ?) }
        String sql = "{ call conta_utenti_per_eta(?, ?) }";

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             CallableStatement cstmt = conn.prepareCall(sql)) {

            // 1. Impostiamo il parametro di INPUT (come un PreparedStatement)
            cstmt.setInt(1, 25); // Vogliamo contare i maggiorenni

            // 2. Registriamo il parametro di OUTPUT
            // Dobbiamo dire a JDBC che tipo di dato ci aspettiamo dal secondo punto interrogativo
            cstmt.registerOutParameter(2, Types.INTEGER);

            // 3. Eseguiamo la chiamata
            System.out.println("Esecuzione della procedura sul Database...");
            cstmt.execute();

            // 4. Recuperiamo il valore calcolato dal DB
            int totale = cstmt.getInt(2);
            System.out.println("Risultato dal DB: Gli utenti con più di 25 anni sono " + totale);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}