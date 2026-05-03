import java.sql.*;

public class Lezione1_lettura_dati {
    public static void main(String[] args) {
        // Parametri di configurazione
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";
        final String QUERY = "SELECT id, eta, nome, cognome FROM utenti";

        System.out.println("--- CONNESSIONE AL DATABASE IN CORSO ---");

        // Try-with-resources: gestisce automaticamente la chiusura delle 3 risorse
        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(QUERY);) {

            System.out.println("Connessione riuscita! Recupero dati...\n");
            System.out.println("------------------------------------------------------------");
            // Intestazione tabella formattata
            System.out.printf("%-5s | %-5s | %-15s | %-15s %n", "ID", "ETA", "NOME", "COGNOME");
            System.out.println("------------------------------------------------------------");

            // Iterazione dei risultati
            while (rs.next()) {
                // Recupero dei dati tramite nome colonna
                int id = rs.getInt("id");
                int eta = rs.getInt("eta");
                String nome = rs.getString("nome");
                String cognome = rs.getString("cognome");

                // Stampa formattata: %-15s significa "stringa di 15 caratteri allineata a sinistra"
                System.out.printf("%-5d | %-5d | %-15s | %-15s %n", id, eta, nome, cognome);
            }
            System.out.println("------------------------------------------------------------");

        } catch (SQLException e) {
            System.err.println("ERRORE CRITICO: Impossibile comunicare con il database.");
            // Mostriamo dettagli specifici dell'errore SQL
            System.err.println("Messaggio: " + e.getMessage());
            System.err.println("Codice Stato: " + e.getSQLState());
        }
    }
}