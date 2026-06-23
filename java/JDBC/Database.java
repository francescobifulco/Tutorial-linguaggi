import com.zaxxer.hikari.HikariConfig;
import com.zaxxer.hikari.HikariDataSource;
import java.sql.Connection;
import java.sql.SQLException;

public class Database {
    private static HikariDataSource dataSource;

    static {
        try {
            HikariConfig config = new HikariConfig();
            config.setJdbcUrl("jdbc:mysql://localhost:3306/prova_db");
            config.setUsername("root");
            config.setPassword("root");

            // Ottimizzazioni per il pool
            config.setMaximumPoolSize(10);
            config.setMinimumIdle(2);

            dataSource = new HikariDataSource(config);
        } catch (Exception e) {
            System.err.println("Errore inizializzazione Pool: " + e.getMessage());
        }
    }

    // Questo è il metodo che cercava il tuo DAO
    public static Connection getConnection() throws SQLException {
        return dataSource.getConnection();
    }
}