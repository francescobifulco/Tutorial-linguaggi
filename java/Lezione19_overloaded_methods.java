public class Lezione19_overloaded_methods {
    public static void main(String[] args) {
        
        // Java capisce quale metodo usare in base agli argomenti che passi:
        
        // 1. Qui passi due interi -> Chiama il metodo addizione(int, int)
        int doppioInt = addizione(2, 3);
        System.out.println("Somma di 2 interi: " + doppioInt);

        // 2. Qui passi tre interi -> Chiama il metodo addizione(int, int, int)
        int triploInt = addizione(5, 7, 3);
        System.out.println("Somma di 3 interi: " + triploInt);

        // 3. Qui passi due double -> Chiama il metodo addizione(double, double)
        double doppioDouble = addizione(2.6, 7.9);
        System.out.println("Somma di 2 double: " + doppioDouble);
    }

    // --- OVERLOADED METHODS ---

    // Versione A: Accetta due parametri di tipo int
    static int addizione(int a, int b) {
        return a + b;
    }

    // Versione B: Accetta tre parametri di tipo int (cambia il NUMERO di parametri)
    static int addizione(int a, int b, int c) {
        return a + b + c;
    }

    // Versione C: Accetta due parametri di tipo double (cambia il TIPO di parametri)
    static double addizione(double a, double b) {
        return a + b;
    }
}