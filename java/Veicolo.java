public abstract class Veicolo {
    // I metodi astratti non hanno un corpo { } ma finiscono con ;
    // Obbligano le sottoclassi a implementarli.
    abstract void muovi();
    abstract void frena();

    // Una classe astratta può avere anche metodi normali
    void accendiMotore() {
        System.out.println("Il motore è stato acceso.");
    }
}