public class Informazione {
    // VARIABILI DI ISTANZA (Scope Globale della classe)
    // Queste variabili "vivono" finché l'oggetto esiste.
    String nome, cognome, colorePreferito;
    int eta;

    // VARIABILE STATICA: Appartiene alla classe, non alla singola persona.
    // Viene condivisa da tutti gli oggetti Informazione.
    static int numeroPersona = 0;

    Informazione(String nome, String cognome, int eta, String colorePreferito) {
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.colorePreferito = colorePreferito;
        
        // Ogni volta che creiamo una persona, incrementiamo il contatore globale
        numeroPersona++; 
        System.out.println("[Sistema] Istanza creata per: " + this.nome);
    }

    Informazione(String nome, String cognome, int eta){
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;

        numeroPersona++; 
        System.out.println("[Sistema] Istanza creata per: " + this.nome);
    }

    // METODO STATICO: Può essere chiamato senza creare un oggetto (usando Informazione.metodo)
    static void mostraNumPersone() {
        System.out.println("Totale persone create nel sistema: " + numeroPersona);
    }

    void saluta() {
        // Accediamo alla variabile globale dell'oggetto tramite 'this'
        System.out.println("Saluto: Ciao, io sono " + this.nome);
    }

   // METODO CHE RICEVE UN ALTRO OGGETTO
    // Qui 'personaDaSalutare' è un riferimento all'oggetto che passeremo nel main.
    void saluta(Informazione personaDaSalutare) {
        // 'this.nome' è chi esegue l'azione (il mittente)
        // 'personaDaSalutare.nome' è chi riceve l'azione (il destinatario)
        System.out.println("[" + this.nome + "]: Ehi " + personaDaSalutare.nome + "! Piacere di conoscerti, io sono " + this.nome + ".");
        
        // Possiamo anche accedere ad altri dati dell'oggetto ricevuto
        System.out.println("[" + this.nome + "]: Ho visto che il tuo colore preferito è il " + personaDaSalutare.colorePreferito + "!");
    }

    void addizione(int a, int b) {
        // SCOPE LOCALE: 'risultato' esiste solo all'interno di questo metodo.
        int risultato = a + b;
        System.out.println("Metodo addizione: Somma calcolata (" + risultato + ")");
        // Passiamo il valore locale a un altro metodo
        this.qwerty(risultato);
    }

    void qwerty(int prova) {
        // Riceve il valore calcolato da un altro metodo e lo elabora
        System.out.println("Metodo qwerty: Ricevuto valore " + prova + " e stampato a video.");
    }
    
    // OVERRIDE DEL METODO toString
    // Questo metodo DEVE essere public e restituire una Stringa.
    @Override // Questa annotazione dice a Java: "Sto sovrascrivendo il metodo standard"
    public String toString() {
        return "--- SCHEDA PERSONA ---\n" +
               "Nome:    " + nome + "\n" +
               "Cognome: " + cognome + "\n" +
               "Età:     " + eta + " anni\n" +
               "Colore:  " + colorePreferito + "\n" +
               "----------------------";
    }
}