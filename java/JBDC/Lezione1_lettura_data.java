import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class Lezione1_lettura_data {
    public static void main(String[] args) {
        // Dati di connessione
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";
        final String QUERY = "SELECT id, first, last, age FROM Employees";

        // Usiamo il try-with-resources per chiudere automaticamente la connessione
        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
            Statement stmt = conn.createStatement(); 
            ResultSet rs = stmt.executeQuery(QUERY)){
            
            System.out.println("Connessione riuscita!");

            // Iteriamo sui risultati
            while (rs.next()) {
                System.out.print("ID: " + rs.getInt("id"));
                System.out.print(", Age: " + rs.getInt("age"));
                System.out.print(", First: " + rs.getString("first"));
                System.out.println(", Last: " + rs.getString("last"));
            }

        } catch (Exception e) {
            System.out.println("Errore specifico: " + e.getMessage());
            e.printStackTrace(); // Fondamentale per capire il problema
        }
    }
}