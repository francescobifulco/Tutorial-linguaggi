public class Lezione37_casting_valori {
    public static void main(String[] args) {
        
        // 1. Widening Casting (Implicito)
        // Passiamo da float (32-bit) a double (64-bit). Non serve specificare nulla.
        double x = 9.5f; 
        System.out.println("Casting Implicito (float -> double):");
        System.out.println("Valore di x: " + x); // Stampa 9.5

        System.out.println("\n------------------------------------\n");

        // 2. Narrowing Casting (Esplicito)
        // Forziamo il float a diventare un intero. 
        // ATTENZIONE: Java elimina la parte decimale, non arrotonda!
        double y = (int) 9.5f; 
        System.out.println("Casting Esplicito (float -> int -> double):");
        System.out.println("Valore di y: " + y); // Stampa 9.0 (lo 0.5 è andato perduto)

        // Esempio extra: Casting di char
        char lettera = 'A';
        int codiceAscii = (int) lettera;
        System.out.println("\nCasting di un carattere:");
        System.out.println("La lettera '" + lettera + "' in codice ASCII è: " + codiceAscii);
    }
}