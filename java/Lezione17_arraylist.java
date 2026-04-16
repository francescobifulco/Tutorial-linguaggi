import java.util.ArrayList; // Obbligatorio importare la classe per usarla

public class Lezione17_arraylist {
    public static void main(String[] args) {
        // --- 1. CREAZIONE E AGGIUNTA ---
        // Usiamo le parentesi angolari <> per definire il tipo (String).
        ArrayList<String> persona = new ArrayList<>();

        persona.add("Luca");  // Indice 0
        persona.add("Marco"); // Indice 1
        persona.add("Anna");  // Indice 2

        // .size() sostituisce .length degli array classici.
        // .get(i) si usa invece di [i] per leggere il valore.
        for(int i = 0; i < persona.size(); i++){
            System.out.println(persona.get(i));
        }

        // --- 2. MODIFICA (.set) ---
        // Cambia l'elemento all'indice 2 ("Anna") con "Paola".
        persona.set(2, "Paola");

        // --- 3. RIMOZIONE (.remove) ---
        // Elimina l'elemento all'indice 0 ("Luca"). 
        // Automaticamente "Marco" diventa l'indice 0 e "Paola" l'indice 1.
        persona.remove(0);

        // --- 4. SVUOTAMENTO (.clear) ---
        // Rimuove tutti gli elementi in un colpo solo.
        persona.clear();

        // --- 5. ARRAYLIST DI INTERI ---
        // Come visto nella lezione precedente, usiamo la Wrapper Class <Integer>
        ArrayList<Integer> numeri = new ArrayList<>();
        numeri.add(10);
        numeri.add(100);
        numeri.add(1000);

        // --- 6. ARRAYLIST MULTIDIMENSIONALE (2D) ---
        // Una lista che contiene altre liste. Dinamismo puro!
        ArrayList<ArrayList<String>> classi = new ArrayList<>();

        ArrayList<String> classe1 = new ArrayList<>();
        classe1.add("Luca");
        classe1.add("Marco");

        ArrayList<String> classe2 = new ArrayList<>();
        classe2.add("Anna");
        classe2.add("Orazio");

        classi.add(classe1);
        classi.add(classe2);

        // Per stampare usiamo get(i) per la riga e get(j) per la colonna.
        for(int i = 0; i < classi.size(); i++){
            System.out.println();
            for(int j = 0; j < classi.get(i).size(); j++){
                System.out.print(classi.get(i).get(j) + " ");
            }
        }
    }
}