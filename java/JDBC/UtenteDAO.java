import java.sql.*;

public class UtenteDAO{
    private String url = "jdbc:mysql://localhost:3306/prova_db";
    private String user = "root";
    private String pass = "root";

    public void salvaUtente(Utente u) throws SQLException {
        String sql = "INSERT INTO utenti (nome, cognome, eta) VALUES (?, ?, ?)";

        try (Connection conn = DriverManager.getConnection(url, user, pass);
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, u.getNome());
            pstmt.setString(2, u.getCognome());
            pstmt.setInt(3, u.getEta());
            pstmt.executeUpdate();
            System.out.println("Utente salvato con successo tramite DAO!");
        }
    }
}