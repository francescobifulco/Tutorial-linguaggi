import java.util.ArrayList;

public class Lezione48_generiche {
    public static void main(String[] args) {
        
        // 1. Esempio classico: ArrayList è una classe generica
        ArrayList<String> frutta = new ArrayList<>();
        frutta.add("Mela");
        frutta.add("Arancia");

        // 2. Uso della classe generica Box con UN tipo <T>
        System.out.println("--- TEST BOX GENERICA ---");
        Box<String> boxFrutta = new Box<>();
        boxFrutta.setItem("Banana");
        System.out.println("Contenuto Box: " + boxFrutta.getItem());

        // 3. Uso della classe generica Product con DUE tipi <T, U>
        System.out.println("\n--- TEST PRODOTTI GENERICI ---");
        
        // Esempio con String e Double (prezzo decimale)
        Product<String, Double> mela = new Product<>("Mela Fuji", 0.50);
        System.out.println("Prodotto: " + mela.getItem() + " | Prezzo: €" + mela.getPrice());

        // Esempio con String e Integer (prezzo intero)
        Product<String, Integer> ticket = new Product<>("Ticket Cinema", 15);
        System.out.println("Prodotto: " + ticket.getItem() + " | Prezzo: €" + ticket.getPrice());
    }
}