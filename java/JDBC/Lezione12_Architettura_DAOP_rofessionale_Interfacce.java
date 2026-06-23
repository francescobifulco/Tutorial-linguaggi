public class Lezione12_Architettura_DAOP_rofessionale_Interfacce {
    public static void main(String[] args) {
        // Polimorfismo: Tipo Interfaccia = Nuova Implementazione
        UtenteDAOImpl dao = new UtenteDAOImpl();

        Utente nuovo = new Utente(3, "Marco", "Neri", 17);

        // Il resto dell'app non sa che sotto c'è JDBC!
        dao.salva(nuovo);
    }
}