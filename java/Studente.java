public class Studente extends Informazione {
    String materiaPreferita;

    Studente(String nome, String cognome, int eta, String materiaPreferita) {
        super(nome, cognome, eta); // Chiama il costruttore di Informazione
        this.materiaPreferita = materiaPreferita;
    }

    void studia() {
        System.out.println(nome + " sta studiando " + materiaPreferita + "...");
    }

    @Override
    void saluta() {
        System.out.println("Saluto Studente: Buongiorno Prof!");
    }
}