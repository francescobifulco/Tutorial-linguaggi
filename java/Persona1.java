public class Persona1 {
    // 1. DATI PRIVATI: Nessuno dall'esterno può scrivere persona.nome = "..."
    private String nome;
    private String cognome;

    Persona1(String nome, String cognome){
        this.nome = nome;
        this.cognome = cognome;
    }

    // 2. GETTER: Metodo pubblico per "esporre" il valore in lettura
    public String getNome() {
        return nome;
    }

    // 3. SETTER: Metodo pubblico per permettere la modifica controllata
    public void setNome(String nome) {
        // Qui potresti aggiungere controlli (es. if(nome != null))
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    // IL METODO COPY: Prende i valori da un'altra persona e li scrive su di sé.
    // Questo crea una copia REALE dei dati, non del puntatore.
    public void copy(Persona1 personaDaCopiare) {
        this.setNome(personaDaCopiare.getNome());
        this.setCognome(personaDaCopiare.getCognome());
    }

    void saluta() {
        System.out.println("Ciao, sono una persona generica.");
    }

}