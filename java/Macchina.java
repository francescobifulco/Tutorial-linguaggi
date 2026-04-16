public class Macchina extends Veicolo {

    @Override
    void muovi() {
        System.out.println("[Sistema Macchina]: Sto accelerando su quattro ruote...");
    }

    @Override
    void frena() {
        System.out.println("[Sistema Macchina]: Ho azionato i freni a disco. Mi sto fermando.");
    }
}