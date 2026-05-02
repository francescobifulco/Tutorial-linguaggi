import java.sql.Connection;
//Jimport java.sql.*;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Lezione1_lettura_data {
    public static void main(String[] args) {
        // Dati di connessione
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "";
        final String QUERY = "SELECT id, nome, cognome, eta FROM utenti";

        // Usiamo il try-with-resources per chiudere automaticamente la connessione
        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
                Statement stmt = conn.createStatement();
                ResultSet rs = stmt.executeQuery(QUERY)) {

            System.out.println("Connessione riuscita!");

            // Iteriamo sui risultati
            while (rs.next()) {
                System.out.print("ID: " + rs.getInt("id"));
                System.out.print(", Età: " + rs.getInt("eta"));
                System.out.print(", Nome: " + rs.getString("nome"));
                System.out.println(", Cognome: " + rs.getString("cognome"));
            }

        } catch (Exception e) {
            System.out.println("Errore specifico: " + e.getMessage());
            e.printStackTrace(); // Fondamentale per capire il problema
        }
    }
}
