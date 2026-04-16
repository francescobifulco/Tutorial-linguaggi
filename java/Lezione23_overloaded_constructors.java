public class Lezione23_overloaded_constructors {
    public static void main(String[] args) {
        System.out.println("--- BENVENUTO IN PIZZERIA JAVA ---\n");

        // Creazione di pizze con diverse combinazioni
        Pizza pizza1 = new Pizza("Integrale", "Pomodoro", "Mozzarella", "Prezzemolo");
        Pizza pizza2 = new Pizza("Normale", "Pomodoro", "Mozzarella");
        Pizza pizza3 = new Pizza("Senza Glutine", "Pomodoro");

        // Usiamo il metodo mostraPizza() invece di stampare l'oggetto direttamente
        pizza1.mostraPizza();
        pizza2.mostraPizza();
        pizza3.mostraPizza();

        System.out.println("\n--- ORDINE COMPLETATO ---");
    }
}