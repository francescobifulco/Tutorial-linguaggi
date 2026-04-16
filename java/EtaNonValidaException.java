// Estendiamo Exception per obbligare chi usa il metodo a gestire l'errore
public class EtaNonValidaException extends Exception {
    
    private int etaErrata;

    public EtaNonValidaException(String messaggio, int eta) {
        super(messaggio); // Passiamo il messaggio alla classe madre Exception
        this.etaErrata = eta;
    }

    public int getEtaErrata() {
        return etaErrata;
    }
}