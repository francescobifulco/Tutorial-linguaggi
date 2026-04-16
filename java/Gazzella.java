// La gazzella ha un solo ruolo: scappare
public class Gazzella implements Preda {
    @Override
    public void scappa() {
        System.out.println("[Gazzella]: Ha avvistato un pericolo e sta scappando velocemente!");
    }
}