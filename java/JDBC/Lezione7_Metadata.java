import java.sql.*;

public class Lezione7_Metadata {
    public static void main(String[] args) {
        final String DB_URL = "jdbc:mysql://localhost:3306/prova_db";
        final String USER = "root";
        final String PASS = "root";

        String sql = "SELECT * FROM utenti"; // Puoi cambiare tabella e funzionerà comunque!

        try (Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
             PreparedStatement pstmt = conn.prepareStatement(sql);
             ResultSet rs = pstmt.executeQuery()) {

            // --- ESTREMIAMO I METADATI ---
            ResultSetMetaData rsmd = rs.getMetaData();

            // 1. Quante colonne ci sono?
            int numeroColonne = rsmd.getColumnCount();
            System.out.println("La tabella ha " + numeroColonne + " colonne.\n");

            // 2. Stampiamo i nomi delle colonne (Intestazione)
            for (int i = 1; i <= numeroColonne; i++) {
                // getColumnName(i) ci dà il nome, getColumnTypeName(i) il tipo (INT, VARCHAR...)
                System.out.print(rsmd.getColumnName(i).toUpperCase() +
                        " (" + rsmd.getColumnTypeName(i) + ")\t");
            }
            System.out.println("\n------------------------------------------------------------");

            // 3. Stampiamo i dati riga per riga
            while (rs.next()) {
                for (int i = 1; i <= numeroColonne; i++) {
                    // Usiamo rs.getObject(i) perché non sappiamo se è una Stringa o un Int
                    System.out.print(rs.getObject(i) + "\t\t");
                }
                System.out.println();
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}