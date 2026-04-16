public class Insegnante extends Informazione {
    String materia;

    Insegnante(String nome, String cognome, int eta, String materia) {
        super(nome, cognome, eta);
        this.materia = materia;
    }

    void insegna() {
        System.out.println("Il Prof. " + cognome + " sta spiegando " + materia + ".");
    }

    @Override
    void saluta() {
        System.out.println("Saluto Insegnante: Buongiorno ragazzi, aprite il libro a pagina 10.");
    }
}