import java.sql.*;

public static void main(String[] args) {
    final String DB_URL = "jdbc:mysql://localhost/prova_db";
    final String USER = "root";
    final String PASS = "root";
    final String QUERY = "SELECT id, eta, nome, cognome FROM utenti";
    // Open a connection
    try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(QUERY);) {
        // Extract data from result set
        while (rs.next()) {
            // Retrieve by column name
            System.out.print("ID: " + rs.getInt("id"));
            System.out.print(", Age: " + rs.getInt("eta"));
            System.out.print(", First: " + rs.getString("nome"));
            System.out.println(", Last: " + rs.getString("cognome"));
        }
    } catch (SQLException e) {
        e.printStackTrace();
    }
}