import java.util.ArrayList;

public class Lezione48_generiche {
    public static void main(String[] args) {
        ArrayList<String> frutta = new ArrayList<>();
        
        frutta.add("mela");
        frutta.add("arancia");
        frutta.add("banana");

        Box<String> box1 = new Box<>();
        box1.setItem("banana");
        System.out.println(box1.getItem());

        Product<String, Double> proce = new Product<String,Double>("mela", 0.50);
        System.out.println(proce.getPrice());

        Product<String, Integer> proce2 = new Product<String,Integer>("ticket", 15);
        System.out.println(proce2.getPrice());
    }
}
