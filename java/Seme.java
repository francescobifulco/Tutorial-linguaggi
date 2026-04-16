public enum Seme {
    // Definizione delle costanti con i parametri del costruttore
    Cuori(true, 10), 
    Spade(false, 12), 
    Quadri(true, 23), 
    Picche(false, 28);

    private final boolean rossa;
    private final int numeroCarteNelMazzo;

    // Il costruttore delle Enum è sempre privato di default
    private Seme(boolean rossa, int numeroCarteNelMazzo){
        this.rossa = rossa;
        this.numeroCarteNelMazzo = numeroCarteNelMazzo;
    }

    public boolean isCarteRossa() { return rossa; }
    public int getNumeroCarteNelMazzo() { return numeroCarteNelMazzo; }
}