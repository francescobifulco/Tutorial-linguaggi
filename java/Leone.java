// Il leone ha un solo ruolo (nel tuo esempio): cacciare
public class Leone implements Predatore {
    @Override
    public void caccia() {
        System.out.println("[Leone]: Si mimetizza nell'erba e parte all'attacco!");
    }
}