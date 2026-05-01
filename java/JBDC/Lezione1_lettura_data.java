import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Lezione1_lettura_data {
    public static void main(String[] args) {
        // Dati di connessione
        String url = "jdbc:mysql://localhost:3306/scuola_db";
        String user = "root";
        String password = "root";

        // Usiamo il try-with-resources per chiudere automaticamente la connessione
        try (Connection conn = DriverManager.getConnection(url, user, password);
            Statement stmt = conn.createStatement()) {
            
            System.out.println("Connessione riuscita!");

            String sql = "SELECT id, nome FROM studenti";
            ResultSet rs = stmt.executeQuery(sql);

            // Iteriamo sui risultati
            while (rs.next()) {
                int id = rs.getInt("id");
                String nome = rs.getString("nome");
                System.out.println("ID: " + id + ", Nome: " + nome);
            }

        } catch (Exception e) {
            System.out.println("Errore specifico: " + e.getMessage());
        }
    }
}