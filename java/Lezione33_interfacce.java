public class Lezione33_interfacce {
    public static void main(String[] args) {
        System.out.println("--- SIMULAZIONE ECOISTEMA ---\n");

        Leone simba = new Leone();
        Gazzella bumbi = new Gazzella();
        Pesce nemo = new Pesce();

        // Test dei comportamenti
        bumbi.scappa();
        simba.caccia();

        System.out.println("\n--- CASO SPECIALE: IL PESCE ---");
        nemo.caccia(); // Comportamento da Predatore
        nemo.scappa(); // Comportamento da Preda

        System.out.println("\n--- FINE SIMULAZIONE ---");
    }
}