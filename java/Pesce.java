// Il pesce è l'esempio perfetto: può essere sia preda che predatore (Eredità Multipla di comportamenti)
public class Pesce implements Preda, Predatore {
    @Override
    public void caccia() {
        System.out.println("[Pesce]: Il pesce grosso insegue il branco di pesci piccoli.");
    }

    @Override
    public void scappa() {
        System.out.println("[Pesce]: Il pesce piccolo schizza via per non essere mangiato.");
    }
}