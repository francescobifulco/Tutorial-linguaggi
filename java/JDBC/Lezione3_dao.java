import java.sql.SQLException;

public class Lezione3_dao {
    public static void main(String[] args) {
        // 1. Creiamo l'oggetto con i dati
        Utente nuovoUtente = new Utente(0, "Marco", "Neri", 28);

        // 2. Usiamo il DAO per salvarlo
        UtenteDAO dao = new UtenteDAO();

        try {
            dao.salvaUtente(nuovoUtente);
            System.out.println("Operazione completata nel Main.");
        } catch (SQLException e) {
            System.err.println("Errore nel salvataggio: " + e.getMessage());
        }
    }
}
