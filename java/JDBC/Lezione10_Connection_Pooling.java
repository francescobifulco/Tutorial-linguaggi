import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;
import java.sql.*;

public class Lezione10_Connection_Pooling {

    // Creiamo il "parcheggio" come variabile statica (una sola per tutta l'app)
    private static HikariDataSource dataSource;

    static {
        HikariConfig config = new HikariConfig();
        config.setJdbcUrl("jdbc:mysql://localhost:3306/prova_db");
        config.setUsername("root");
        config.setPassword("root");

        // --- CONFIGURAZIONE DEL POOL ---
        config.setMaximumPoolSize(10); // Massimo 10 connessioni contemporanee
        config.setMinimumIdle(5);      // Almeno 5 connessioni sempre pronte
        config.setIdleTimeout(300000); // 5 minuti di inattività prima di chiudere un'auto in eccesso
        config.setConnectionTimeout(20000); // Se dopo 20 secondi non c'è un'auto libera, dai errore

        dataSource = new HikariDataSource(config);
    }

    public static void main(String[] args) {
        String sql = "SELECT COUNT(*) FROM utenti";

        // NOTA: Qui non usiamo DriverManager!
        // Chiediamo una connessione al pool.
        try (Connection conn = dataSource.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql);
             ResultSet rs = pstmt.executeQuery()) {

            if (rs.next()) {
                System.out.println("Totale utenti (via Pooling): " + rs.getInt(1));
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        // Alla fine dell'applicazione, chiudiamo il pool
        dataSource.close();
    }
}