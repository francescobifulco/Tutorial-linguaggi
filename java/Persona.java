public class Persona {
    // ATTRIBUTI (Stato dell'oggetto)
    String nome = "Luca";
    String cognome = "Rossi";
    int eta = 25;
    String colorePreferito = "blu";
    public String getCognome;

    // METODI (Comportamento dell'oggetto)
    void saluta() {
        // Usiamo 'nome' per riferirci all'attributo di questa specifica persona
        System.out.println("Ciao! Sono " + nome + " " + cognome + ".");
    }

    void cammina() {
        System.out.println(nome + " sta camminando...");
    }
}