import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class UtenteDAOImpl implements InterfaceUtenteDAO {

    @Override
    public void salva(Utente u) {
        String sql = "INSERT INTO utenti (nome, cognome, eta) VALUES (?, ?, ?)";
        try (Connection conn = Database.getConnection(); // Usiamo il tuo pooling!
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, u.getNome());
            pstmt.setString(2, u.getCognome());
            pstmt.setString(3, String.valueOf(u.getEta()));
            pstmt.executeUpdate();
            System.out.println("Utente salvato via JDBC!");

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public Utente trovaPerId(int id) {
        // ... codice per cercare un utente ...
        return null;
    }

    @Override
    public List<Utente> trovaTutti() {
        // ... codice per listare tutti ...
        return new ArrayList<>();
    }

    @Override
    public void cancella(int id) {
        // ... codice per cancellare ...
    }
}