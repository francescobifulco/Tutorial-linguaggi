import java.util.List;

public interface InterfaceUtenteDAO {
    void salva(Utente u);
    Utente trovaPerId(int id);
    List<Utente> trovaTutti();
    void cancella(int id);
}